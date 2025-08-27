# spine-glfw Runtime Documentation

> **Licensing**
>
> Please see the [Spine Runtimes License](/spine-runtimes-license) before integrating the Spine Runtimes into your applications.

# Getting Started
spine-glfw is a C++ based runtime to load, manipulate and render Spine skeletons with [GLFW](https://www.glfw.org/) and OpenGL.

spine-glfw requires GLFW 3.0+ and OpenGL 3.3+ and supports all Spine features including [two-color tinting](https://en.esotericsoftware.com/spine-slots#Tint-black).

## Installation

The spine-glfw runtime is available as a C++ API based on the generic [spine-cpp](/spine-cpp) runtime and also supports [spine-c](/spine-c) API. To integrate spine-glfw into your project:

1. Create a new GLFW project. See the [GLFW documentation](https://www.glfw.org/docs/latest/) or have a look at the example in [spine-runtimes repository](/git/spine-runtimes/tree/spine-glfw), which uses [CMake](https://cmake.org) as the build system.
2. Download the Spine Runtimes source using git (`git clone https://github.com/esotericsoftware/spine-runtimes`).
3. Add the sources from `spine-cpp/spine-cpp/src/spine` and the files `spine-glfw/src/spine-glfw.cpp` and `spine-glfw/src/spine-glfw.h` to your project.
4. Add the folders `spine-cpp/spine-cpp/include` and `spine-glfw/src` to your header search path.
5. Link against GLFW, OpenGL, and optionally glbinding for modern OpenGL function loading.

In your C++ code, include the following header file to get access to the `spine-glfw` API:

```cpp
#include <spine-glfw.h>
```

> *Note:* spine-glfw requires OpenGL 3.3 Core Profile or higher. The runtime uses modern OpenGL features including vertex array objects, vertex buffer objects, and GLSL shaders.

## Samples
The spine-glfw example works on Windows, Linux and Mac OS X. For a [spine-cpp](/spine-cpp) based example, see [example/main.cpp](/git/spine-runtimes/tree/spine-glfw/example/main.cpp), for a spine-c example see [example/main-c.cpp](/git/spine-runtimes/tree/spine-glfw/example/main-c.cpp).

### Windows

1. Install [Visual Studio Community](https://visualstudio.microsoft.com/downloads/). Make sure you install support for C++ and CMake.
2. Download the Spine Runtimes repository using git (`git clone https://github.com/esotericsoftware/spine-runtimes`) or download it as a zip.
3. Open Visual Studio Community, then open `spine-glfw/` via the **Open a local folder** button in the Visual Studio Community launcher.
4. Wait for CMake to finish, then select either `spine-glfw-example.exe` or `spine-glfw-example-c.exe` as the start-up project and start debugging.

### Linux

1. Install dependencies:
   ```bash
   sudo apt-get install cmake ninja-build libgl1-mesa-dev libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev  # Ubuntu/Debian
   # or equivalent for your distribution
   ```
2. Clone the repository: `git clone https://github.com/esotericsoftware/spine-runtimes`
3. Build and run:
   ```bash
   cd spine-runtimes/spine-glfw
   ./build.sh
   ./build/debug/spine-glfw-example-c    # Run C example
   ./build/debug/spine-glfw-example      # Run C++ example
   ```

### macOS

1. Install [Xcode](https://developer.apple.com/xcode/)
2. Install [Homebrew](http://brew.sh/)
3. Install dependencies:
   ```bash
   brew install cmake ninja
   ```
4. Clone the repository: `git clone https://github.com/esotericsoftware/spine-runtimes`
5. Build and run:
   ```bash
   cd spine-runtimes/spine-glfw
   ./build.sh
   ./build/debug/spine-glfw-example-c    # Run C example
   ./build/debug/spine-glfw-example      # Run C++ example
   ```

## Using spine-glfw
The spine-glfw runtime supports playback and manipulation of animations created with Spine using [GLFW](https://www.glfw.org/) and OpenGL. The spine-glfw runtime is implemented in C++ and is based on the generic [spine-cpp](/spine-cpp) runtime. It adds loading and rendering implementations based on OpenGL APIs.

Please consult the [Spine Runtimes Guide](/spine-runtimes) for a detailed overview of the Spine Runtime architecture, and the [spine-cpp](/spine-cpp) documentation for information on the core APIs used to playback and manipulate animations created with Spine with C++.

### Exporting for GLFW
![](/img/spine-runtimes-guide/spine-ue4/export.png)
Please follow the instructions in the Spine User Guide on how to

1. [Export skeleton & animation data](/spine-export)
2. [Export texture atlases containing the images of your skeleton](/spine-texture-packer)

An export of the skeleton data and texture atlas of your skeleton will yield the following files:

![](/img/spine-runtimes-guide/spine-ue4/exported-files.png)

1. `skeleton-name.json` or `skeleton-name.skel`, containing your skeleton and animation data.
2. `skeleton-name.atlas`, containing information about the texture atlas.
3. One or more `.png` files, each representing on page of your texture atlas containing the packed images your skeleton uses.

> **Note:** The spine-glfw runtime does not support the screen blend mode available in the Spine editor.

### Loading Spine skeletons
The spine-glfw runtime uses OpenGL for rendering skeletons. Before a skeleton can be loaded from exported files, a GLFW window and OpenGL context must be created:

```cpp
// Initialize GLFW
if (!glfwInit()) {
    // Handle error
    return -1;
}

// Set OpenGL version to 3.3 Core Profile
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// Create window
GLFWwindow* window = glfwCreateWindow(800, 600, "Spine GLFW", NULL, NULL);
glfwMakeContextCurrent(window);

// Initialize OpenGL function loading (e.g., with glbinding)
glbinding::initialize(glfwGetProcAddress);
```

Next, the texture atlas can be loaded using the `GlTextureLoader`:

```cpp
// C++ API
spine::GlTextureLoader textureLoader;
spine::Atlas *atlas = new spine::Atlas("data/spineboy-pma.atlas", &textureLoader);
```

With the atlas loaded, the `.json` or `.skel` file can be loaded:

```cpp
// C++ API
spine::SkeletonBinary binary(atlas);
spine::SkeletonData *skeletonData = binary.readSkeletonDataFile("data/spineboy-pro.skel");
```

For JSON format:

```cpp
// C++ API
spine::SkeletonJson json(atlas);
spine::SkeletonData *skeletonData = json.readSkeletonDataFile("data/spineboy-pro.json");
```

The `spine::Atlas` and `spine::SkeletonData` instances can then be used to create `spine::Skeleton` instances for rendering.

> *Note:* the loaded skeleton data and atlas can and should be shared across `spine::Skeleton` instances to reduce memory consumption and enable batched rendering of skeletons that share the same atlas data.

### Renderer
The main addition of spine-glfw on top of [spine-cpp](/spine-cpp) is the renderer system. The renderer handles the OpenGL rendering pipeline including shaders, meshes, and textures. Unlike other runtimes that provide a drawable class, spine-glfw uses a more modular approach with separate renderer and mesh components.

You can create a renderer like this:

```cpp
// Create the renderer and set viewport size
renderer_t *renderer = renderer_create();
renderer_set_viewport_size(renderer, windowWidth, windowHeight);
```

The renderer automatically creates and manages OpenGL shaders optimized for Spine skeleton rendering.

### Creating and animating skeletons
With the skeleton data loaded, you can create a skeleton instance:

```cpp
// Set coordinate system (spine-glfw uses y-down by default)
spine::Bone::setYDown(true);

// Create a skeleton from the data
spine::Skeleton skeleton(skeletonData);
skeleton.setPosition(400, 500);
skeleton.setScaleX(0.5f);
skeleton.setScaleY(0.5f);
```

For animation, create an animation state:

```cpp
// Create animation state
spine::AnimationStateData animationStateData(skeletonData);
animationStateData.setDefaultMix(0.2f);
spine::AnimationState animationState(&animationStateData);

// Set animations
animationState.setAnimation(0, "portal", true);
animationState.addAnimation(0, "run", true, 0);
```

Please refer to the [spine-cpp](/spine-cpp) documentation for more information on the APIs to manipulate skeletons and animation states.

### Updating and rendering
In your main loop, update the animation state and skeleton, then render:

```cpp
double lastTime = glfwGetTime();
while (!glfwWindowShouldClose(window)) {
    double currTime = glfwGetTime();
    float delta = currTime - lastTime;
    lastTime = currTime;

    // Update animation state
    animationState.update(delta);
    animationState.apply(skeleton);

    // Update skeleton
    skeleton.update(delta);
    skeleton.updateWorldTransform(spine::Physics_Update);

    // Clear screen
    gl::glClear(gl::GL_COLOR_BUFFER_BIT);

    // Render skeleton
    renderer_draw(renderer, &skeleton, true); // true for premultiplied alpha

    // Present
    glfwSwapBuffers(window);
    glfwPollEvents();
}
```

### Using spine-c
spine-glfw also supports the [spine-c](/spine-cpp-lite) API for applications that need a C interface or are written in programming languages that cannot interface with C++ code directly. The key differences when using spine-c with spine-glfw are:

#### Key Differences from spine-cpp:

1. **C API instead of C++**: All functions use C-style naming (e.g., `spine_skeleton_set_position` vs `skeleton.setPosition`)
2. **Manual file loading**: You must manually load atlas and skeleton files into memory
3. **Callback-based texture loading**: Textures are loaded via user-provided callback functions
4. **Skeleton drawable wrapper**: Uses `spine_skeleton_drawable` which wraps skeleton and animation state
5. **Different renderer function**: Uses `renderer_draw_c()` instead of `renderer_draw()`

#### Texture Loading with Callbacks
First, you need to provide texture loading callbacks that bridge spine-cpp-lite to spine-glfw's texture system:

```cpp
// Callback function to load textures
void *load_texture(const char *path) {
    return (void *)(uintptr_t)texture_load(path);
}

// Callback function to unload textures
void unload_texture(void *texture) {
    texture_dispose((texture_t)(uintptr_t)texture);
}
```

#### Loading Atlas and Skeleton Data
Unlike spine-cpp which can load files directly, spine-c requires manual file reading:

```cpp
// Read atlas file into memory
int atlas_length = 0;
uint8_t *atlas_bytes = read_file("data/spineboy-pma.atlas", &atlas_length);
spine_atlas atlas = spine_atlas_load_callback(
    (utf8*)atlas_bytes, "data/", load_texture, unload_texture);

// Read skeleton file into memory
int skeleton_length = 0;
uint8_t *skeleton_bytes = read_file("data/spineboy-pro.skel", &skeleton_length);
spine_skeleton_data_result result = spine_skeleton_data_load_binary(atlas, skeleton_bytes, skeleton_length);
spine_skeleton_data skeleton_data = spine_skeleton_data_result_get_data(result);
```

#### Creating and Manipulating Skeletons
spine-c uses a drawable wrapper and C-style function calls:

```cpp
// Create skeleton drawable (combines skeleton + animation state)
spine_skeleton_drawable drawable = spine_skeleton_drawable_create(skeleton_data);
spine_skeleton skeleton = spine_skeleton_drawable_get_skeleton(drawable);

// Set skeleton properties using C functions
spine_skeleton_set_position(skeleton, width / 2, height - 100);
spine_skeleton_set_scale(skeleton, 0.3f, 0.3f);

// Get animation state from drawable
spine_animation_state animation_state = spine_skeleton_drawable_get_animation_state(drawable);
spine_animation_state_data animation_state_data = spine_animation_state_get_data(animation_state);
spine_animation_state_data_set_default_mix(animation_state_data, 0.2f);

// Set animations using C functions
spine_animation_state_set_animation_1(animation_state, 0, "portal", true);
spine_animation_state_add_animation_1(animation_state, 0, "run", true, 0);
```

#### Updating and Rendering
The update loop uses C-style function calls and a different renderer function:

```cpp
// Update animation state and skeleton
spine_skeleton_drawable_update(drawable, deltaTimeInSeconds)

// Render using the C-specific function
renderer_draw_c(renderer, skeleton, true);
```

The `renderer_draw_c()` function is specifically designed to work with spine-c's `spine_skeleton` opaque type, while `renderer_draw()` works with spine-cpp's `spine::Skeleton` class.

### Cleanup

#### Cleanup for spine-cpp
When using the spine-cpp API, use C++ delete operators:

```cpp
// Dispose renderer
renderer_dispose(renderer);

// Dispose skeleton data and atlas (C++ API)
delete skeletonData;
delete atlas;

// Cleanup GLFW
glfwTerminate();
```

#### Cleanup for spine-c
When using the spine-c API, use the C-style dispose functions:

```cpp
// Dispose renderer
renderer_dispose(renderer);

// Dispose skeleton data and atlas (C API)
spine_skeleton_drawable_dispose(drawable);
spine_skeleton_data_dispose(skeleton_data);
spine_atlas_dispose(atlas);

// Free manually allocated file data
free(atlas_bytes);
free(skeleton_bytes);

// Cleanup GLFW
glfwTerminate();
```

> *Note:* freeing skeleton data and atlas instances will automatically dispose of any associated OpenGL textures through the texture loader. With spine-c, you must also free any memory you allocated for file data using `malloc()`/`read_file()`.