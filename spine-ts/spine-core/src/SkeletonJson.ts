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

import { Animation, Timeline, InheritTimeline, AttachmentTimeline, RGBATimeline, RGBTimeline, AlphaTimeline, RGBA2Timeline, RGB2Timeline, RotateTimeline, TranslateTimeline, TranslateXTimeline, TranslateYTimeline, ScaleTimeline, ScaleXTimeline, ScaleYTimeline, ShearTimeline, ShearXTimeline, ShearYTimeline, IkConstraintTimeline, TransformConstraintTimeline, PathConstraintPositionTimeline, PathConstraintSpacingTimeline, PathConstraintMixTimeline, DeformTimeline, DrawOrderTimeline, EventTimeline, CurveTimeline1, CurveTimeline, PhysicsConstraintResetTimeline, PhysicsConstraintInertiaTimeline, PhysicsConstraintStrengthTimeline, PhysicsConstraintDampingTimeline, PhysicsConstraintMassTimeline, PhysicsConstraintWindTimeline, PhysicsConstraintGravityTimeline, PhysicsConstraintMixTimeline, BoneTimeline2, SliderTimeline, SliderMixTimeline } from "./Animation.js";
import { VertexAttachment, Attachment } from "./attachments/Attachment.js";
import { AttachmentLoader } from "./attachments/AttachmentLoader.js";
import { MeshAttachment } from "./attachments/MeshAttachment.js";
import { BoneData, Inherit } from "./BoneData.js";
import { EventData } from "./EventData.js";
import { Event } from "./Event.js";
import { IkConstraintData } from "./IkConstraintData.js";
import { PathConstraintData, PositionMode, SpacingMode, RotateMode } from "./PathConstraintData.js";
import { SkeletonData } from "./SkeletonData.js";
import { Skin } from "./Skin.js";
import { SlotData, BlendMode } from "./SlotData.js";
import { FromProperty, FromRotate, FromScaleX, FromScaleY, FromShearY, FromX, FromY, ToProperty, ToRotate, ToScaleX, ToScaleY, ToShearY, ToX, ToY, TransformConstraintData } from "./TransformConstraintData.js";
import { Utils, Color, NumberArrayLike } from "./Utils.js";
import { Sequence, SequenceMode } from "./attachments/Sequence.js";
import { SequenceTimeline } from "./Animation.js";
import { HasTextureRegion } from "./attachments/HasTextureRegion.js";
import { PhysicsConstraintData } from "./PhysicsConstraintData.js";
import { SliderData } from "./SliderData.js";

/** Loads skeleton data in the Spine JSON format.
 *
 * See [Spine JSON format](http://esotericsoftware.com/spine-json-format) and
 * [JSON and binary data](http://esotericsoftware.com/spine-loading-skeleton-data#JSON-and-binary-data) in the Spine
 * Runtimes Guide. */
export class SkeletonJson {
	attachmentLoader: AttachmentLoader;

	/** Scales bone positions, image sizes, and translations as they are loaded. This allows different size images to be used at
	 * runtime than were used in Spine.
	 *
	 * See [Scaling](http://esotericsoftware.com/spine-loading-skeleton-data#Scaling) in the Spine Runtimes Guide. */
	scale = 1;
	private readonly linkedMeshes = new Array<LinkedMesh>();

	constructor (attachmentLoader: AttachmentLoader) {
		this.attachmentLoader = attachmentLoader;
	}

	readSkeletonData (json: string | any): SkeletonData {
		let scale = this.scale;
		let skeletonData = new SkeletonData();
		let root = typeof (json) === "string" ? JSON.parse(json) : json;

		// Skeleton
		let skeletonMap = root.skeleton;
		if (skeletonMap) {
			skeletonData.hash = skeletonMap.hash;
			skeletonData.version = skeletonMap.spine;
			skeletonData.x = skeletonMap.x;
			skeletonData.y = skeletonMap.y;
			skeletonData.width = skeletonMap.width;
			skeletonData.height = skeletonMap.height;
			skeletonData.referenceScale = getValue(skeletonMap, "referenceScale", 100) * scale;
			skeletonData.fps = skeletonMap.fps;
			skeletonData.imagesPath = skeletonMap.images ?? null;
			skeletonData.audioPath = skeletonMap.audio ?? null;
		}

		// Bones
		if (root.bones) {
			for (let i = 0; i < root.bones.length; i++) {
				let boneMap = root.bones[i];

				let parent: BoneData | null = null;
				let parentName: string = getValue(boneMap, "parent", null);
				if (parentName) parent = skeletonData.findBone(parentName);
				let data = new BoneData(skeletonData.bones.length, boneMap.name, parent);
				data.length = getValue(boneMap, "length", 0) * scale;
				const setup = data.setup;
				setup.x = getValue(boneMap, "x", 0) * scale;
				setup.y = getValue(boneMap, "y", 0) * scale;
				setup.rotation = getValue(boneMap, "rotation", 0);
				setup.scaleX = getValue(boneMap, "scaleX", 1);
				setup.scaleY = getValue(boneMap, "scaleY", 1);
				setup.shearX = getValue(boneMap, "shearX", 0);
				setup.shearY = getValue(boneMap, "shearY", 0);
				setup.inherit = Utils.enumValue(Inherit, getValue(boneMap, "inherit", "Normal"));
				data.skinRequired = getValue(boneMap, "skin", false);

				let color = getValue(boneMap, "color", null);
				if (color) data.color.setFromString(color);

				skeletonData.bones.push(data);
			}
		}

		// Slots.
		if (root.slots) {
			for (let i = 0; i < root.slots.length; i++) {
				let slotMap = root.slots[i];
				let slotName = slotMap.name;

				let boneData = skeletonData.findBone(slotMap.bone);
				if (!boneData) throw new Error(`Couldn't find bone ${slotMap.bone} for slot ${slotName}`);
				let data = new SlotData(skeletonData.slots.length, slotName, boneData);

				let color: string = getValue(slotMap, "color", null);
				if (color) data.setup.color.setFromString(color);

				let dark: string = getValue(slotMap, "dark", null);
				if (dark) data.setup.darkColor = Color.fromString(dark);

				data.attachmentName = getValue(slotMap, "attachment", null);
				data.blendMode = Utils.enumValue(BlendMode, getValue(slotMap, "blend", "normal"));
				data.visible = getValue(slotMap, "visible", true);
				skeletonData.slots.push(data);
			}
		}

		// Constraints.
		if (root.constraints) {
			for (const constraintMap of root.constraints) {
				const name = constraintMap.name;
				const skinRequired = getValue(constraintMap, "skin", false);
				switch (getValue(constraintMap, "type", false)) {
					case "ik": {
						const data = new IkConstraintData(name);
						data.skinRequired = skinRequired;

						for (let ii = 0; ii < constraintMap.bones.length; ii++) {
							let bone = skeletonData.findBone(constraintMap.bones[ii]);
							if (!bone) throw new Error(`Couldn't find bone ${constraintMap.bones[ii]} for IK constraint ${name}.`);
							data.bones.push(bone);
						}

						const targetName = constraintMap.target;
						const target = skeletonData.findBone(targetName);
						if (!target) throw new Error(`Couldn't find target bone ${targetName} for IK constraint ${name}.`);
						data.target = target;

						data.uniform = getValue(constraintMap, "uniform", false);
						const setup = data.setup;
						setup.mix = getValue(constraintMap, "mix", 1);
						setup.softness = getValue(constraintMap, "softness", 0) * scale;
						setup.bendDirection = getValue(constraintMap, "bendPositive", true) ? 1 : -1;
						setup.compress = getValue(constraintMap, "compress", false);
						setup.stretch = getValue(constraintMap, "stretch", false);

						skeletonData.constraints.push(data);
						break;
					}
					case "transform": {
						const data = new TransformConstraintData(name);
						data.skinRequired = skinRequired;

						for (let ii = 0; ii < constraintMap.bones.length; ii++) {
							let boneName = constraintMap.bones[ii];
							let bone = skeletonData.findBone(boneName);
							if (!bone) throw new Error(`Couldn't find bone ${boneName} for transform constraint ${constraintMap.name}.`);
							data.bones.push(bone);
						}

						const sourceName: string = constraintMap.source;
						const source = skeletonData.findBone(sourceName);
						if (!source) throw new Error(`Couldn't find source bone ${sourceName} for transform constraint ${constraintMap.name}.`);
						data.source = source;

						data.localSource = getValue(constraintMap, "localSource", false);
						data.localTarget = getValue(constraintMap, "localTarget", false);
						data.additive = getValue(constraintMap, "additive", false);
						data.clamp = getValue(constraintMap, "clamp", false);

						let rotate = false, x = false, y = false, scaleX = false, scaleY = false, shearY = false;
						const fromEntries = Object.entries(getValue(constraintMap, "properties", {})) as [string, any][];
						for (const [name, fromEntry] of fromEntries) {
							const from = this.fromProperty(name);
							const fromScale = this.propertyScale(name, scale);
							from.offset = getValue(fromEntry, "offset", 0) * fromScale;
							const toEntries = Object.entries(getValue(fromEntry, "to", {})) as [string, any][];
							for (const [name, toEntry] of toEntries) {
								let toScale = 1;
								let to: ToProperty;
								switch (name) {
									case "rotate": {
										rotate = true;
										to = new ToRotate();
										break;
									}
									case "x": {
										x = true;
										to = new ToX();
										toScale = scale;
										break;
									}
									case "y": {
										y = true;
										to = new ToY();
										toScale = scale;
										break;
									}
									case "scaleX": {
										scaleX = true;
										to = new ToScaleX();
										break;
									}
									case "scaleY": {
										scaleY = true;
										to = new ToScaleY();
										break;
									}
									case "shearY": {
										shearY = true;
										to = new ToShearY();
										break;
									}
									default: throw new Error("Invalid transform constraint to property: " + name);
								}
								to.offset = getValue(toEntry, "offset", 0) * toScale;
								to.max = getValue(toEntry, "max", 1) * toScale;
								to.scale = getValue(toEntry, "scale", 1) * toScale / fromScale;
								from.to.push(to);
							}
							if (from.to.length > 0) data.properties.push(from);
						}

						data.offsets[TransformConstraintData.ROTATION] = getValue(constraintMap, "rotation", 0);
						data.offsets[TransformConstraintData.X] = getValue(constraintMap, "x", 0) * scale;
						data.offsets[TransformConstraintData.Y] = getValue(constraintMap, "y", 0) * scale;
						data.offsets[TransformConstraintData.SCALEX] = getValue(constraintMap, "scaleX", 0);
						data.offsets[TransformConstraintData.SCALEY] = getValue(constraintMap, "scaleY", 0);
						data.offsets[TransformConstraintData.SHEARY] = getValue(constraintMap, "shearY", 0);

						const setup = data.setup;
						if (rotate) setup.mixRotate = getValue(constraintMap, "mixRotate", 1);
						if (x) setup.mixX = getValue(constraintMap, "mixX", 1);
						if (y) setup.mixY = getValue(constraintMap, "mixY", setup.mixX);
						if (scaleX) setup.mixScaleX = getValue(constraintMap, "mixScaleX", 1);
						if (scaleY) setup.mixScaleY = getValue(constraintMap, "mixScaleY", setup.mixScaleX);
						if (shearY) setup.mixShearY = getValue(constraintMap, "mixShearY", 1);

						skeletonData.constraints.push(data);
						break;
					}
					case "path": {
						const data = new PathConstraintData(name);
						data.skinRequired = skinRequired;

						for (let ii = 0; ii < constraintMap.bones.length; ii++) {
							let boneName = constraintMap.bones[ii];
							let bone = skeletonData.findBone(boneName);
							if (!bone) throw new Error(`Couldn't find bone ${boneName} for path constraint ${constraintMap.name}.`);
							data.bones.push(bone);
						}

						const slotName: string = constraintMap.slot;
						const slot = skeletonData.findSlot(slotName);
						if (!slot) throw new Error(`Couldn't find slot ${slotName} for path constraint ${constraintMap.name}.`);
						data.slot = slot;

						data.positionMode = Utils.enumValue(PositionMode, getValue(constraintMap, "positionMode", "Percent"));
						data.spacingMode = Utils.enumValue(SpacingMode, getValue(constraintMap, "spacingMode", "Length"));
						data.rotateMode = Utils.enumValue(RotateMode, getValue(constraintMap, "rotateMode", "Tangent"));
						data.offsetRotation = getValue(constraintMap, "rotation", 0);
						const setup = data.setup;
						setup.position = getValue(constraintMap, "position", 0);
						if (data.positionMode == PositionMode.Fixed) setup.position *= scale;
						setup.spacing = getValue(constraintMap, "spacing", 0);
						if (data.spacingMode == SpacingMode.Length || data.spacingMode == SpacingMode.Fixed) setup.spacing *= scale;
						setup.mixRotate = getValue(constraintMap, "mixRotate", 1);
						setup.mixX = getValue(constraintMap, "mixX", 1);
						setup.mixY = getValue(constraintMap, "mixY", setup.mixX);

						skeletonData.constraints.push(data);
						break;
					}
					case "physics": {
						const data = new PhysicsConstraintData(name);
						data.skinRequired = skinRequired;

						const boneName: string = constraintMap.bone;
						const bone = skeletonData.findBone(boneName);
						if (bone == null) throw new Error("Physics bone not found: " + boneName);
						data.bone = bone;

						data.x = getValue(constraintMap, "x", 0);
						data.y = getValue(constraintMap, "y", 0);
						data.rotate = getValue(constraintMap, "rotate", 0);
						data.scaleX = getValue(constraintMap, "scaleX", 0);
						data.shearX = getValue(constraintMap, "shearX", 0);
						data.limit = getValue(constraintMap, "limit", 5000) * scale;
						data.step = 1 / getValue(constraintMap, "fps", 60);
						const setup = data.setup;
						setup.inertia = getValue(constraintMap, "inertia", 0.5);
						setup.strength = getValue(constraintMap, "strength", 100);
						setup.damping = getValue(constraintMap, "damping", 0.85);
						setup.massInverse = 1 / getValue(constraintMap, "mass", 1);
						setup.wind = getValue(constraintMap, "wind", 0);
						setup.gravity = getValue(constraintMap, "gravity", 0);
						setup.mix = getValue(constraintMap, "mix", 1);
						data.inertiaGlobal = getValue(constraintMap, "inertiaGlobal", false);
						data.strengthGlobal = getValue(constraintMap, "strengthGlobal", false);
						data.dampingGlobal = getValue(constraintMap, "dampingGlobal", false);
						data.massGlobal = getValue(constraintMap, "massGlobal", false);
						data.windGlobal = getValue(constraintMap, "windGlobal", false);
						data.gravityGlobal = getValue(constraintMap, "gravityGlobal", false);
						data.mixGlobal = getValue(constraintMap, "mixGlobal", false);

						skeletonData.constraints.push(data);
						break;
					}
					case "slider": {
						const data = new SliderData(name);
						data.skinRequired = skinRequired;

						data.additive = getValue(constraintMap, "additive", false);
						data.loop = getValue(constraintMap, "loop", false);
						data.setup.time = getValue(constraintMap, "time", 0);
						data.setup.mix = getValue(constraintMap, "mix", 1);

						const boneName: string = constraintMap.bone;
						if (boneName) {
							data.bone = skeletonData.findBone(boneName);
							if (!data.bone) throw new Error("Slider bone not found: " + boneName);
							const property = constraintMap.property;
							data.property = this.fromProperty(property);
							data.property.offset = constraintMap.getFloat("offset", 0) * this.propertyScale(property, scale);
							data.scale = getValue(constraintMap, "scale", 1);
							data.local = getValue(constraintMap, "local", false);
						}

						skeletonData.constraints.push(data);
						break;
					}
				}
			}
		}

		// Skins.
		if (root.skins) {
			for (let i = 0; i < root.skins.length; i++) {
				let skinMap = root.skins[i]
				let skin = new Skin(skinMap.name);

				if (skinMap.bones) {
					for (let ii = 0; ii < skinMap.bones.length; ii++) {
						let boneName = skinMap.bones[ii];
						let bone = skeletonData.findBone(boneName);
						if (!bone) throw new Error(`Couldn't find bone ${boneName} for skin ${skinMap.name}.`);
						skin.bones.push(bone);
					}
				}

				if (skinMap.ik) {
					for (let ii = 0; ii < skinMap.ik.length; ii++) {
						let constraintName = skinMap.ik[ii];
						let constraint = skeletonData.findConstraint(constraintName, IkConstraintData);
						if (!constraint) throw new Error(`Couldn't find IK constraint ${constraintName} for skin ${skinMap.name}.`);
						skin.constraints.push(constraint);
					}
				}

				if (skinMap.transform) {
					for (let ii = 0; ii < skinMap.transform.length; ii++) {
						let constraintName = skinMap.transform[ii];
						let constraint = skeletonData.findConstraint(constraintName, TransformConstraintData);
						if (!constraint) throw new Error(`Couldn't find transform constraint ${constraintName} for skin ${skinMap.name}.`);
						skin.constraints.push(constraint);
					}
				}

				if (skinMap.path) {
					for (let ii = 0; ii < skinMap.path.length; ii++) {
						let constraintName = skinMap.path[ii];
						let constraint = skeletonData.findConstraint(constraintName, PathConstraintData);
						if (!constraint) throw new Error(`Couldn't find path constraint ${constraintName} for skin ${skinMap.name}.`);
						skin.constraints.push(constraint);
					}
				}

				if (skinMap.physics) {
					for (let ii = 0; ii < skinMap.physics.length; ii++) {
						let constraintName = skinMap.physics[ii];
						let constraint = skeletonData.findConstraint(constraintName, PhysicsConstraintData);
						if (!constraint) throw new Error(`Couldn't find physics constraint ${constraintName} for skin ${skinMap.name}.`);
						skin.constraints.push(constraint);
					}
				}

				if (skinMap.slider) {
					for (let ii = 0; ii < skinMap.slider.length; ii++) {
						let constraintName = skinMap.slider[ii];
						let constraint = skeletonData.findConstraint(constraintName, SliderData);
						if (!constraint) throw new Error(`Couldn't find slider constraint ${constraintName} for skin ${skinMap.name}.`);
						skin.constraints.push(constraint);
					}
				}

				for (let slotName in skinMap.attachments) {
					let slot = skeletonData.findSlot(slotName);
					if (!slot) throw new Error(`Couldn't find slot ${slotName} for skin ${skinMap.name}.`);
					let slotMap = skinMap.attachments[slotName];
					for (let entryName in slotMap) {
						let attachment = this.readAttachment(slotMap[entryName], skin, slot.index, entryName, skeletonData);
						if (attachment) skin.setAttachment(slot.index, entryName, attachment);
					}
				}
				skeletonData.skins.push(skin);
				if (skin.name == "default") skeletonData.defaultSkin = skin;
			}
		}

		// Linked meshes.
		for (let i = 0, n = this.linkedMeshes.length; i < n; i++) {
			let linkedMesh = this.linkedMeshes[i];
			let skin = !linkedMesh.skin ? skeletonData.defaultSkin : skeletonData.findSkin(linkedMesh.skin);
			if (!skin) throw new Error(`Skin not found: ${linkedMesh.skin}`);
			let parent = skin.getAttachment(linkedMesh.slotIndex, linkedMesh.parent);
			if (!parent) throw new Error(`Parent mesh not found: ${linkedMesh.parent}`);
			linkedMesh.mesh.timelineAttachment = linkedMesh.inheritTimeline ? <VertexAttachment>parent : <VertexAttachment>linkedMesh.mesh;
			linkedMesh.mesh.setParentMesh(<MeshAttachment>parent);
			if (linkedMesh.mesh.region != null) linkedMesh.mesh.updateRegion();
		}
		this.linkedMeshes.length = 0;

		// Events.
		if (root.events) {
			for (let eventName in root.events) {
				let eventMap = root.events[eventName];
				let data = new EventData(eventName);
				data.intValue = getValue(eventMap, "int", 0);
				data.floatValue = getValue(eventMap, "float", 0);
				data.stringValue = getValue(eventMap, "string", "");
				data.audioPath = getValue(eventMap, "audio", null);
				if (data.audioPath) {
					data.volume = getValue(eventMap, "volume", 1);
					data.balance = getValue(eventMap, "balance", 0);
				}
				skeletonData.events.push(data);
			}
		}

		// Animations.
		if (root.animations) {
			for (let animationName in root.animations) {
				let animationMap = root.animations[animationName];
				this.readAnimation(animationMap, animationName, skeletonData);
			}
		}

		// Slider animations.
		if (root.constraints) {
			for (let animationName in root.constraints) {
				let animationMap = root.constraints[animationName];
				if (animationMap.type === "slider") {
					const data = skeletonData.findConstraint(animationMap.name, SliderData)!;
					const animationName = animationMap.animation;
					const animation = skeletonData.findAnimation(animationName);
					if (!animation) throw new Error("Slider animation not found: " + animationName);
					data.animation = animation;
				}
			}
		}

		return skeletonData;
	}

	private fromProperty (type: string): FromProperty {
		let from: FromProperty;
		switch (type) {
			case "rotate": from = new FromRotate(); break;
			case "x": from = new FromX(); break;
			case "y": from = new FromY(); break;
			case "scaleX": from = new FromScaleX(); break;
			case "scaleY": from = new FromScaleY(); break;
			case "shearY": from = new FromShearY(); break;
			default: throw new Error("Invalid transform constraint from property: " + type);
		}
		return from;
	}

	private propertyScale (type: string, scale: number) {
		switch (type) {
			case "x":
			case "y": return scale;
			default: return 1;
		};
	}

	readAttachment (map: any, skin: Skin, slotIndex: number, name: string, skeletonData: SkeletonData): Attachment | null {
		let scale = this.scale;
		name = getValue(map, "name", name);

		switch (getValue(map, "type", "region")) {
			case "region": {
				let path = getValue(map, "path", name);
				let sequence = this.readSequence(getValue(map, "sequence", null));
				let region = this.attachmentLoader.newRegionAttachment(skin, name, path, sequence);
				if (!region) return null;
				region.path = path;
				region.x = getValue(map, "x", 0) * scale;
				region.y = getValue(map, "y", 0) * scale;
				region.scaleX = getValue(map, "scaleX", 1);
				region.scaleY = getValue(map, "scaleY", 1);
				region.rotation = getValue(map, "rotation", 0);
				region.width = map.width * scale;
				region.height = map.height * scale;
				region.sequence = sequence;

				let color: string = getValue(map, "color", null);
				if (color) region.color.setFromString(color);

				if (region.region != null) region.updateRegion();
				return region;
			}
			case "boundingbox": {
				let box = this.attachmentLoader.newBoundingBoxAttachment(skin, name);
				if (!box) return null;
				this.readVertices(map, box, map.vertexCount << 1);
				let color: string = getValue(map, "color", null);
				if (color) box.color.setFromString(color);
				return box;
			}
			case "mesh":
			case "linkedmesh": {
				let path = getValue(map, "path", name);
				let sequence = this.readSequence(getValue(map, "sequence", null));
				let mesh = this.attachmentLoader.newMeshAttachment(skin, name, path, sequence);
				if (!mesh) return null;
				mesh.path = path;

				let color = getValue(map, "color", null);
				if (color) mesh.color.setFromString(color);

				mesh.width = getValue(map, "width", 0) * scale;
				mesh.height = getValue(map, "height", 0) * scale;
				mesh.sequence = sequence;

				let parent: string = getValue(map, "parent", null);
				if (parent) {
					this.linkedMeshes.push(new LinkedMesh(mesh, <string>getValue(map, "skin", null), slotIndex, parent, getValue(map, "timelines", true)));
					return mesh;
				}

				let uvs: Array<number> = map.uvs;
				this.readVertices(map, mesh, uvs.length);
				mesh.triangles = map.triangles;
				mesh.regionUVs = uvs;
				if (mesh.region != null) mesh.updateRegion();

				mesh.edges = getValue(map, "edges", null);
				mesh.hullLength = getValue(map, "hull", 0) * 2;
				return mesh;
			}
			case "path": {
				let path = this.attachmentLoader.newPathAttachment(skin, name);
				if (!path) return null;
				path.closed = getValue(map, "closed", false);
				path.constantSpeed = getValue(map, "constantSpeed", true);

				let vertexCount = map.vertexCount;
				this.readVertices(map, path, vertexCount << 1);

				let lengths: Array<number> = Utils.newArray(vertexCount / 3, 0);
				for (let i = 0; i < map.lengths.length; i++)
					lengths[i] = map.lengths[i] * scale;
				path.lengths = lengths;

				let color: string = getValue(map, "color", null);
				if (color) path.color.setFromString(color);
				return path;
			}
			case "point": {
				let point = this.attachmentLoader.newPointAttachment(skin, name);
				if (!point) return null;
				point.x = getValue(map, "x", 0) * scale;
				point.y = getValue(map, "y", 0) * scale;
				point.rotation = getValue(map, "rotation", 0);

				let color = getValue(map, "color", null);
				if (color) point.color.setFromString(color);
				return point;
			}
			case "clipping": {
				let clip = this.attachmentLoader.newClippingAttachment(skin, name);
				if (!clip) return null;

				let end = getValue(map, "end", null);
				if (end) clip.endSlot = skeletonData.findSlot(end);

				let vertexCount = map.vertexCount;
				this.readVertices(map, clip, vertexCount << 1);

				let color: string = getValue(map, "color", null);
				if (color) clip.color.setFromString(color);
				return clip;
			}
		}
		return null;
	}

	readSequence (map: any) {
		if (map == null) return null;
		let sequence = new Sequence(getValue(map, "count", 0));
		sequence.start = getValue(map, "start", 1);
		sequence.digits = getValue(map, "digits", 0);
		sequence.setupIndex = getValue(map, "setup", 0);
		return sequence;
	}

	readVertices (map: any, attachment: VertexAttachment, verticesLength: number) {
		let scale = this.scale;
		attachment.worldVerticesLength = verticesLength;
		let vertices: Array<number> = map.vertices;
		if (verticesLength == vertices.length) {
			let scaledVertices = Utils.toFloatArray(vertices);
			if (scale != 1) {
				for (let i = 0, n = vertices.length; i < n; i++)
					scaledVertices[i] *= scale;
			}
			attachment.vertices = scaledVertices;
			return;
		}
		let weights = new Array<number>();
		let bones = new Array<number>();
		for (let i = 0, n = vertices.length; i < n;) {
			let boneCount = vertices[i++];
			bones.push(boneCount);
			for (let nn = i + boneCount * 4; i < nn; i += 4) {
				bones.push(vertices[i]);
				weights.push(vertices[i + 1] * scale);
				weights.push(vertices[i + 2] * scale);
				weights.push(vertices[i + 3]);
			}
		}
		attachment.bones = bones;
		attachment.vertices = Utils.toFloatArray(weights);
	}

	readAnimation (map: any, name: string, skeletonData: SkeletonData) {
		let scale = this.scale;
		let timelines = new Array<Timeline>();

		// Slot timelines.
		if (map.slots) {
			for (let slotName in map.slots) {
				let slotMap = map.slots[slotName];
				let slot = skeletonData.findSlot(slotName);
				if (!slot) throw new Error("Slot not found: " + slotName);
				let slotIndex = slot.index;
				for (let timelineName in slotMap) {
					let timelineMap = slotMap[timelineName];
					if (!timelineMap) continue;
					let frames = timelineMap.length;

					switch (timelineName) {
						case "attachment": {
							let timeline = new AttachmentTimeline(frames, slotIndex);
							for (let frame = 0; frame < frames; frame++) {
								let keyMap = timelineMap[frame];
								timeline.setFrame(frame, getValue(keyMap, "time", 0), getValue(keyMap, "name", null));
							}
							timelines.push(timeline);
							break;
						}
						case "rgba": {
							let timeline = new RGBATimeline(frames, frames << 2, slotIndex);
							let keyMap = timelineMap[0];
							let time = getValue(keyMap, "time", 0);
							let color = Color.fromString(keyMap.color);

							for (let frame = 0, bezier = 0; ; frame++) {
								timeline.setFrame(frame, time, color.r, color.g, color.b, color.a);
								let nextMap = timelineMap[frame + 1];
								if (!nextMap) {
									timeline.shrink(bezier);
									break;
								}
								let time2 = getValue(nextMap, "time", 0);
								let newColor = Color.fromString(nextMap.color);
								let curve = keyMap.curve;
								if (curve) {
									bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, color.r, newColor.r, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, color.g, newColor.g, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 2, time, time2, color.b, newColor.b, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 3, time, time2, color.a, newColor.a, 1);
								}
								time = time2;
								color = newColor;
								keyMap = nextMap;
							}

							timelines.push(timeline);
							break;
						}
						case "rgb": {
							let timeline = new RGBTimeline(frames, frames * 3, slotIndex);
							let keyMap = timelineMap[0];
							let time = getValue(keyMap, "time", 0);
							let color = Color.fromString(keyMap.color);

							for (let frame = 0, bezier = 0; ; frame++) {
								timeline.setFrame(frame, time, color.r, color.g, color.b);
								let nextMap = timelineMap[frame + 1];
								if (!nextMap) {
									timeline.shrink(bezier);
									break;
								}
								let time2 = getValue(nextMap, "time", 0);
								let newColor = Color.fromString(nextMap.color);
								let curve = keyMap.curve;
								if (curve) {
									bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, color.r, newColor.r, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, color.g, newColor.g, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 2, time, time2, color.b, newColor.b, 1);
								}
								time = time2;
								color = newColor;
								keyMap = nextMap;
							}

							timelines.push(timeline);
							break;
						}
						case "alpha": {
							readTimeline1(timelines, timelineMap, new AlphaTimeline(frames, frames, slotIndex), 0, 1);
							break;
						}
						case "rgba2": {
							let timeline = new RGBA2Timeline(frames, frames * 7, slotIndex);

							let keyMap = timelineMap[0];
							let time = getValue(keyMap, "time", 0);
							let color = Color.fromString(keyMap.light);
							let color2 = Color.fromString(keyMap.dark);

							for (let frame = 0, bezier = 0; ; frame++) {
								timeline.setFrame(frame, time, color.r, color.g, color.b, color.a, color2.r, color2.g, color2.b);
								let nextMap = timelineMap[frame + 1];
								if (!nextMap) {
									timeline.shrink(bezier);
									break;
								}
								let time2 = getValue(nextMap, "time", 0);
								let newColor = Color.fromString(nextMap.light);
								let newColor2 = Color.fromString(nextMap.dark);
								let curve = keyMap.curve;
								if (curve) {
									bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, color.r, newColor.r, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, color.g, newColor.g, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 2, time, time2, color.b, newColor.b, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 3, time, time2, color.a, newColor.a, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 4, time, time2, color2.r, newColor2.r, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 5, time, time2, color2.g, newColor2.g, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 6, time, time2, color2.b, newColor2.b, 1);
								}
								time = time2;
								color = newColor;
								color2 = newColor2;
								keyMap = nextMap;
							}

							timelines.push(timeline);
							break;
						}
						case "rgb2": {
							let timeline = new RGB2Timeline(frames, frames * 6, slotIndex);

							let keyMap = timelineMap[0];
							let time = getValue(keyMap, "time", 0);
							let color = Color.fromString(keyMap.light);
							let color2 = Color.fromString(keyMap.dark);

							for (let frame = 0, bezier = 0; ; frame++) {
								timeline.setFrame(frame, time, color.r, color.g, color.b, color2.r, color2.g, color2.b);
								let nextMap = timelineMap[frame + 1];
								if (!nextMap) {
									timeline.shrink(bezier);
									break;
								}
								let time2 = getValue(nextMap, "time", 0);
								let newColor = Color.fromString(nextMap.light);
								let newColor2 = Color.fromString(nextMap.dark);
								let curve = keyMap.curve;
								if (curve) {
									bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, color.r, newColor.r, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, color.g, newColor.g, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 2, time, time2, color.b, newColor.b, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 3, time, time2, color2.r, newColor2.r, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 4, time, time2, color2.g, newColor2.g, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 5, time, time2, color2.b, newColor2.b, 1);
								}
								time = time2;
								color = newColor;
								color2 = newColor2;
								keyMap = nextMap;
							}

							timelines.push(timeline);
							break;
						}
						default:
							throw new Error("Invalid timeline type for a slot: " + timelineMap.name + " (" + slotMap.name + ")");
					}
				}
			}
		}

		// Bone timelines.
		if (map.bones) {
			for (let boneName in map.bones) {
				let boneMap = map.bones[boneName];
				let bone = skeletonData.findBone(boneName);
				if (!bone) throw new Error("Bone not found: " + boneName);
				let boneIndex = bone.index;
				for (let timelineName in boneMap) {
					let timelineMap = boneMap[timelineName];
					let frames = timelineMap.length;
					if (frames == 0) continue;

					switch (timelineName) {
						case "rotate": readTimeline1(timelines, timelineMap, new RotateTimeline(frames, frames, boneIndex), 0, 1); break;
						case "translate": readTimeline2(timelines, timelineMap, new TranslateTimeline(frames, frames << 1, boneIndex), "x", "y", 0, scale); break;
						case "translatex": readTimeline1(timelines, timelineMap, new TranslateXTimeline(frames, frames, boneIndex), 0, scale); break;
						case "translatey": readTimeline1(timelines, timelineMap, new TranslateYTimeline(frames, frames, boneIndex), 0, scale); break;
						case "scale": readTimeline2(timelines, timelineMap, new ScaleTimeline(frames, frames << 1, boneIndex), "x", "y", 1, 1); break;
						case "scalex": readTimeline1(timelines, timelineMap, new ScaleXTimeline(frames, frames, boneIndex), 1, 1); break;
						case "scaley": readTimeline1(timelines, timelineMap, new ScaleYTimeline(frames, frames, boneIndex), 1, 1); break;
						case "shear": readTimeline2(timelines, timelineMap, new ShearTimeline(frames, frames << 1, boneIndex), "x", "y", 0, 1); break;
						case "shearx": readTimeline1(timelines, timelineMap, new ShearXTimeline(frames, frames, boneIndex), 0, 1); break;
						case "sheary": readTimeline1(timelines, timelineMap, new ShearYTimeline(frames, frames, boneIndex), 0, 1); break;
						case "inherit":
							const timeline = new InheritTimeline(frames, bone.index);
							for (let frame = 0; frame < timelineMap.length; frame++) {
								let aFrame = timelineMap[frame];
								timeline.setFrame(frame, getValue(aFrame, "time", 0), Utils.enumValue(Inherit, getValue(aFrame, "inherit", "Normal")));
							}
							timelines.push(timeline);
							break;
						default:
							throw new Error("Invalid timeline type for a bone: " + timelineMap.name + " (" + boneMap.name + ")");
					}

				}
			}
		}

		// IK constraint timelines.
		if (map.ik) {
			for (let constraintName in map.ik) {
				let constraintMap = map.ik[constraintName];
				let keyMap = constraintMap[0];
				if (!keyMap) continue;

				let constraint = skeletonData.findConstraint(constraintName, IkConstraintData);
				if (!constraint) throw new Error("IK Constraint not found: " + constraintName);
				const timeline = new IkConstraintTimeline(constraintMap.length, constraintMap.length << 1,
					skeletonData.constraints.indexOf(constraint));

				let time = getValue(keyMap, "time", 0);
				let mix = getValue(keyMap, "mix", 1);
				let softness = getValue(keyMap, "softness", 0) * scale;

				for (let frame = 0, bezier = 0; ; frame++) {
					timeline.setFrame(frame, time, mix, softness, getValue(keyMap, "bendPositive", true) ? 1 : -1, getValue(keyMap, "compress", false), getValue(keyMap, "stretch", false));
					let nextMap = constraintMap[frame + 1];
					if (!nextMap) {
						timeline.shrink(bezier);
						break;
					}

					let time2 = getValue(nextMap, "time", 0);
					let mix2 = getValue(nextMap, "mix", 1);
					let softness2 = getValue(nextMap, "softness", 0) * scale;
					let curve = keyMap.curve;
					if (curve) {
						bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, mix, mix2, 1);
						bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, softness, softness2, scale);
					}

					time = time2;
					mix = mix2;
					softness = softness2;
					keyMap = nextMap;
				}
				timelines.push(timeline);
			}
		}

		// Transform constraint timelines.
		if (map.transform) {
			for (let constraintName in map.transform) {
				let timelineMap = map.transform[constraintName];
				let keyMap = timelineMap[0];
				if (!keyMap) continue;

				let constraint = skeletonData.findConstraint(constraintName, TransformConstraintData);
				if (!constraint) throw new Error("Transform constraint not found: " + constraintName);
				let timeline = new TransformConstraintTimeline(timelineMap.length, timelineMap.length * 6,
					skeletonData.constraints.indexOf(constraint));

				let time = getValue(keyMap, "time", 0);
				let mixRotate = getValue(keyMap, "mixRotate", 0);
				let mixX = getValue(keyMap, "mixX", 0);
				let mixY = getValue(keyMap, "mixY", mixX);
				let mixScaleX = getValue(keyMap, "mixScaleX", 0);
				let mixScaleY = getValue(keyMap, "mixScaleY", mixScaleX);
				let mixShearY = getValue(keyMap, "mixShearY", 0);

				for (let frame = 0, bezier = 0; ; frame++) {
					timeline.setFrame(frame, time, mixRotate, mixX, mixY, mixScaleX, mixScaleY, mixShearY);
					let nextMap = timelineMap[frame + 1];
					if (!nextMap) {
						timeline.shrink(bezier);
						break;
					}

					let time2 = getValue(nextMap, "time", 0);
					let mixRotate2 = getValue(nextMap, "mixRotate", 1);
					let mixX2 = getValue(nextMap, "mixX", 1);
					let mixY2 = getValue(nextMap, "mixY", mixX2);
					let mixScaleX2 = getValue(nextMap, "mixScaleX", 1);
					let mixScaleY2 = getValue(nextMap, "mixScaleY", mixScaleX2);
					let mixShearY2 = getValue(nextMap, "mixShearY", 1);
					let curve = keyMap.curve;
					if (curve) {
						bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, mixRotate, mixRotate2, 1);
						bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, mixX, mixX2, 1);
						bezier = readCurve(curve, timeline, bezier, frame, 2, time, time2, mixY, mixY2, 1);
						bezier = readCurve(curve, timeline, bezier, frame, 3, time, time2, mixScaleX, mixScaleX2, 1);
						bezier = readCurve(curve, timeline, bezier, frame, 4, time, time2, mixScaleY, mixScaleY2, 1);
						bezier = readCurve(curve, timeline, bezier, frame, 5, time, time2, mixShearY, mixShearY2, 1);
					}

					time = time2;
					mixRotate = mixRotate2;
					mixX = mixX2;
					mixY = mixY2;
					mixScaleX = mixScaleX2;
					mixScaleY = mixScaleY2;
					mixScaleX = mixScaleX2;
					keyMap = nextMap;
				}
				timelines.push(timeline);
			}
		}

		// Path constraint timelines.
		if (map.path) {
			for (let constraintName in map.path) {
				const constraintMap = map.path[constraintName];
				const constraint = skeletonData.findConstraint(constraintName, PathConstraintData);
				if (!constraint) throw new Error("Path constraint not found: " + constraintName);
				const index = skeletonData.constraints.indexOf(constraint);
				for (const timelineName in constraintMap) {
					const timelineMap = constraintMap[timelineName];
					let keyMap = timelineMap[0];
					if (!keyMap) continue;

					const frames = timelineMap.length;
					switch (timelineName) {
						case "position": {
							const timeline = new PathConstraintPositionTimeline(frames, frames, index);
							readTimeline1(timelines, timelineMap, timeline, 0, constraint.positionMode == PositionMode.Fixed ? scale : 1);
							break;
						}
						case "spacing": {
							const timeline = new PathConstraintSpacingTimeline(frames, frames, index);
							readTimeline1(timelines, timelineMap, timeline, 0, constraint.spacingMode == SpacingMode.Length || constraint.spacingMode == SpacingMode.Fixed ? scale : 1);
							break;
						}
						case "mix": {
							const timeline = new PathConstraintMixTimeline(frames, frames * 3, index);
							let time = getValue(keyMap, "time", 0);
							let mixRotate = getValue(keyMap, "mixRotate", 1);
							let mixX = getValue(keyMap, "mixX", 1);
							let mixY = getValue(keyMap, "mixY", mixX);
							for (let frame = 0, bezier = 0; ; frame++) {
								timeline.setFrame(frame, time, mixRotate, mixX, mixY);
								let nextMap = timelineMap[frame + 1];
								if (!nextMap) {
									timeline.shrink(bezier);
									break;
								}
								let time2 = getValue(nextMap, "time", 0);
								let mixRotate2 = getValue(nextMap, "mixRotate", 1);
								let mixX2 = getValue(nextMap, "mixX", 1);
								let mixY2 = getValue(nextMap, "mixY", mixX2);
								let curve = keyMap.curve;
								if (curve) {
									bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, mixRotate, mixRotate2, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, mixX, mixX2, 1);
									bezier = readCurve(curve, timeline, bezier, frame, 2, time, time2, mixY, mixY2, 1);
								}
								time = time2;
								mixRotate = mixRotate2;
								mixX = mixX2;
								mixY = mixY2;
								keyMap = nextMap;
							}
							timelines.push(timeline);
							break;
						}
					}
				}
			}
		}

		// Physics constraint timelines.
		if (map.physics) {
			for (const constraintName in map.physics) {
				const constraintMap = map.physics[constraintName];
				let index = -1;
				if (constraintName.length > 0) {
					const constraint = skeletonData.findConstraint(constraintName, PhysicsConstraintData);
					if (!constraint) throw new Error("Physics constraint not found: " + constraintName);
					index = skeletonData.constraints.indexOf(constraint);
				}
				for (const timelineName in constraintMap) {
					const timelineMap = constraintMap[timelineName];
					let keyMap = timelineMap[0];
					if (!keyMap) continue;

					const frames = timelineMap.length;
					let timeline;
					let defaultValue = 0;
					if (timelineName === "reset") {
						const resetTimeline = new PhysicsConstraintResetTimeline(frames, index);
						for (let frame = 0; keyMap != null; keyMap = timelineMap[frame + 1], frame++)
							resetTimeline.setFrame(frame, getValue(keyMap, "time", 0));
						timelines.push(resetTimeline);
						continue;
					}
					switch (timelineName) {
						case "inertia": timeline = new PhysicsConstraintInertiaTimeline(frames, frames, index); break;
						case "strength": timeline = new PhysicsConstraintStrengthTimeline(frames, frames, index); break;
						case "damping": timeline = new PhysicsConstraintDampingTimeline(frames, frames, index); break;
						case "mass": timeline = new PhysicsConstraintMassTimeline(frames, frames, index); break;
						case "wind": timeline = new PhysicsConstraintWindTimeline(frames, frames, index); break;
						case "gravity": timeline = new PhysicsConstraintGravityTimeline(frames, frames, index); break;
						case "mix": timeline = new PhysicsConstraintMixTimeline(frames, frames, index); break;
						default: continue;
					}
					readTimeline1(timelines, timelineMap, timeline, 0, 1);
				}
			}
		}

		// Slider timelines.
		if (map.slider) {
			for (const constraintName in map.slider) {
				const constraintMap = map.slider[constraintName];
				const constraint = skeletonData.findConstraint(constraintName, SliderData);
				if (!constraint) throw new Error("Slider not found: " + constraintName);
				const index = skeletonData.constraints.indexOf(constraint);

				for (const timelineName in constraintMap) {
					const timelineMap = constraintMap[timelineName];
					let keyMap = timelineMap[0];
					if (!keyMap) continue;

					const frames = timelineMap.length;
					switch (timelineName) {
						case "time": readTimeline1(timelines, timelineMap, new SliderTimeline(frames, frames, index), 1, 1); break;
						case "mix": readTimeline1(timelines, timelineMap, new SliderMixTimeline(frames, frames, index), 1, 1); break;
					}
				}
			}
		}

		// Attachment timelines.
		if (map.attachments) {
			for (let attachmentsName in map.attachments) {
				let attachmentsMap = map.attachments[attachmentsName];
				let skin = skeletonData.findSkin(attachmentsName);
				if (!skin) throw new Error("Skin not found: " + attachmentsName);
				for (let slotMapName in attachmentsMap) {
					let slotMap = attachmentsMap[slotMapName];
					let slot = skeletonData.findSlot(slotMapName);
					if (!slot) throw new Error("Slot not found: " + slotMapName);
					let slotIndex = slot.index;
					for (let attachmentMapName in slotMap) {
						let attachmentMap = slotMap[attachmentMapName];
						let attachment = <VertexAttachment>skin.getAttachment(slotIndex, attachmentMapName);
						if (!attachment) throw new Error("Timeline attachment not found: " + attachmentMapName);

						for (let timelineMapName in attachmentMap) {
							let timelineMap = attachmentMap[timelineMapName];
							let keyMap = timelineMap[0];
							if (!keyMap) continue;

							if (timelineMapName == "deform") {
								let weighted = attachment.bones;
								let vertices = attachment.vertices;
								let deformLength = weighted ? vertices.length / 3 * 2 : vertices.length;

								let timeline = new DeformTimeline(timelineMap.length, timelineMap.length, slotIndex, attachment);
								let time = getValue(keyMap, "time", 0);
								for (let frame = 0, bezier = 0; ; frame++) {
									let deform: NumberArrayLike;
									let verticesValue: Array<Number> = getValue(keyMap, "vertices", null);
									if (!verticesValue)
										deform = weighted ? Utils.newFloatArray(deformLength) : vertices;
									else {
										deform = Utils.newFloatArray(deformLength);
										let start = <number>getValue(keyMap, "offset", 0);
										Utils.arrayCopy(verticesValue, 0, deform, start, verticesValue.length);
										if (scale != 1) {
											for (let i = start, n = i + verticesValue.length; i < n; i++)
												deform[i] *= scale;
										}
										if (!weighted) {
											for (let i = 0; i < deformLength; i++)
												deform[i] += vertices[i];
										}
									}

									timeline.setFrame(frame, time, deform);
									let nextMap = timelineMap[frame + 1];
									if (!nextMap) {
										timeline.shrink(bezier);
										break;
									}
									let time2 = getValue(nextMap, "time", 0);
									let curve = keyMap.curve;
									if (curve) bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, 0, 1, 1);
									time = time2;
									keyMap = nextMap;
								}
								timelines.push(timeline);
							} else if (timelineMapName == "sequence") {
								let timeline = new SequenceTimeline(timelineMap.length, slotIndex, attachment as unknown as HasTextureRegion);
								let lastDelay = 0;
								for (let frame = 0; frame < timelineMap.length; frame++) {
									let delay = getValue(keyMap, "delay", lastDelay);
									let time = getValue(keyMap, "time", 0);
									let mode = SequenceMode[getValue(keyMap, "mode", "hold")] as unknown as number;
									let index = getValue(keyMap, "index", 0);
									timeline.setFrame(frame, time, mode, index, delay);
									lastDelay = delay;
									keyMap = timelineMap[frame + 1];
								}
								timelines.push(timeline);
							}
						}
					}
				}
			}
		}

		// Draw order timelines.
		if (map.drawOrder) {
			let timeline = new DrawOrderTimeline(map.drawOrder.length);
			let slotCount = skeletonData.slots.length;
			let frame = 0;
			for (let i = 0; i < map.drawOrder.length; i++, frame++) {
				let drawOrderMap = map.drawOrder[i];
				let drawOrder: Array<number> | null = null;
				let offsets = getValue(drawOrderMap, "offsets", null);
				if (offsets) {
					drawOrder = Utils.newArray<number>(slotCount, -1);
					let unchanged = Utils.newArray<number>(slotCount - offsets.length, 0);
					let originalIndex = 0, unchangedIndex = 0;
					for (let ii = 0; ii < offsets.length; ii++) {
						let offsetMap = offsets[ii];
						let slot = skeletonData.findSlot(offsetMap.slot);
						if (!slot) throw new Error("Slot not found: " + slot);
						let slotIndex = slot.index;
						// Collect unchanged items.
						while (originalIndex != slotIndex)
							unchanged[unchangedIndex++] = originalIndex++;
						// Set changed items.
						drawOrder[originalIndex + offsetMap.offset] = originalIndex++;
					}
					// Collect remaining unchanged items.
					while (originalIndex < slotCount)
						unchanged[unchangedIndex++] = originalIndex++;
					// Fill in unchanged items.
					for (let ii = slotCount - 1; ii >= 0; ii--)
						if (drawOrder[ii] == -1) drawOrder[ii] = unchanged[--unchangedIndex];
				}
				timeline.setFrame(frame, getValue(drawOrderMap, "time", 0), drawOrder);
			}
			timelines.push(timeline);
		}

		// Event timelines.
		if (map.events) {
			let timeline = new EventTimeline(map.events.length);
			let frame = 0;
			for (let i = 0; i < map.events.length; i++, frame++) {
				let eventMap = map.events[i];
				let eventData = skeletonData.findEvent(eventMap.name);
				if (!eventData) throw new Error("Event not found: " + eventMap.name);
				let event = new Event(Utils.toSinglePrecision(getValue(eventMap, "time", 0)), eventData);
				event.intValue = getValue(eventMap, "int", eventData.intValue);
				event.floatValue = getValue(eventMap, "float", eventData.floatValue);
				event.stringValue = getValue(eventMap, "string", eventData.stringValue);
				if (event.data.audioPath) {
					event.volume = getValue(eventMap, "volume", 1);
					event.balance = getValue(eventMap, "balance", 0);
				}
				timeline.setFrame(frame, event);
			}
			timelines.push(timeline);
		}

		let duration = 0;
		for (let i = 0, n = timelines.length; i < n; i++)
			duration = Math.max(duration, timelines[i].getDuration());
		skeletonData.animations.push(new Animation(name, timelines, duration));
	}
}

class LinkedMesh {
	parent: string; skin: string;
	slotIndex: number;
	mesh: MeshAttachment;
	inheritTimeline: boolean;

	constructor (mesh: MeshAttachment, skin: string, slotIndex: number, parent: string, inheritDeform: boolean) {
		this.mesh = mesh;
		this.skin = skin;
		this.slotIndex = slotIndex;
		this.parent = parent;
		this.inheritTimeline = inheritDeform;
	}
}

function readTimeline1 (timelines: Array<Timeline>, keys: any[], timeline: CurveTimeline1, defaultValue: number, scale: number) {
	let keyMap = keys[0];
	let time = getValue(keyMap, "time", 0);
	let value = getValue(keyMap, "value", defaultValue) * scale;
	let bezier = 0;
	for (let frame = 0; ; frame++) {
		timeline.setFrame(frame, time, value);
		let nextMap = keys[frame + 1];
		if (!nextMap) {
			timeline.shrink(bezier);
			timelines.push(timeline);
			return;
		}
		let time2 = getValue(nextMap, "time", 0);
		let value2 = getValue(nextMap, "value", defaultValue) * scale;
		if (keyMap.curve) bezier = readCurve(keyMap.curve, timeline, bezier, frame, 0, time, time2, value, value2, scale);
		time = time2;
		value = value2;
		keyMap = nextMap;
	}
}

function readTimeline2 (timelines: Array<Timeline>, keys: any[], timeline: BoneTimeline2, name1: string, name2: string, defaultValue: number, scale: number) {
	let keyMap = keys[0];
	let time = getValue(keyMap, "time", 0);
	let value1 = getValue(keyMap, name1, defaultValue) * scale;
	let value2 = getValue(keyMap, name2, defaultValue) * scale;
	let bezier = 0;
	for (let frame = 0; ; frame++) {
		timeline.setFrame(frame, time, value1, value2);
		let nextMap = keys[frame + 1];
		if (!nextMap) {
			timeline.shrink(bezier);
			timelines.push(timeline);
			return;
		}
		let time2 = getValue(nextMap, "time", 0);
		let nvalue1 = getValue(nextMap, name1, defaultValue) * scale;
		let nvalue2 = getValue(nextMap, name2, defaultValue) * scale;
		let curve = keyMap.curve;
		if (curve) {
			bezier = readCurve(curve, timeline, bezier, frame, 0, time, time2, value1, nvalue1, scale);
			bezier = readCurve(curve, timeline, bezier, frame, 1, time, time2, value2, nvalue2, scale);
		}
		time = time2;
		value1 = nvalue1;
		value2 = nvalue2;
		keyMap = nextMap;
	}
}

function readCurve (curve: any, timeline: CurveTimeline, bezier: number, frame: number, value: number, time1: number, time2: number,
	value1: number, value2: number, scale: number) {
	if (curve == "stepped") {
		timeline.setStepped(frame);
		return bezier;
	}
	let i = value << 2;
	let cx1 = curve[i];
	let cy1 = curve[i + 1] * scale;
	let cx2 = curve[i + 2];
	let cy2 = curve[i + 3] * scale;
	timeline.setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
	return bezier + 1;
}

function getValue (map: any, property: string, defaultValue: any) {
	return map[property] !== undefined ? map[property] : defaultValue;
}
