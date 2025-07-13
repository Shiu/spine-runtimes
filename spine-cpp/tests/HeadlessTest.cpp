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

#include <spine/spine.h>
#include "SkeletonSerializer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <locale.h>

using namespace spine;

// Provide the default extension implementation
namespace spine {
	SpineExtension *getDefaultExtension() {
		return new DefaultSpineExtension();
	}
}// namespace spine

// Mock texture that doesn't require OpenGL
class MockTexture {
public:
	int width = 1024;
	int height = 1024;
};

// Custom texture loader that doesn't load actual textures
class HeadlessTextureLoader : public TextureLoader {
public:
	virtual void load(AtlasPage &page, const String &path) override {
		// Don't load actual texture, just set dimensions
		page.texture = new MockTexture();
		page.width = 1024;
		page.height = 1024;
	}

	virtual void unload(void *texture) override {
		delete static_cast<MockTexture *>(texture);
	}
};


int main(int argc, char *argv[]) {
	// Set locale to ensure consistent number formatting
	setlocale(LC_ALL, "C");

	if (argc < 3) {
		fprintf(stderr, "Usage: DebugPrinter <skeleton-path> <atlas-path> [animation-name]\n");
		return 1;
	}

	Bone::setYDown(false);

	const char *skeletonPath = argv[1];
	const char *atlasPath = argv[2];
	const char *animationName = argc >= 4 ? argv[3] : nullptr;

	// Load atlas with headless texture loader
	HeadlessTextureLoader textureLoader;
	Atlas *atlas = new Atlas(atlasPath, &textureLoader);

	// Load skeleton data
	SkeletonData *skeletonData = nullptr;

	if (strstr(skeletonPath, ".json") != nullptr) {
		SkeletonJson json(atlas);
		skeletonData = json.readSkeletonDataFile(skeletonPath);
	} else {
		SkeletonBinary binary(atlas);
		skeletonData = binary.readSkeletonDataFile(skeletonPath);
	}

	if (!skeletonData) {
		fprintf(stderr, "Failed to load skeleton data\n");
		delete atlas;
		return 1;
	}

	// Create skeleton instance
	Skeleton skeleton(*skeletonData);

	// Create animation state
	AnimationStateData stateData(skeletonData);
	AnimationState state(&stateData);

	skeleton.setupPose();

	// Set animation or setup pose
	if (animationName != nullptr) {
		// Find and set animation
		Animation *animation = skeletonData->findAnimation(animationName);
		if (!animation) {
			fprintf(stderr, "Animation not found: %s\n", animationName);
			delete skeletonData;
			delete atlas;
			return 1;
		}
		state.setAnimation(0, animation, true);
		// Update and apply
		state.update(0.016f);
		state.apply(skeleton);
	}

	skeleton.updateWorldTransform(Physics_Update);

	// Use SkeletonSerializer for JSON output
	SkeletonSerializer serializer;
	
	// Print skeleton data
	printf("=== SKELETON DATA ===\n");
	printf("%s", serializer.serializeSkeletonData(skeletonData).buffer());

	// Print skeleton state
	printf("\n=== SKELETON STATE ===\n");
	printf("%s", serializer.serializeSkeleton(&skeleton).buffer());

	// Print animation state
	printf("\n=== ANIMATION STATE ===\n");
	printf("%s", serializer.serializeAnimationState(&state).buffer());

	// Cleanup
	delete skeletonData;
	delete atlas;

	return 0;
}