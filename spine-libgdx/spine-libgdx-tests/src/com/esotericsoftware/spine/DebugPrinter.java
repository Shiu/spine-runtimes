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

package com.esotericsoftware.spine;

import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.backends.headless.HeadlessApplication;
import com.badlogic.gdx.backends.headless.HeadlessApplicationConfiguration;
import com.badlogic.gdx.files.FileHandle;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.graphics.g2d.TextureAtlas.AtlasRegion;
import com.badlogic.gdx.graphics.g2d.TextureAtlas.TextureAtlasData;

public class DebugPrinter implements ApplicationListener {
	private String skeletonPath;
	private String atlasPath;
	private String animationName;

	public DebugPrinter (String skeletonPath, String atlasPath, String animationName) {
		this.skeletonPath = skeletonPath;
		this.atlasPath = atlasPath;
		this.animationName = animationName;
	}

	static class Printer {
		private int indentLevel = 0;
		private static final String INDENT = "  ";

		private void print (String text) {
			for (int i = 0; i < indentLevel; i++) {
				System.out.print(INDENT);
			}
			System.out.println(text);
		}

		private void printValue (String name, Object value) {
			if (value == null) {
				print(name + ": null");
			} else if (value instanceof String) {
				print(name + ": \"" + value + "\"");
			} else if (value instanceof Float) {
				// Format floats to 6 decimal places to match other runtimes
				print(name + ": " + String.format("%.6f", value));
			} else {
				print(name + ": " + value);
			}
		}

		private void indent () {
			indentLevel++;
		}

		private void unindent () {
			indentLevel--;
		}

		public void printSkeletonData (SkeletonData data) {
			print("SkeletonData {");
			indent();

			// Basic properties
			printValue("name", data.getName());
			printValue("version", data.getVersion());
			printValue("hash", data.getHash());
			printValue("x", data.getX());
			printValue("y", data.getY());
			printValue("width", data.getWidth());
			printValue("height", data.getHeight());
			printValue("referenceScale", data.getReferenceScale());
			printValue("fps", data.getFps());
			printValue("imagesPath", data.getImagesPath());
			printValue("audioPath", data.getAudioPath());

			// TODO: Add bones, slots, skins, animations, etc. in future expansion

			unindent();
			print("}");
		}

		public void printSkeleton (Skeleton skeleton) {
			print("Skeleton {");
			indent();

			// Basic properties
			printValue("x", skeleton.getX());
			printValue("y", skeleton.getY());
			printValue("scaleX", skeleton.getScaleX());
			printValue("scaleY", skeleton.getScaleY());
			printValue("time", skeleton.getTime());

			// TODO: Add runtime state (bones, slots, etc.) in future expansion

			unindent();
			print("}");
		}
	}

	// Mock texture that doesn't require OpenGL - similar to AndroidTexture
	static class MockTexture extends Texture {
		private int width, height;

		public MockTexture (int width, int height) {
			super();
			this.width = width;
			this.height = height;
		}

		@Override
		public int getWidth () {
			return width;
		}

		@Override
		public int getHeight () {
			return height;
		}

		@Override
		public void bind () {
			// Do nothing
		}

		@Override
		public void bind (int unit) {
			// Do nothing
		}

		@Override
		public void dispose () {
			// Do nothing
		}
	}

	// Custom TextureAtlas that doesn't load actual textures - similar to AndroidTextureAtlas
	static class HeadlessTextureAtlas extends TextureAtlas {
		public HeadlessTextureAtlas (FileHandle packFile) {
			// Load atlas data without creating real textures
			TextureAtlasData data = new TextureAtlasData(packFile, packFile.parent(), false);

			// Create mock textures for each page
			for (TextureAtlasData.Page page : data.getPages()) {
				// Create a mock texture - we use 1024x1024 as a default size
				page.texture = new MockTexture(1024, 1024);
			}

			// Create regions from the data
			for (TextureAtlasData.Region region : data.getRegions()) {
				AtlasRegion atlasRegion = new AtlasRegion(region.page.texture, region.left, region.top,
					region.rotate ? region.height : region.width, region.rotate ? region.width : region.height);
				atlasRegion.index = region.index;
				atlasRegion.name = region.name;
				atlasRegion.offsetX = region.offsetX;
				atlasRegion.offsetY = region.offsetY;
				atlasRegion.originalHeight = region.originalHeight;
				atlasRegion.originalWidth = region.originalWidth;
				atlasRegion.rotate = region.rotate;
				atlasRegion.degrees = region.degrees;
				atlasRegion.names = region.names;
				atlasRegion.values = region.values;
				if (region.flip) atlasRegion.flip(false, true);
				getRegions().add(atlasRegion);
			}
		}
	}

	@Override
	public void create () {
		try {
			// Load atlas without textures
			FileHandle atlasFile = Gdx.files.absolute(atlasPath);
			TextureAtlas atlas = new HeadlessTextureAtlas(atlasFile);

			// Load skeleton data
			FileHandle skeletonFile = Gdx.files.absolute(skeletonPath);
			SkeletonData skeletonData;

			if (skeletonPath.endsWith(".json")) {
				SkeletonJson json = new SkeletonJson(atlas);
				skeletonData = json.readSkeletonData(skeletonFile);
			} else {
				SkeletonBinary binary = new SkeletonBinary(atlas);
				skeletonData = binary.readSkeletonData(skeletonFile);
			}

			// Print skeleton data
			System.out.println("=== SKELETON DATA ===");
			Printer printer = new Printer();
			printer.printSkeletonData(skeletonData);

			// Create skeleton instance
			Skeleton skeleton = new Skeleton(skeletonData);

			// Create animation state
			AnimationStateData stateData = new AnimationStateData(skeletonData);
			AnimationState state = new AnimationState(stateData);

			// Find and set animation
			Animation animation = skeletonData.findAnimation(animationName);
			if (animation == null) {
				System.err.println("Animation not found: " + animationName);
				System.exit(1);
			}

			state.setAnimation(0, animation, true);

			// Update and apply
			state.update(0.016f);
			state.apply(skeleton);
			skeleton.update(0.016f);
			skeleton.updateWorldTransform(Physics.update);

			// Print skeleton state
			System.out.println("\n=== SKELETON STATE ===");
			printer.printSkeleton(skeleton);

		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}

		// Exit after processing
		Gdx.app.exit();
	}

	@Override
	public void resize (int width, int height) {
	}

	@Override
	public void render () {
	}

	@Override
	public void pause () {
	}

	@Override
	public void resume () {
	}

	@Override
	public void dispose () {
	}

	public static void main (String[] args) {
		if (args.length < 3) {
			System.err.println("Usage: DebugPrinter <skeleton-path> <atlas-path> <animation-name>");
			System.exit(1);
		}

		HeadlessApplicationConfiguration config = new HeadlessApplicationConfiguration();
		config.updatesPerSecond = 60;
		new HeadlessApplication(new DebugPrinter(args[0], args[1], args[2]), config);
	}
}
