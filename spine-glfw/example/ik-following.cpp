/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include <glbinding/glbinding.h>
#include <glbinding/gl/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <spine-glfw.h>

using namespace spine;

int width = 800, height = 600;

// Mouse position for IK targeting
double mouseX = 400, mouseY = 300;
Skeleton* ikSkeleton = nullptr;

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	mouseX = xpos;
	mouseY = ypos;
}

GLFWwindow *init_glfw() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return nullptr;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow *window = glfwCreateWindow(width, height, "spine-glfw IK Following - Move mouse to aim", NULL, NULL);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);
	glbinding::initialize(glfwGetProcAddress);

	// Set mouse callback
	glfwSetCursorPosCallback(window, cursor_position_callback);

	return window;
}

int main() {
	// Initialize GLFW and glbinding
	GLFWwindow *window = init_glfw();
	if (!window) return -1;

	// We use a y-down coordinate system, see renderer_set_viewport_size()
	Bone::setYDown(true);

	// Load the atlas and the skeleton data
	GlTextureLoader textureLoader;
	Atlas *atlas = new Atlas("data/spineboy-pma.atlas", &textureLoader);
	SkeletonBinary binary(*atlas);
	SkeletonData *skeletonData = binary.readSkeletonDataFile("data/spineboy-pro.skel");

	// Create a skeleton from the data
	Skeleton skeleton(*skeletonData);
	skeleton.setScaleX(0.5);
	skeleton.setScaleY(0.5);
	skeleton.setupPose();

	// Position the skeleton on the left side like in the Flutter example
	skeleton.setPosition(200, height / 2 + 150);

	// Set the global skeleton pointer for IK
	ikSkeleton = &skeleton;

	// Create an AnimationState to drive animations on the skeleton
	AnimationStateData animationStateData(*skeletonData);
	AnimationState animationState(animationStateData);

	// Set the walk animation on track 0 and aim animation on track 1
	animationState.setAnimation(0, "walk", true);
	animationState.setAnimation(1, "aim", true);

	// Create the renderer and set the viewport size to match the window size
	renderer_t *renderer = renderer_create();
	renderer_set_viewport_size(renderer, width, height);

	// Rendering loop
	double lastTime = glfwGetTime();
	while (!glfwWindowShouldClose(window)) {
		// Calculate the delta time in seconds
		double currTime = glfwGetTime();
		float delta = currTime - lastTime;
		lastTime = currTime;

		// Update and apply the animation state to the skeleton
		animationState.update(delta);
		animationState.apply(skeleton);

		// Update the skeleton time (used for physics)
		skeleton.update(delta);

		// Update the crosshair bone position based on mouse position
		Bone* crosshairBone = skeleton.findBone("crosshair");
		if (crosshairBone != nullptr) {
			Bone* parent = crosshairBone->getParent();
			if (parent != nullptr) {
				// Convert mouse position to world coordinates
				float worldX = mouseX;
				float worldY = mouseY;

				// Convert world position to parent's local space
				float localX, localY;
				parent->getAppliedPose().worldToLocal(worldX, worldY, localX, localY);

				// Set the crosshair bone position in its applied pose
				crosshairBone->getAppliedPose().setX(localX);
				crosshairBone->getAppliedPose().setY(localY);
			}
		}

		// Calculate the new pose
		skeleton.updateWorldTransform(spine::Physics_Update);

		// Clear the screen
		gl::glClear(gl::GL_COLOR_BUFFER_BIT);

		// Render the skeleton in its current pose
		renderer_draw(renderer, &skeleton, true);

		// Present the rendering results and poll for events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Clear the IK skeleton pointer
	ikSkeleton = nullptr;

	// Dispose everything
	renderer_dispose(renderer);
	delete skeletonData;
	delete atlas;

	// Kill the window and GLFW
	glfwTerminate();
	return 0;
}