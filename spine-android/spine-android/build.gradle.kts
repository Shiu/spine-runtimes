import java.util.Properties

plugins {
    alias(libs.plugins.androidLibrary)
    `maven-publish`
    signing
}

// Function to read properties from spine-libgdx gradle.properties - single source of truth
fun readSpineLibgdxProperty(propertyName: String): String {
    val spineLibgdxPropsFile = File(rootProject.projectDir, "../spine-libgdx/gradle.properties")
    if (!spineLibgdxPropsFile.exists()) {
        throw GradleException("spine-libgdx gradle.properties file not found at ${spineLibgdxPropsFile.absolutePath}")
    }
    val lines = spineLibgdxPropsFile.readLines()
    for (line in lines) {
        if (line.startsWith("$propertyName=")) {
            return line.split("=")[1].trim()
        }
    }
    throw GradleException("Property '$propertyName' not found in spine-libgdx gradle.properties")
}

// JReleaser config for release builds to Central Portal
if (project.hasProperty("RELEASE")) {
    apply(plugin = "org.jreleaser")
}

android {
    namespace = "com.esotericsoftware.spine"
    compileSdk = 34

    defaultConfig {
        minSdk = 23

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        consumerProguardFiles("consumer-rules.pro")
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
}

dependencies {
    implementation(libs.androidx.appcompat)
    api("com.badlogicgames.gdx:gdx:${readSpineLibgdxProperty("libgdx_version")}")
    api("com.esotericsoftware.spine:spine-libgdx:${readSpineLibgdxProperty("version")}")

    testImplementation(libs.junit)
    androidTestImplementation(libs.androidx.junit)
    androidTestImplementation(libs.androidx.espresso.core)
}


tasks.register<Jar>("sourceJar") {
    archiveClassifier.set("sources")
    from(android.sourceSets["main"].java.srcDirs)
}

afterEvaluate {
    publishing {
        publications {
            create<MavenPublication>("release") {
                artifact(tasks.getByName("bundleReleaseAar"))
                artifact(tasks.getByName("sourceJar"))

                groupId = "com.esotericsoftware.spine"
                artifactId = "spine-android"
                version = project.version.toString()

                pom {
                    packaging = "aar"
                    name.set(project.findProperty("POM_NAME") as String? ?: "spine-android")
                    if (project.hasProperty("POM_DESCRIPTION")) {
                        description.set(project.findProperty("POM_DESCRIPTION") as String)
                    }
                    url.set(project.findProperty("POM_URL") as String? ?: "https://github.com/esotericsoftware/spine-runtimes")
                    licenses {
                        license {
                            name.set(project.findProperty("POM_LICENCE_NAME") as String? ?: "Spine Runtimes License")
                            url.set(project.findProperty("POM_LICENCE_URL") as String? ?: "http://esotericsoftware.com/spine-runtimes-license")
                            distribution.set(project.findProperty("POM_LICENCE_DIST") as String? ?: "repo")
                        }
                    }
                    developers {
                        developer {
                            name.set("Esoteric Software")
                            email.set("contact@esotericsoftware.com")
                        }
                    }
                    scm {
                        connection.set(project.findProperty("POM_SCM_CONNECTION") as String? ?: "scm:git:https://github.com/esotericsoftware/spine-runtimes.git")
                        developerConnection.set(project.findProperty("POM_SCM_DEV_CONNECTION") as String? ?: "scm:git:https://github.com/esotericsoftware/spine-runtimes.git")
                        url.set(project.findProperty("POM_SCM_URL") as String? ?: "https://github.com/esotericsoftware/spine-runtimes")
                    }

                    withXml {
                        val dependenciesNode = asNode().appendNode("dependencies")
                        configurations.api.get().dependencies.forEach { dependency ->
                            dependenciesNode.appendNode("dependency").apply {
                                appendNode("groupId", dependency.group)
                                appendNode("artifactId", dependency.name)
                                appendNode("version", dependency.version)
                                appendNode("scope", "compile")
                            }
                        }
                        configurations.implementation.get().dependencies.forEach { dependency ->
                            dependenciesNode.appendNode("dependency").apply {
                                appendNode("groupId", dependency.group)
                                appendNode("artifactId", dependency.name)
                                appendNode("version", dependency.version)
                                appendNode("scope", "runtime")
                            }
                        }
                    }

                }
            }
        }

        repositories {
            maven {
                name = "SonaType"
                url = uri(if (project.version.toString().endsWith("-SNAPSHOT")) {
                    if (project.hasProperty("SNAPSHOT_REPOSITORY_URL")) {
                        project.property("SNAPSHOT_REPOSITORY_URL") as String
                    } else {
                        "https://central.sonatype.com/repository/maven-snapshots/"
                    }
                } else {
                    // If release build, dump artifacts to local build/staging-deploy folder for consumption by jreleaser
                    layout.buildDirectory.dir("staging-deploy")
                })

                if (project.version.toString().endsWith("-SNAPSHOT")) {
                    val username = if (project.hasProperty("MAVEN_USERNAME")) {
                        project.property("MAVEN_USERNAME") as String
                    } else {
                        ""
                    }
                    val password = if (project.hasProperty("MAVEN_PASSWORD")) {
                        project.property("MAVEN_PASSWORD") as String
                    } else {
                        ""
                    }
                    if (username.isNotEmpty() || password.isNotEmpty()) {
                        credentials {
                            this.username = username
                            this.password = password
                        }
                    }
                }
            }
        }
    }

    signing {
        useGpgCmd()
        sign(publishing.publications["release"])
        sign(tasks.getByName("sourceJar"))
    }

    tasks.withType<Sign> {
        onlyIf { !project.version.toString().endsWith("-SNAPSHOT") }
    }
}

// For release builds, create a task that depends on publishing and finalizes with jreleaser
if (project.hasProperty("RELEASE")) {
    tasks.register("publishRelease") {
        dependsOn(tasks.withType<PublishToMavenRepository>())
        doLast {
            exec {
                commandLine("./gradlew", "jreleaserDeploy")
            }
        }
    }
}
