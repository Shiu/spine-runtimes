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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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

class Printer {
private:
	int indentLevel = 0;
	static constexpr const char *INDENT = "  ";

	void print(const char *format, ...) {
		for (int i = 0; i < indentLevel; i++) {
			printf("%s", INDENT);
		}
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
		printf("\n");
	}

	void indent() {
		indentLevel++;
	}

	void unindent() {
		indentLevel--;
	}

public:
	void printSkeletonData(SkeletonData *data) {
		print("SkeletonData {");
		indent();

		print("name: \"%s\"", data->getName().buffer());
		print("version: \"%s\"", data->getVersion().buffer());
		print("hash: \"%s\"", data->getHash().buffer());
		print("x: %.6f", data->getX());
		print("y: %.6f", data->getY());
		print("width: %.6f", data->getWidth());
		print("height: %.6f", data->getHeight());
		print("referenceScale: %.6f", data->getReferenceScale());
		print("fps: %.6f", data->getFps());
		print("imagesPath: \"%s\"", data->getImagesPath().buffer());
		print("audioPath: \"%s\"", data->getAudioPath().buffer());

		// TODO: Add bones, slots, skins, animations, etc. in future expansion

		unindent();
		print("}");
	}

	void printSkeleton(Skeleton *skeleton) {
		print("Skeleton {");
		indent();

		print("x: %.6f", skeleton->getX());
		print("y: %.6f", skeleton->getY());
		print("scaleX: %.6f", skeleton->getScaleX());
		print("scaleY: %.6f", skeleton->getScaleY());
		print("time: %.6f", skeleton->getTime());

		// TODO: Add runtime state (bones, slots, etc.) in future expansion

		unindent();
		print("}");
	}
};

int main(int argc, char *argv[]) {
	if (argc < 4) {
		fprintf(stderr, "Usage: DebugPrinter <skeleton-path> <atlas-path> <animation-name>\n");
		return 1;
	}

	const char *skeletonPath = argv[1];
	const char *atlasPath = argv[2];
	const char *animationName = argv[3];

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

	// Print skeleton data
	printf("=== SKELETON DATA ===\n");
	Printer printer;
	printer.printSkeletonData(skeletonData);

	// Create skeleton instance
	Skeleton skeleton(*skeletonData);

	// Create animation state
	AnimationStateData stateData(skeletonData);
	AnimationState state(&stateData);

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
	skeleton.update(0.016f);
	skeleton.updateWorldTransform(Physics_Update);

	// Print skeleton state
	printf("\n=== SKELETON STATE ===\n");
	printer.printSkeleton(&skeleton);

	// Cleanup
	delete skeletonData;
	delete atlas;

	return 0;
}