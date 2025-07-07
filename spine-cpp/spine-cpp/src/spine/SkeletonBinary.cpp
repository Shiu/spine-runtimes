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

#include <spine/SkeletonBinary.h>

#include <spine/Animation.h>
#include <spine/Atlas.h>
#include <spine/AtlasAttachmentLoader.h>
#include <spine/Attachment.h>
#include <spine/CurveTimeline.h>
#include <spine/LinkedMesh.h>
#include <spine/SkeletonData.h>
#include <spine/Skin.h>
#include <spine/VertexAttachment.h>

#include <spine/AttachmentTimeline.h>
#include <spine/AttachmentType.h>
#include <spine/BoneData.h>
#include <spine/BoundingBoxAttachment.h>
#include <spine/ClippingAttachment.h>
#include <spine/ColorTimeline.h>
#include <spine/ContainerUtil.h>
#include <spine/DeformTimeline.h>
#include <spine/DrawOrderTimeline.h>
#include <spine/Event.h>
#include <spine/EventData.h>
#include <spine/EventTimeline.h>
#include <spine/IkConstraintData.h>
#include <spine/IkConstraintTimeline.h>
#include <spine/InheritTimeline.h>
#include <spine/MeshAttachment.h>
#include <spine/PathAttachment.h>
#include <spine/PathConstraintData.h>
#include <spine/PathConstraintMixTimeline.h>
#include <spine/PathConstraintPositionTimeline.h>
#include <spine/PathConstraintSpacingTimeline.h>
#include <spine/PhysicsConstraintData.h>
#include <spine/PhysicsConstraintTimeline.h>
#include <spine/PointAttachment.h>
#include <spine/RegionAttachment.h>
#include <spine/RotateTimeline.h>
#include <spine/ScaleTimeline.h>
#include <spine/ShearTimeline.h>
#include <spine/SlotData.h>
#include <spine/TransformConstraintData.h>
#include <spine/TransformConstraintTimeline.h>
#include <spine/TranslateTimeline.h>
#include <spine/SequenceTimeline.h>
#include <spine/SliderData.h>
#include <spine/SliderTimeline.h>
#include <spine/SliderMixTimeline.h>
#include <spine/Version.h>

using namespace spine;

SkeletonBinary::SkeletonBinary(Atlas *atlas) : _attachmentLoader(
													   new(__FILE__, __LINE__) AtlasAttachmentLoader(atlas)),
											   _error(), _scale(1), _ownsLoader(true) {
}

SkeletonBinary::SkeletonBinary(AttachmentLoader *attachmentLoader, bool ownsLoader) : _attachmentLoader(
																							  attachmentLoader),
																					  _error(),
																					  _scale(1),
																					  _ownsLoader(ownsLoader) {
	assert(_attachmentLoader != NULL);
}

SkeletonBinary::~SkeletonBinary() {
	ContainerUtil::cleanUpVectorOfPointers(_linkedMeshes);
	_linkedMeshes.clear();

	if (_ownsLoader) delete _attachmentLoader;
}

SkeletonData *SkeletonBinary::readSkeletonDataFile(const String &path) {
	int length;
	const char *binary = SpineExtension::readFile(path.buffer(), &length);
	if (length == 0 || !binary) {
		setError("Unable to read skeleton file: ", path.buffer());
		return NULL;
	}

	SkeletonData *skeletonData = readSkeletonData((unsigned char *) binary, length);
	SpineExtension::free(binary, __FILE__, __LINE__);

	if (skeletonData) {
		// Extract filename without extension
		const char *lastSlash = strrchr(path.buffer(), '/');
		const char *lastBackslash = strrchr(path.buffer(), '\\');
		const char *filename = path.buffer();
		if (lastSlash) filename = lastSlash + 1;
		if (lastBackslash && lastBackslash > filename) filename = lastBackslash + 1;

		String nameWithoutExtension(filename);
		const char *lastDot = strrchr(nameWithoutExtension.buffer(), '.');
		if (lastDot) {
			int length = lastDot - nameWithoutExtension.buffer();
			nameWithoutExtension = String(nameWithoutExtension.buffer(), length);
		}
		skeletonData->_name = nameWithoutExtension;
	}

	return skeletonData;
}

SkeletonData *SkeletonBinary::readSkeletonData(const unsigned char *binary, const int length) {
	if (binary == NULL || length == 0) {
		setError("Unable to read skeleton file: ", "");
		return NULL;
	}

	ContainerUtil::cleanUpVectorOfPointers(_linkedMeshes);
	_linkedMeshes.clear();

	SkeletonData *skeletonData = new (__FILE__, __LINE__) SkeletonData();
	DataInput input(skeletonData, binary, length);
	String version;
	{// try block in Java
		long long hash = input.readLong();
		if (hash == 0) {
			skeletonData->_hash = "";
		} else {
			char buffer[32];
			snprintf(buffer, 32, "%llx", hash);
			skeletonData->_hash = String(buffer);
		}
		skeletonData->_version.own(input.readString());
		if (skeletonData->_version.isEmpty()) skeletonData->_version = "";
		version = skeletonData->_version;
		if (!skeletonData->_version.startsWith(SPINE_VERSION_STRING)) {
			String errorMsg = "Skeleton version ";
			errorMsg.append(skeletonData->_version);
			errorMsg.append(" does not match runtime version ");
			errorMsg.append(SPINE_VERSION_STRING);
			setError(errorMsg.buffer(), "");
			delete skeletonData;
			return NULL;
		}
		skeletonData->_x = input.readFloat();
		skeletonData->_y = input.readFloat();
		skeletonData->_width = input.readFloat();
		skeletonData->_height = input.readFloat();
		skeletonData->_referenceScale = input.readFloat() * this->_scale;

		bool nonessential = input.readBoolean();
		if (nonessential) {
			skeletonData->_fps = input.readFloat();
			skeletonData->_imagesPath.own(input.readString());
			skeletonData->_audioPath.own(input.readString());
		}

		int n = input.readInt(true);
		Vector<char *> &strings = skeletonData->_strings.setSize(n, NULL);
		for (int i = 0; i < n; i++)
			strings[i] = input.readString();

		/* Bones. */
		Vector<BoneData *> &bones = skeletonData->_bones.setSize(input.readInt(true), NULL);
		for (int i = 0; i < bones.size(); ++i) {
			const char *name = input.readString();
			BoneData *parent = i == 0 ? 0 : bones[input.readInt(true)];
			BoneData *data = new (__FILE__, __LINE__) BoneData(i, String(name, true), parent);
			BoneLocal &setup = data->_setup;
			setup._rotation = input.readFloat();
			setup._x = input.readFloat() * _scale;
			setup._y = input.readFloat() * _scale;
			setup._scaleX = input.readFloat();
			setup._scaleY = input.readFloat();
			setup._shearX = input.readFloat();
			setup._shearY = input.readFloat();
			setup._inherit = static_cast<Inherit>(input.readByte());
			data->_length = input.readFloat() * _scale;
			data->_skinRequired = input.readBoolean();
			if (nonessential) {
				Color::rgba8888ToColor(data->getColor(), input.readInt());
				data->_icon.own(input.readString());
				data->_visible = input.readBoolean();
			}
			bones[i] = data;
		}

		/* Slots. */
		Vector<SlotData *> &slots = skeletonData->_slots.setSize(input.readInt(true), NULL);
		for (int i = 0; i < slots.size(); ++i) {
			String slotName = String(input.readString(), true);
			BoneData *boneData = bones[input.readInt(true)];
			SlotData *data = new (__FILE__, __LINE__) SlotData(i, slotName, *boneData);
			Color::rgba8888ToColor(data->_setup._color, input.readInt());

			int darkColor = input.readInt();
			if (darkColor != -1) {
				Color::rgb888ToColor(data->_setup._darkColor, darkColor);
				data->_setup._hasDarkColor = true;
			}

			data->_attachmentName = input.readStringRef();
			data->_blendMode = static_cast<BlendMode>(input.readInt(true));
			if (nonessential) data->_visible = input.readBoolean();
			slots[i] = data;
		}

		/* Constraints. */
		int constraintCount = input.readInt(true);
		Vector<ConstraintData *> &constraints = skeletonData->_constraints.setSize(constraintCount, NULL);
		for (int i = 0; i < constraintCount; i++) {
			String name(input.readString(), true);
			int nn;
			switch (input.readByte()) {
				case CONSTRAINT_IK: {
					IkConstraintData *data = new (__FILE__, __LINE__) IkConstraintData(name);
					Vector<BoneData *> &constraintBones = data->_bones.setSize(nn = input.readInt(true), NULL);
					for (int ii = 0; ii < nn; ii++)
						constraintBones[ii] = bones[input.readInt(true)];
					data->_target = bones[input.readInt(true)];
					int flags = input.read();
					data->_skinRequired = (flags & 1) != 0;
					data->_uniform = (flags & 2) != 0;
					IkConstraintPose &setup = data->_setup;
					setup._bendDirection = (flags & 4) != 0 ? 1 : -1;
					setup._compress = (flags & 8) != 0;
					setup._stretch = (flags & 16) != 0;
					if ((flags & 32) != 0) setup._mix = (flags & 64) != 0 ? input.readFloat() : 1;
					if ((flags & 128) != 0) setup._softness = input.readFloat() * _scale;
					constraints[i] = data;
					break;
				}
				case CONSTRAINT_TRANSFORM: {
					TransformConstraintData *data = new (__FILE__, __LINE__) TransformConstraintData(name);
					Vector<BoneData *> &constraintBones = data->_bones.setSize(nn = input.readInt(true), NULL);
					for (int ii = 0; ii < nn; ii++)
						constraintBones[ii] = bones[input.readInt(true)];
					data->_source = bones[input.readInt(true)];
					int flags = input.read();
					data->_skinRequired = (flags & 1) != 0;
					data->_localSource = (flags & 2) != 0;
					data->_localTarget = (flags & 4) != 0;
					data->_additive = (flags & 8) != 0;
					data->_clamp = (flags & 16) != 0;
					Vector<FromProperty *> &froms = data->_properties.setSize(nn = flags >> 5, NULL);
					for (int ii = 0, tn; ii < nn; ii++) {
						float fromScale = 1;
						FromProperty *from = NULL;
						switch (input.readByte()) {
							case 0:
								from = new (__FILE__, __LINE__) FromRotate();
								break;
							case 1:
								fromScale = _scale;
								from = new (__FILE__, __LINE__) FromX();
								break;
							case 2:
								fromScale = _scale;
								from = new (__FILE__, __LINE__) FromY();
								break;
							case 3:
								from = new (__FILE__, __LINE__) FromScaleX();
								break;
							case 4:
								from = new (__FILE__, __LINE__) FromScaleY();
								break;
							case 5:
								from = new (__FILE__, __LINE__) FromShearY();
								break;
						}
						from->_offset = input.readFloat() * fromScale;
						Vector<ToProperty *> &tos = from->_to.setSize(tn = input.readByte(), NULL);
						for (int t = 0; t < tn; t++) {
							float toScale = 1;
							ToProperty *to = NULL;
							switch (input.readByte()) {
								case 0:
									to = new (__FILE__, __LINE__) ToRotate();
									break;
								case 1:
									toScale = _scale;
									to = new (__FILE__, __LINE__) ToX();
									break;
								case 2:
									toScale = _scale;
									to = new (__FILE__, __LINE__) ToY();
									break;
								case 3:
									to = new (__FILE__, __LINE__) ToScaleX();
									break;
								case 4:
									to = new (__FILE__, __LINE__) ToScaleY();
									break;
								case 5:
									to = new (__FILE__, __LINE__) ToShearY();
									break;
							}
							to->_offset = input.readFloat() * toScale;
							to->_max = input.readFloat() * toScale;
							to->_scale = input.readFloat() * toScale / fromScale;
							tos[t] = to;
						}
						froms[ii] = from;
					}
					flags = input.read();
					if ((flags & 1) != 0) data->_offsets[TransformConstraintData::ROTATION] = input.readFloat();
					if ((flags & 2) != 0) data->_offsets[TransformConstraintData::X] = input.readFloat() * _scale;
					if ((flags & 4) != 0) data->_offsets[TransformConstraintData::Y] = input.readFloat() * _scale;
					if ((flags & 8) != 0) data->_offsets[TransformConstraintData::SCALEX] = input.readFloat();
					if ((flags & 16) != 0) data->_offsets[TransformConstraintData::SCALEY] = input.readFloat();
					if ((flags & 32) != 0) data->_offsets[TransformConstraintData::SHEARY] = input.readFloat();
					flags = input.read();
					TransformConstraintPose &setup = data->_setup;
					if ((flags & 1) != 0) setup._mixRotate = input.readFloat();
					if ((flags & 2) != 0) setup._mixX = input.readFloat();
					if ((flags & 4) != 0) setup._mixY = input.readFloat();
					if ((flags & 8) != 0) setup._mixScaleX = input.readFloat();
					if ((flags & 16) != 0) setup._mixScaleY = input.readFloat();
					if ((flags & 32) != 0) setup._mixShearY = input.readFloat();
					constraints[i] = data;
					break;
				}
				case CONSTRAINT_PATH: {
					PathConstraintData *data = new (__FILE__, __LINE__) PathConstraintData(name);
					Vector<BoneData *> &constraintBones = data->_bones.setSize(nn = input.readInt(true), NULL);
					for (int ii = 0; ii < nn; ii++)
						constraintBones[ii] = bones[input.readInt(true)];
					data->_slot = slots[input.readInt(true)];
					int flags = input.read();
					data->_skinRequired = (flags & 1) != 0;
					data->_positionMode = (PositionMode) ((flags >> 1) & 2);
					data->_spacingMode = (SpacingMode) ((flags >> 2) & 3);
					data->_rotateMode = (RotateMode) ((flags >> 4) & 3);
					if ((flags & 128) != 0) data->_offsetRotation = input.readFloat();
					PathConstraintPose &setup = data->_setup;
					setup._position = input.readFloat();
					if (data->_positionMode == PositionMode_Fixed) setup._position *= _scale;
					setup._spacing = input.readFloat();
					if (data->_spacingMode == SpacingMode_Length || data->_spacingMode == SpacingMode_Fixed) setup._spacing *= _scale;
					setup._mixRotate = input.readFloat();
					setup._mixX = input.readFloat();
					setup._mixY = input.readFloat();
					constraints[i] = data;
					break;
				}
				case CONSTRAINT_PHYSICS: {
					PhysicsConstraintData *data = new (__FILE__, __LINE__) PhysicsConstraintData(name);
					data->_bone = bones[input.readInt(true)];
					int flags = input.read();
					data->_skinRequired = (flags & 1) != 0;
					if ((flags & 2) != 0) data->_x = input.readFloat();
					if ((flags & 4) != 0) data->_y = input.readFloat();
					if ((flags & 8) != 0) data->_rotate = input.readFloat();
					if ((flags & 16) != 0) data->_scaleX = input.readFloat();
					if ((flags & 32) != 0) data->_shearX = input.readFloat();
					data->_limit = ((flags & 64) != 0 ? input.readFloat() : 5000) * _scale;
					data->_step = 1.f / input.readUnsignedByte();
					PhysicsConstraintPose &setup = data->getSetupPose();
					setup._inertia = input.readFloat();
					setup._strength = input.readFloat();
					setup._damping = input.readFloat();
					setup._massInverse = (flags & 128) != 0 ? input.readFloat() : 1;
					setup._wind = input.readFloat();
					setup._gravity = input.readFloat();
					flags = input.read();
					if ((flags & 1) != 0) data->_inertiaGlobal = true;
					if ((flags & 2) != 0) data->_strengthGlobal = true;
					if ((flags & 4) != 0) data->_dampingGlobal = true;
					if ((flags & 8) != 0) data->_massGlobal = true;
					if ((flags & 16) != 0) data->_windGlobal = true;
					if ((flags & 32) != 0) data->_gravityGlobal = true;
					if ((flags & 64) != 0) data->_mixGlobal = true;
					setup._mix = (flags & 128) != 0 ? input.readFloat() : 1;
					constraints[i] = data;
					break;
				}
				case CONSTRAINT_SLIDER: {
					SliderData *data = new (__FILE__, __LINE__) SliderData(name);
					int flags = input.read();
					data->_skinRequired = (flags & 1) != 0;
					data->_loop = (flags & 2) != 0;
					data->_additive = (flags & 4) != 0;
					SliderPose &setup = data->_setup;
					if ((flags & 8) != 0) setup._time = input.readFloat();
					if ((flags & 16) != 0) setup._mix = (flags & 32) != 0 ? input.readFloat() : 1;
					if ((flags & 64) != 0) {
						data->_local = (flags & 128) != 0;
						data->_bone = bones[input.readInt(true)];
						float offset = input.readFloat();
						float propertyScale = 1;
						switch (input.readByte()) {
							case 0:
								data->_property = new (__FILE__, __LINE__) FromRotate();
								break;
							case 1:
								propertyScale = _scale;
								data->_property = new (__FILE__, __LINE__) FromX();
								break;
							case 2:
								propertyScale = _scale;
								data->_property = new (__FILE__, __LINE__) FromY();
								break;
							case 3:
								data->_property = new (__FILE__, __LINE__) FromScaleX();
								break;
							case 4:
								data->_property = new (__FILE__, __LINE__) FromScaleY();
								break;
							case 5:
								data->_property = new (__FILE__, __LINE__) FromShearY();
								break;
							default:
								data->_property = NULL;
								break;
						}
						if(data->_property) data->_property->_offset = offset * propertyScale;
						data->_offset = input.readFloat();
						data->_scale = input.readFloat() / propertyScale;
					}
					constraints[i] = data;
					break;
				}
			}
		}

		/* Default skin. */
		Skin *defaultSkin = readSkin(input, skeletonData, true, nonessential);
		if (defaultSkin) {
			skeletonData->_defaultSkin = defaultSkin;
			skeletonData->_skins.add(defaultSkin);
		}

		if (!this->getError().isEmpty()) {
			delete skeletonData;
			return NULL;
		}

		/* Skins. */
		{
			int i = skeletonData->_skins.size();
			Vector<Skin *> &skins = skeletonData->_skins.setSize(n = i + input.readInt(true), NULL);
			for (; i < n; i++) {
				Skin *skin = readSkin(input, skeletonData, false, nonessential);
				if (skin)
					skins[i] = skin;
				else {
					delete skeletonData;
					return NULL;
				}
			}
		}

		/* Linked meshes. */
		Vector<LinkedMesh *> &items = _linkedMeshes;
		for (int i = 0, n = items.size(); i < n; i++) {
			LinkedMesh *linkedMesh = items[i];
			Skin *skin = skeletonData->_skins[linkedMesh->_skinIndex];
			Attachment *parent = skin->getAttachment(linkedMesh->_slotIndex, linkedMesh->_parent);
			if (parent == NULL) {
				delete skeletonData;
				setError("Parent mesh not found: ", linkedMesh->_parent.buffer());
				return NULL;
			}
			linkedMesh->_mesh->_timelineAttachment = linkedMesh->_inheritTimelines ? static_cast<VertexAttachment *>(parent)
																				   : linkedMesh->_mesh;
			linkedMesh->_mesh->setParentMesh(static_cast<MeshAttachment *>(parent));
			if (linkedMesh->_mesh->getSequence() == NULL) linkedMesh->_mesh->updateRegion();
			_attachmentLoader->configureAttachment(linkedMesh->_mesh);
		}
		ContainerUtil::cleanUpVectorOfPointers(_linkedMeshes);
		_linkedMeshes.clear();

		/* Events. */
		int eventsCount = input.readInt(true);
		Vector<EventData *> &events = skeletonData->_events.setSize(eventsCount, NULL);
		for (int i = 0; i < eventsCount; ++i) {
			EventData *eventData = new (__FILE__, __LINE__) EventData(String(input.readString(), true));
			eventData->_intValue = input.readInt(false);
			eventData->_floatValue = input.readFloat();
			eventData->_stringValue.own(input.readString());
			eventData->_audioPath.own(input.readString());
			if (!eventData->_audioPath.isEmpty()) {
				eventData->_volume = input.readFloat();
				eventData->_balance = input.readFloat();
			}
			events[i] = eventData;
		}

		/* Animations. */
		int animationsCount = input.readInt(true);
		Vector<Animation *> &animations = skeletonData->_animations.setSize(animationsCount, NULL);
		for (int i = 0; i < animationsCount; ++i) {
			Animation *animation = readAnimation(input, String(input.readString(), true), skeletonData);
			if (!animation) {
				delete skeletonData;
				return NULL;
			}
			skeletonData->_animations[i] = animation;
		}

		for (int i = 0; i < constraintCount; i++) {
			if (constraints[i]->getRTTI().instanceOf(SliderData::rtti)) {
				SliderData *data = static_cast<SliderData *>(constraints[i]);
				data->setAnimation(animations[input.readInt(true)]);
			}
		}
	}

	return skeletonData;
}

void SkeletonBinary::setError(const char *value1, const char *value2) {
	char message[256];
	int length;
	strcpy(message, value1);
	length = (int) strlen(value1);
	if (value2) strncat(message + length, value2, 255 - length);
	_error = String(message);
}

Skin *SkeletonBinary::readSkin(DataInput *input, SkeletonData *skeletonData, bool defaultSkin, bool nonessential) {
	Skin *skin;
	int slotCount = 0;
	if (defaultSkin) {
		slotCount = readVarint(input, true);
		if (slotCount == 0) return NULL;
		skin = new (__FILE__, __LINE__) Skin("default");
	} else {
		skin = new (__FILE__, __LINE__) Skin(String(readString(input), true));

		if (nonessential) readColor(input, skin->getColor());

		for (int i = 0, n = readVarint(input, true); i < n; i++) {
			int boneIndex = readVarint(input, true);
			if (boneIndex >= (int) skeletonData->_bones.size()) return NULL;
			skin->getBones().add(skeletonData->_bones[boneIndex]);
		}

		for (int i = 0, n = readVarint(input, true); i < n; i++) {
			int ikIndex = readVarint(input, true);
			if (ikIndex >= (int) skeletonData->_ikConstraints.size()) return NULL;
			skin->getConstraints().add(skeletonData->_ikConstraints[ikIndex]);
		}

		for (int i = 0, n = readVarint(input, true); i < n; i++) {
			int transformIndex = readVarint(input, true);
			if (transformIndex >= (int) skeletonData->_transformConstraints.size()) return NULL;
			skin->getConstraints().add(skeletonData->_transformConstraints[transformIndex]);
		}

		for (int i = 0, n = readVarint(input, true); i < n; i++) {
			int pathIndex = readVarint(input, true);
			if (pathIndex >= (int) skeletonData->_pathConstraints.size()) return NULL;
			skin->getConstraints().add(skeletonData->_pathConstraints[pathIndex]);
		}

		for (int i = 0, n = readVarint(input, true); i < n; i++) {
			int physicsIndex = readVarint(input, true);
			if (physicsIndex >= (int) skeletonData->_physicsConstraints.size()) return NULL;
			skin->getConstraints().add(skeletonData->_physicsConstraints[physicsIndex]);
		}
		slotCount = readVarint(input, true);
	}

	for (int i = 0; i < slotCount; ++i) {
		int slotIndex = readVarint(input, true);
		for (int ii = 0, nn = readVarint(input, true); ii < nn; ++ii) {
			String name(readStringRef(input, skeletonData));
			Attachment *attachment = readAttachment(input, skin, slotIndex, name, skeletonData, nonessential);
			if (attachment)
				skin->setAttachment(slotIndex, String(name), attachment);
			else {
				delete skin;
				return NULL;
			}
		}
	}
	return skin;
}

Sequence *SkeletonBinary::readSequence(DataInput *input) {
	Sequence *sequence = new (__FILE__, __LINE__) Sequence(readVarint(input, true));
	sequence->_start = readVarint(input, true);
	sequence->_digits = readVarint(input, true);
	sequence->_setupIndex = readVarint(input, true);
	return sequence;
}

Attachment *SkeletonBinary::readAttachment(DataInput *input, Skin *skin, int slotIndex, const String &attachmentName,
										   SkeletonData *skeletonData, bool nonessential) {

	int flags = readByte(input);
	String name = (flags & 8) != 0 ? readStringRef(input, skeletonData) : attachmentName;
	AttachmentType type = static_cast<AttachmentType>(flags & 0x7);
	switch (type) {
		case AttachmentType_Region: {
			String path = (flags & 16) != 0 ? readStringRef(input, skeletonData) : name;
			Color color(1, 1, 1, 1);
			if ((flags & 32) != 0) readColor(input, color);
			Sequence *sequence = (flags & 64) != 0 ? readSequence(input) : nullptr;
			float rotation = (flags & 128) != 0 ? readFloat(input) : 0;
			float x = readFloat(input) * _scale;
			float y = readFloat(input) * _scale;
			float scaleX = readFloat(input);
			float scaleY = readFloat(input);
			float width = readFloat(input) * _scale;
			float height = readFloat(input) * _scale;
			RegionAttachment *region = _attachmentLoader->newRegionAttachment(*skin, String(name), String(path), sequence);
			if (!region) {
				setError("Error reading attachment: ", name.buffer());
				return NULL;
			}
			region->_path = path;
			region->_rotation = rotation;
			region->_x = x;
			region->_y = y;
			region->_scaleX = scaleX;
			region->_scaleY = scaleY;
			region->_width = width;
			region->_height = height;
			region->getColor().set(color);
			region->_sequence = sequence;
			if (sequence == NULL) region->updateRegion();
			_attachmentLoader->configureAttachment(region);
			return region;
		}
		case AttachmentType_Boundingbox: {
			BoundingBoxAttachment *box = _attachmentLoader->newBoundingBoxAttachment(*skin, String(name));
			if (!box) {
				setError("Error reading attachment: ", name.buffer());
				return NULL;
			}
			int verticesLength = readVertices(input, box->getVertices(), box->getBones(), (flags & 16) != 0);
			box->setWorldVerticesLength(verticesLength);
			if (nonessential) {
				readColor(input, box->getColor());
			}
			_attachmentLoader->configureAttachment(box);
			return box;
		}
		case AttachmentType_Mesh: {
			Vector<float> uvs;
			Vector<unsigned short> triangles;
			Vector<float> vertices;
			Vector<int> bones;
			int hullLength;
			float width = 0;
			float height = 0;
			Vector<unsigned short> edges;

			String path = (flags & 16) != 0 ? readStringRef(input, skeletonData) : name;
			Color color(1, 1, 1, 1);
			if ((flags & 32) != 0) readColor(input, color);
			Sequence *sequence = (flags & 64) != 0 ? readSequence(input) : nullptr;
			hullLength = readVarint(input, true);
			int verticesLength = readVertices(input, vertices, bones, (flags & 128) != 0);
			readFloatArray(input, verticesLength, 1, uvs);
			readShortArray(input, triangles, (verticesLength - hullLength - 2) * 3);

			if (nonessential) {
				readShortArray(input, edges, readVarint(input, true));
				width = readFloat(input);
				height = readFloat(input);
			}

			MeshAttachment *mesh = _attachmentLoader->newMeshAttachment(*skin, String(name), String(path), sequence);
			if (!mesh) {
				setError("Error reading attachment: ", name.buffer());
				return NULL;
			}
			mesh->_path = path;
			mesh->_color.set(color);
			mesh->_bones.addAll(bones);
			mesh->_vertices.addAll(vertices);
			mesh->setWorldVerticesLength(verticesLength);
			mesh->_triangles.addAll(triangles);
			mesh->_regionUVs.addAll(uvs);
			if (sequence == NULL) mesh->updateRegion();
			mesh->_hullLength = hullLength;
			mesh->_sequence = sequence;
			if (nonessential) {
				mesh->_edges.addAll(edges);
				mesh->_width = width;
				mesh->_height = height;
			}
			_attachmentLoader->configureAttachment(mesh);
			return mesh;
		}
		case AttachmentType_Linkedmesh: {
			String path = (flags & 16) != 0 ? readStringRef(input, skeletonData) : name;
			Color color(1, 1, 1, 1);
			if ((flags & 32) != 0) readColor(input, color);
			Sequence *sequence = (flags & 64) != 0 ? readSequence(input) : nullptr;
			bool inheritTimelines = (flags & 128) != 0;
			int skinIndex = readVarint(input, true);
			String parent(readStringRef(input, skeletonData));
			float width = 0, height = 0;
			if (nonessential) {
				width = readFloat(input) * _scale;
				height = readFloat(input) * _scale;
			}

			MeshAttachment *mesh = _attachmentLoader->newMeshAttachment(*skin, String(name), String(path), sequence);
			if (!mesh) {
				setError("Error reading attachment: ", name.buffer());
				return NULL;
			}
			mesh->_path = path;
			mesh->_color.set(color);
			mesh->_sequence = sequence;
			if (nonessential) {
				mesh->_width = width;
				mesh->_height = height;
			}

			LinkedMesh *linkedMesh = new (__FILE__, __LINE__) LinkedMesh(mesh, skinIndex, slotIndex,
																		 String(parent), inheritTimelines);
			_linkedMeshes.add(linkedMesh);
			return mesh;
		}
		case AttachmentType_Path: {
			PathAttachment *path = _attachmentLoader->newPathAttachment(*skin, String(name));
			if (!path) {
				setError("Error reading attachment: ", name.buffer());
				return NULL;
			}
			path->_closed = (flags & 16) != 0;
			path->_constantSpeed = (flags & 32) != 0;
			int verticesLength = readVertices(input, path->getVertices(), path->getBones(), (flags & 64) != 0);
			path->setWorldVerticesLength(verticesLength);
			int lengthsLength = verticesLength / 6;
			path->_lengths.setSize(lengthsLength, 0);
			for (int i = 0; i < lengthsLength; ++i) {
				path->_lengths[i] = readFloat(input) * _scale;
			}
			if (nonessential) {
				readColor(input, path->getColor());
			}
			_attachmentLoader->configureAttachment(path);
			return path;
		}
		case AttachmentType_Point: {
			PointAttachment *point = _attachmentLoader->newPointAttachment(*skin, String(name));
			if (!point) {
				setError("Error reading attachment: ", name.buffer());
				return NULL;
			}
			point->_rotation = readFloat(input);
			point->_x = readFloat(input) * _scale;
			point->_y = readFloat(input) * _scale;

			if (nonessential) {
				readColor(input, point->getColor());
			}
			_attachmentLoader->configureAttachment(point);
			return point;
		}
		case AttachmentType_Clipping: {
			int endSlotIndex = readVarint(input, true);
			ClippingAttachment *clip = _attachmentLoader->newClippingAttachment(*skin, name);
			if (!clip) {
				setError("Error reading attachment: ", name.buffer());
				return NULL;
			}
			int verticesLength = readVertices(input, clip->getVertices(), clip->getBones(), (flags & 16) != 0);
			clip->setWorldVerticesLength(verticesLength);
			clip->_endSlot = skeletonData->_slots[endSlotIndex];
			if (nonessential) {
				readColor(input, clip->getColor());
			}
			_attachmentLoader->configureAttachment(clip);
			return clip;
		}
	}
	return NULL;
}

int SkeletonBinary::readVertices(DataInput *input, Vector<float> &vertices, Vector<int> &bones, bool weighted) {
	float scale = _scale;
	int vertexCount = readVarint(input, true);
	int verticesLength = vertexCount << 1;
	if (!weighted) {
		readFloatArray(input, verticesLength, scale, vertices);
		return verticesLength;
	}
	vertices.ensureCapacity(verticesLength * 3 * 3);
	bones.ensureCapacity(verticesLength * 3);
	for (int i = 0; i < vertexCount; ++i) {
		int boneCount = readVarint(input, true);
		bones.add(boneCount);
		for (int ii = 0; ii < boneCount; ++ii) {
			bones.add(readVarint(input, true));
			vertices.add(readFloat(input) * scale);
			vertices.add(readFloat(input) * scale);
			vertices.add(readFloat(input));
		}
	}
	return verticesLength;
}

void SkeletonBinary::readFloatArray(DataInput *input, int n, float scale, Vector<float> &array) {
	array.setSize(n, 0);

	int i;
	if (scale == 1) {
		for (i = 0; i < n; ++i) {
			array[i] = readFloat(input);
		}
	} else {
		for (i = 0; i < n; ++i) {
			array[i] = readFloat(input) * scale;
		}
	}
}

void SkeletonBinary::readShortArray(DataInput *input, Vector<unsigned short> &array, int n) {
	array.setSize(n, 0);
	for (int i = 0; i < n; ++i) {
		array[i] = (short) readVarint(input, true);
	}
}

void SkeletonBinary::setBezier(DataInput *input, CurveTimeline *timeline, int bezier, int frame, int value, float time1,
							   float time2,
							   float value1, float value2, float scale) {
	float cx1 = readFloat(input);
	float cy1 = readFloat(input);
	float cx2 = readFloat(input);
	float cy2 = readFloat(input);
	timeline->setBezier(bezier, frame, value, time1, value1, cx1, cy1 * scale, cx2, cy2 * scale, time2, value2);
}

void SkeletonBinary::readTimeline(DataInput *input, Vector<Timeline *> &timelines, CurveTimeline1 *timeline, float scale) {
	float time = readFloat(input);
	float value = readFloat(input) * scale;
	for (int frame = 0, bezier = 0, frameLast = (int) timeline->getFrameCount() - 1;; frame++) {
		timeline->setFrame(frame, time, value);
		if (frame == frameLast) break;
		float time2 = readFloat(input);
		float value2 = readFloat(input) * scale;
		switch (readSByte(input)) {
			case CURVE_STEPPED:
				timeline->setStepped(frame);
				break;
			case CURVE_BEZIER:
				setBezier(input, timeline, bezier++, frame, 0, time, time2, value, value2, scale);
		}
		time = time2;
		value = value2;
	}
	timelines.add(timeline);
}

void SkeletonBinary::readTimeline2(DataInput *input, Vector<Timeline *> &timelines, CurveTimeline2 *timeline, float scale) {
	float time = readFloat(input);
	float value1 = readFloat(input) * scale;
	float value2 = readFloat(input) * scale;
	for (int frame = 0, bezier = 0, frameLast = (int) timeline->getFrameCount() - 1;; frame++) {
		timeline->setFrame(frame, time, value1, value2);
		if (frame == frameLast) break;
		float time2 = readFloat(input);
		float nvalue1 = readFloat(input) * scale;
		float nvalue2 = readFloat(input) * scale;
		switch (readSByte(input)) {
			case CURVE_STEPPED:
				timeline->setStepped(frame);
				break;
			case CURVE_BEZIER:
				setBezier(input, timeline, bezier++, frame, 0, time, time2, value1, nvalue1, scale);
				setBezier(input, timeline, bezier++, frame, 1, time, time2, value2, nvalue2, scale);
		}
		time = time2;
		value1 = nvalue1;
		value2 = nvalue2;
	}
	timelines.add(timeline);
}

Animation *SkeletonBinary::readAnimation(DataInput *input, const String &name, SkeletonData *skeletonData) {
	Vector<Timeline *> timelines;
	float scale = _scale;
	int numTimelines = readVarint(input, true);
	SP_UNUSED(numTimelines);
	// Slot timelines.
	for (int i = 0, n = readVarint(input, true); i < n; ++i) {
		int slotIndex = readVarint(input, true);
		for (int ii = 0, nn = readVarint(input, true); ii < nn; ++ii) {
			unsigned char timelineType = readByte(input);
			int frameCount = readVarint(input, true);
			int frameLast = frameCount - 1;
			switch (timelineType) {
				case SLOT_ATTACHMENT: {
					AttachmentTimeline *timeline = new (__FILE__, __LINE__) AttachmentTimeline(frameCount, slotIndex);
					for (int frame = 0; frame < frameCount; ++frame) {
						float time = readFloat(input);
						String attachmentName(readStringRef(input, skeletonData));
						timeline->setFrame(frame, time, attachmentName);
					}
					timelines.add(timeline);
					break;
				}
				case SLOT_RGBA: {
					int bezierCount = readVarint(input, true);
					RGBATimeline *timeline = new (__FILE__, __LINE__) RGBATimeline(frameCount, bezierCount, slotIndex);

					float time = readFloat(input);
					float r = readByte(input) / 255.0;
					float g = readByte(input) / 255.0;
					float b = readByte(input) / 255.0;
					float a = readByte(input) / 255.0;

					for (int frame = 0, bezier = 0;; frame++) {
						timeline->setFrame(frame, time, r, g, b, a);
						if (frame == frameLast) break;

						float time2 = readFloat(input);
						float r2 = readByte(input) / 255.0;
						float g2 = readByte(input) / 255.0;
						float b2 = readByte(input) / 255.0;
						float a2 = readByte(input) / 255.0;

						switch (readSByte(input)) {
							case CURVE_STEPPED:
								timeline->setStepped(frame);
								break;
							case CURVE_BEZIER:
								setBezier(input, timeline, bezier++, frame, 0, time, time2, r, r2, 1);
								setBezier(input, timeline, bezier++, frame, 1, time, time2, g, g2, 1);
								setBezier(input, timeline, bezier++, frame, 2, time, time2, b, b2, 1);
								setBezier(input, timeline, bezier++, frame, 3, time, time2, a, a2, 1);
						}
						time = time2;
						r = r2;
						g = g2;
						b = b2;
						a = a2;
					}
					timelines.add(timeline);
					break;
				}
				case SLOT_RGB: {
					int bezierCount = readVarint(input, true);
					RGBTimeline *timeline = new (__FILE__, __LINE__) RGBTimeline(frameCount, bezierCount, slotIndex);

					float time = readFloat(input);
					float r = readByte(input) / 255.0;
					float g = readByte(input) / 255.0;
					float b = readByte(input) / 255.0;

					for (int frame = 0, bezier = 0;; frame++) {
						timeline->setFrame(frame, time, r, g, b);
						if (frame == frameLast) break;

						float time2 = readFloat(input);
						float r2 = readByte(input) / 255.0;
						float g2 = readByte(input) / 255.0;
						float b2 = readByte(input) / 255.0;

						switch (readSByte(input)) {
							case CURVE_STEPPED:
								timeline->setStepped(frame);
								break;
							case CURVE_BEZIER:
								setBezier(input, timeline, bezier++, frame, 0, time, time2, r, r2, 1);
								setBezier(input, timeline, bezier++, frame, 1, time, time2, g, g2, 1);
								setBezier(input, timeline, bezier++, frame, 2, time, time2, b, b2, 1);
						}
						time = time2;
						r = r2;
						g = g2;
						b = b2;
					}
					timelines.add(timeline);
					break;
				}
				case SLOT_RGBA2: {
					int bezierCount = readVarint(input, true);
					RGBA2Timeline *timeline = new (__FILE__, __LINE__) RGBA2Timeline(frameCount, bezierCount, slotIndex);

					float time = readFloat(input);
					float r = readByte(input) / 255.0;
					float g = readByte(input) / 255.0;
					float b = readByte(input) / 255.0;
					float a = readByte(input) / 255.0;
					float r2 = readByte(input) / 255.0;
					float g2 = readByte(input) / 255.0;
					float b2 = readByte(input) / 255.0;

					for (int frame = 0, bezier = 0;; frame++) {
						timeline->setFrame(frame, time, r, g, b, a, r2, g2, b2);
						if (frame == frameLast) break;
						float time2 = readFloat(input);
						float nr = readByte(input) / 255.0;
						float ng = readByte(input) / 255.0;
						float nb = readByte(input) / 255.0;
						float na = readByte(input) / 255.0;
						float nr2 = readByte(input) / 255.0;
						float ng2 = readByte(input) / 255.0;
						float nb2 = readByte(input) / 255.0;

						switch (readSByte(input)) {
							case CURVE_STEPPED:
								timeline->setStepped(frame);
								break;
							case CURVE_BEZIER:
								setBezier(input, timeline, bezier++, frame, 0, time, time2, r, nr, 1);
								setBezier(input, timeline, bezier++, frame, 1, time, time2, g, ng, 1);
								setBezier(input, timeline, bezier++, frame, 2, time, time2, b, nb, 1);
								setBezier(input, timeline, bezier++, frame, 3, time, time2, a, na, 1);
								setBezier(input, timeline, bezier++, frame, 4, time, time2, r2, nr2, 1);
								setBezier(input, timeline, bezier++, frame, 5, time, time2, g2, ng2, 1);
								setBezier(input, timeline, bezier++, frame, 6, time, time2, b2, nb2, 1);
						}
						time = time2;
						r = nr;
						g = ng;
						b = nb;
						a = na;
						r2 = nr2;
						g2 = ng2;
						b2 = nb2;
					}
					timelines.add(timeline);
					break;
				}
				case SLOT_RGB2: {
					int bezierCount = readVarint(input, true);
					RGB2Timeline *timeline = new (__FILE__, __LINE__) RGB2Timeline(frameCount, bezierCount, slotIndex);

					float time = readFloat(input);
					float r = readByte(input) / 255.0;
					float g = readByte(input) / 255.0;
					float b = readByte(input) / 255.0;
					float r2 = readByte(input) / 255.0;
					float g2 = readByte(input) / 255.0;
					float b2 = readByte(input) / 255.0;

					for (int frame = 0, bezier = 0;; frame++) {
						timeline->setFrame(frame, time, r, g, b, r2, g2, b2);
						if (frame == frameLast) break;
						float time2 = readFloat(input);
						float nr = readByte(input) / 255.0;
						float ng = readByte(input) / 255.0;
						float nb = readByte(input) / 255.0;
						float nr2 = readByte(input) / 255.0;
						float ng2 = readByte(input) / 255.0;
						float nb2 = readByte(input) / 255.0;

						switch (readSByte(input)) {
							case CURVE_STEPPED:
								timeline->setStepped(frame);
								break;
							case CURVE_BEZIER:
								setBezier(input, timeline, bezier++, frame, 0, time, time2, r, nr, 1);
								setBezier(input, timeline, bezier++, frame, 1, time, time2, g, ng, 1);
								setBezier(input, timeline, bezier++, frame, 2, time, time2, b, nb, 1);
								setBezier(input, timeline, bezier++, frame, 3, time, time2, r2, nr2, 1);
								setBezier(input, timeline, bezier++, frame, 4, time, time2, g2, ng2, 1);
								setBezier(input, timeline, bezier++, frame, 5, time, time2, b2, nb2, 1);
						}
						time = time2;
						r = nr;
						g = ng;
						b = nb;
						r2 = nr2;
						g2 = ng2;
						b2 = nb2;
					}
					timelines.add(timeline);
					break;
				}
				case SLOT_ALPHA: {
					int bezierCount = readVarint(input, true);
					AlphaTimeline *timeline = new (__FILE__, __LINE__) AlphaTimeline(frameCount, bezierCount, slotIndex);
					float time = readFloat(input);
					float a = readByte(input) / 255.0;
					for (int frame = 0, bezier = 0;; frame++) {
						timeline->setFrame(frame, time, a);
						if (frame == frameLast) break;
						float time2 = readFloat(input);
						float a2 = readByte(input) / 255.0;
						switch (readSByte(input)) {
							case CURVE_STEPPED:
								timeline->setStepped(frame);
								break;
							case CURVE_BEZIER:
								setBezier(input, timeline, bezier++, frame, 0, time, time2, a, a2, 1);
						}
						time = time2;
						a = a2;
					}
					timelines.add(timeline);
					break;
				}
				default: {
					ContainerUtil::cleanUpVectorOfPointers(timelines);
					setError("Invalid timeline type for a slot: ", skeletonData->_slots[slotIndex]->_name.buffer());
					return NULL;
				}
			}
		}
	}

	// Bone timelines.
	for (int i = 0, n = readVarint(input, true); i < n; ++i) {
		int boneIndex = readVarint(input, true);
		for (int ii = 0, nn = readVarint(input, true); ii < nn; ++ii) {
			unsigned char timelineType = readByte(input);
			int frameCount = readVarint(input, true);
			if (timelineType == BONE_INHERIT) {
				InheritTimeline *timeline = new (__FILE__, __LINE__) InheritTimeline(frameCount, boneIndex);
				for (int frame = 0; frame < frameCount; frame++) {
					float time = readFloat(input);
					Inherit inherit = (Inherit) readByte(input);
					timeline->setFrame(frame, time, inherit);
				}
				timelines.add(timeline);
				continue;
			}
			int bezierCount = readVarint(input, true);
			switch (timelineType) {
				case BONE_ROTATE:
					readTimeline(input, timelines,
								 new (__FILE__, __LINE__) RotateTimeline(frameCount, bezierCount, boneIndex),
								 1);
					break;
				case BONE_TRANSLATE:
					readTimeline2(input, timelines, new (__FILE__, __LINE__) TranslateTimeline(frameCount, bezierCount, boneIndex), scale);
					break;
				case BONE_TRANSLATEX:
					readTimeline(input, timelines, new (__FILE__, __LINE__) TranslateXTimeline(frameCount, bezierCount, boneIndex), scale);
					break;
				case BONE_TRANSLATEY:
					readTimeline(input, timelines, new (__FILE__, __LINE__) TranslateYTimeline(frameCount, bezierCount, boneIndex), scale);
					break;
				case BONE_SCALE:
					readTimeline2(input, timelines,
								  new (__FILE__, __LINE__) ScaleTimeline(frameCount, bezierCount, boneIndex),
								  1);
					break;
				case BONE_SCALEX:
					readTimeline(input, timelines,
								 new (__FILE__, __LINE__) ScaleXTimeline(frameCount, bezierCount, boneIndex),
								 1);
					break;
				case BONE_SCALEY:
					readTimeline(input, timelines,
								 new (__FILE__, __LINE__) ScaleYTimeline(frameCount, bezierCount, boneIndex),
								 1);
					break;
				case BONE_SHEAR:
					readTimeline2(input, timelines,
								  new (__FILE__, __LINE__) ShearTimeline(frameCount, bezierCount, boneIndex),
								  1);
					break;
				case BONE_SHEARX:
					readTimeline(input, timelines,
								 new (__FILE__, __LINE__) ShearXTimeline(frameCount, bezierCount, boneIndex),
								 1);
					break;
				case BONE_SHEARY:
					readTimeline(input, timelines,
								 new (__FILE__, __LINE__) ShearYTimeline(frameCount, bezierCount, boneIndex),
								 1);
					break;
				default: {
					ContainerUtil::cleanUpVectorOfPointers(timelines);
					setError("Invalid timeline type for a bone: ", skeletonData->_bones[boneIndex]->_name.buffer());
					return NULL;
				}
			}
		}
	}

	// IK timelines.
	for (int i = 0, n = readVarint(input, true); i < n; ++i) {
		int index = readVarint(input, true);
		int frameCount = readVarint(input, true);
		int frameLast = frameCount - 1;
		int bezierCount = readVarint(input, true);
		IkConstraintTimeline *timeline = new (__FILE__, __LINE__) IkConstraintTimeline(frameCount, bezierCount, index);
		int flags = readByte(input);
		float time = readFloat(input), mix = (flags & 1) != 0 ? ((flags & 2) != 0 ? readFloat(input) : 1) : 0;
		float softness = (flags & 4) != 0 ? readFloat(input) * scale : 0;
		for (int frame = 0, bezier = 0;; frame++) {
			timeline->setFrame(frame, time, mix, softness, (flags & 8) != 0 ? 1 : -1, (flags & 16) != 0, (flags & 32) != 0);
			if (frame == frameLast) break;
			flags = readByte(input);
			float time2 = readFloat(input), mix2 = (flags & 1) != 0 ? ((flags & 2) != 0 ? readFloat(input) : 1) : 0;
			float softness2 = (flags & 4) != 0 ? readFloat(input) * scale : 0;
			if ((flags & 64) != 0)
				timeline->setStepped(frame);
			else if ((flags & 128) != 0) {
				setBezier(input, timeline, bezier++, frame, 0, time, time2, mix, mix2, 1);
				setBezier(input, timeline, bezier++, frame, 1, time, time2, softness, softness2, scale);
			}
			time = time2;
			mix = mix2;
			softness = softness2;
		}
		timelines.add(timeline);
	}

	// Transform constraint timelines.
	for (int i = 0, n = readVarint(input, true); i < n; ++i) {
		int index = readVarint(input, true);
		int frameCount = readVarint(input, true);
		int frameLast = frameCount - 1;
		int bezierCount = readVarint(input, true);
		TransformConstraintTimeline *timeline = new TransformConstraintTimeline(frameCount, bezierCount, index);
		float time = readFloat(input);
		float mixRotate = readFloat(input);
		float mixX = readFloat(input);
		float mixY = readFloat(input);
		float mixScaleX = readFloat(input);
		float mixScaleY = readFloat(input);
		float mixShearY = readFloat(input);
		for (int frame = 0, bezier = 0;; frame++) {
			timeline->setFrame(frame, time, mixRotate, mixX, mixY, mixScaleX, mixScaleY, mixShearY);
			if (frame == frameLast) break;
			float time2 = readFloat(input);
			float mixRotate2 = readFloat(input);
			float mixX2 = readFloat(input);
			float mixY2 = readFloat(input);
			float mixScaleX2 = readFloat(input);
			float mixScaleY2 = readFloat(input);
			float mixShearY2 = readFloat(input);
			switch (readSByte(input)) {
				case CURVE_STEPPED:
					timeline->setStepped(frame);
					break;
				case CURVE_BEZIER:
					setBezier(input, timeline, bezier++, frame, 0, time, time2, mixRotate, mixRotate2, 1);
					setBezier(input, timeline, bezier++, frame, 1, time, time2, mixX, mixX2, 1);
					setBezier(input, timeline, bezier++, frame, 2, time, time2, mixY, mixY2, 1);
					setBezier(input, timeline, bezier++, frame, 3, time, time2, mixScaleX, mixScaleX2, 1);
					setBezier(input, timeline, bezier++, frame, 4, time, time2, mixScaleY, mixScaleY2, 1);
					setBezier(input, timeline, bezier++, frame, 5, time, time2, mixShearY, mixShearY2, 1);
			}
			time = time2;
			mixRotate = mixRotate2;
			mixX = mixX2;
			mixY = mixY2;
			mixScaleX = mixScaleX2;
			mixScaleY = mixScaleY2;
			mixShearY = mixShearY2;
		}
		timelines.add(timeline);
	}

	// Path constraint timelines.
	for (int i = 0, n = readVarint(input, true); i < n; ++i) {
		int index = readVarint(input, true);
		PathConstraintData *data = skeletonData->_pathConstraints[index];
		for (int ii = 0, nn = readVarint(input, true); ii < nn; ii++) {
			int type = readByte(input);
			int frameCount = readVarint(input, true);
			int bezierCount = readVarint(input, true);
			switch (type) {
				case PATH_POSITION: {
					readTimeline(input, timelines, new PathConstraintPositionTimeline(frameCount, bezierCount, index),
								 data->_positionMode == PositionMode_Fixed ? scale : 1);
					break;
				}
				case PATH_SPACING: {
					readTimeline(input, timelines,
								 new PathConstraintSpacingTimeline(frameCount,
																   bezierCount,
																   index),
								 data->_spacingMode == SpacingMode_Length ||
												 data->_spacingMode == SpacingMode_Fixed
										 ? scale
										 : 1);
					break;
				}
				case PATH_MIX:
					PathConstraintMixTimeline *timeline = new PathConstraintMixTimeline(frameCount, bezierCount, index);
					float time = readFloat(input);
					float mixRotate = readFloat(input);
					float mixX = readFloat(input);
					float mixY = readFloat(input);
					for (int frame = 0, bezier = 0, frameLast = (int) timeline->getFrameCount() - 1;; frame++) {
						timeline->setFrame(frame, time, mixRotate, mixX, mixY);
						if (frame == frameLast) break;
						float time2 = readFloat(input);
						float mixRotate2 = readFloat(input);
						float mixX2 = readFloat(input);
						float mixY2 = readFloat(input);
						switch (readSByte(input)) {
							case CURVE_STEPPED:
								timeline->setStepped(frame);
								break;
							case CURVE_BEZIER:
								setBezier(input, timeline, bezier++, frame, 0, time, time2, mixRotate, mixRotate2, 1);
								setBezier(input, timeline, bezier++, frame, 1, time, time2, mixX, mixX2, 1);
								setBezier(input, timeline, bezier++, frame, 2, time, time2, mixY, mixY2, 1);
						}
						time = time2;
						mixRotate = mixRotate2;
						mixX = mixX2;
						mixY = mixY2;
					}
					timelines.add(timeline);
			}
		}
	}

	// Physics timelines.
	for (int i = 0, n = readVarint(input, true); i < n; i++) {
		int index = readVarint(input, true) - 1;
		for (int ii = 0, nn = readVarint(input, true); ii < nn; ii++) {
			int type = readByte(input);
			int frameCount = readVarint(input, true);
			if (type == PHYSICS_RESET) {
				PhysicsConstraintResetTimeline *timeline = new (__FILE__, __LINE__) PhysicsConstraintResetTimeline(frameCount, index);
				for (int frame = 0; frame < frameCount; frame++)
					timeline->setFrame(frame, readFloat(input));
				timelines.add(timeline);
				continue;
			}
			int bezierCount = readVarint(input, true);
			switch (type) {
				case PHYSICS_INERTIA:
					readTimeline(input, timelines, new PhysicsConstraintInertiaTimeline(frameCount, bezierCount, index), 1);
					break;
				case PHYSICS_STRENGTH:
					readTimeline(input, timelines, new PhysicsConstraintStrengthTimeline(frameCount, bezierCount, index), 1);
					break;
				case PHYSICS_DAMPING:
					readTimeline(input, timelines, new PhysicsConstraintDampingTimeline(frameCount, bezierCount, index), 1);
					break;
				case PHYSICS_MASS:
					readTimeline(input, timelines, new PhysicsConstraintMassTimeline(frameCount, bezierCount, index), 1);
					break;
				case PHYSICS_WIND:
					readTimeline(input, timelines, new PhysicsConstraintWindTimeline(frameCount, bezierCount, index), 1);
					break;
				case PHYSICS_GRAVITY:
					readTimeline(input, timelines, new PhysicsConstraintGravityTimeline(frameCount, bezierCount, index), 1);
					break;
				case PHYSICS_MIX:
					readTimeline(input, timelines, new PhysicsConstraintMixTimeline(frameCount, bezierCount, index), 1);
			}
		}
	}

	// Attachment timelines.
	for (int i = 0, n = readVarint(input, true); i < n; ++i) {
		Skin *skin = skeletonData->_skins[readVarint(input, true)];
		for (int ii = 0, nn = readVarint(input, true); ii < nn; ++ii) {
			int slotIndex = readVarint(input, true);
			for (int iii = 0, nnn = readVarint(input, true); iii < nnn; iii++) {
				const char *attachmentName = readStringRef(input, skeletonData);
				Attachment *baseAttachment = skin->getAttachment(slotIndex, String(attachmentName));
				if (!baseAttachment) {
					ContainerUtil::cleanUpVectorOfPointers(timelines);
					setError("Attachment not found: ", attachmentName);
					return NULL;
				}
				unsigned int timelineType = readByte(input);
				int frameCount = readVarint(input, true);
				int frameLast = frameCount - 1;

				switch (timelineType) {
					case ATTACHMENT_DEFORM: {
						VertexAttachment *attachment = static_cast<VertexAttachment *>(baseAttachment);
						bool weighted = attachment->_bones.size() > 0;
						Vector<float> &vertices = attachment->_vertices;
						int deformLength = weighted ? (int) vertices.size() / 3 * 2 : (int) vertices.size();

						int bezierCount = readVarint(input, true);
						DeformTimeline *timeline = new (__FILE__, __LINE__) DeformTimeline(frameCount, bezierCount, slotIndex,
																						   attachment);

						float time = readFloat(input);
						for (int frame = 0, bezier = 0;; ++frame) {
							Vector<float> deform;
							size_t end = (size_t) readVarint(input, true);
							if (end == 0) {
								if (weighted) {
									deform.setSize(deformLength, 0);
									for (int iiii = 0; iiii < deformLength; ++iiii)
										deform[iiii] = 0;
								} else {
									deform.clearAndAddAll(vertices);
								}
							} else {
								deform.setSize(deformLength, 0);
								size_t start = (size_t) readVarint(input, true);
								end += start;
								if (scale == 1) {
									for (size_t v = start; v < end; ++v)
										deform[v] = readFloat(input);
								} else {
									for (size_t v = start; v < end; ++v)
										deform[v] = readFloat(input) * scale;
								}

								if (!weighted) {
									for (size_t v = 0, vn = deform.size(); v < vn; ++v)
										deform[v] += vertices[v];
								}
							}

							timeline->setFrame(frame, time, deform);
							if (frame == frameLast) break;
							float time2 = readFloat(input);
							switch (readSByte(input)) {
								case CURVE_STEPPED:
									timeline->setStepped(frame);
									break;
								case CURVE_BEZIER:
									setBezier(input, timeline, bezier++, frame, 0, time, time2, 0, 1, 1);
							}
							time = time2;
						}

						timelines.add(timeline);
						break;
					}
					case ATTACHMENT_SEQUENCE: {
						SequenceTimeline *timeline = new (__FILE__, __LINE__) SequenceTimeline(frameCount, slotIndex, baseAttachment);
						for (int frame = 0; frame < frameCount; frame++) {
							float time = readFloat(input);
							int modeAndIndex = readInt(input);
							float delay = readFloat(input);
							timeline->setFrame(frame, time, (spine::SequenceMode)(modeAndIndex & 0xf), modeAndIndex >> 4, delay);
						}
						timelines.add(timeline);
						break;
					}
				}
			}
		}
	}

	// Draw order timeline.
	size_t drawOrderCount = (size_t) readVarint(input, true);
	if (drawOrderCount > 0) {
		DrawOrderTimeline *timeline = new (__FILE__, __LINE__) DrawOrderTimeline(drawOrderCount);

		size_t slotCount = skeletonData->_slots.size();
		for (size_t i = 0; i < drawOrderCount; ++i) {
			float time = readFloat(input);
			size_t offsetCount = (size_t) readVarint(input, true);

			Vector<int> drawOrder;
			drawOrder.setSize(slotCount, 0);
			for (int ii = (int) slotCount - 1; ii >= 0; --ii)
				drawOrder[ii] = -1;

			Vector<int> unchanged;
			unchanged.setSize(slotCount - offsetCount, 0);
			size_t originalIndex = 0, unchangedIndex = 0;
			for (size_t ii = 0; ii < offsetCount; ++ii) {
				size_t slotIndex = (size_t) readVarint(input, true);
				// Collect unchanged items.
				while (originalIndex != slotIndex)
					unchanged[unchangedIndex++] = (int) originalIndex++;
				// Set changed items.
				size_t index = originalIndex;
				drawOrder[index + (size_t) readVarint(input, true)] = (int) originalIndex++;
			}

			// Collect remaining unchanged items.
			while (originalIndex < slotCount) {
				unchanged[unchangedIndex++] = (int) originalIndex++;
			}

			// Fill in unchanged items.
			for (int ii = (int) slotCount - 1; ii >= 0; --ii)
				if (drawOrder[ii] == -1) drawOrder[ii] = unchanged[--unchangedIndex];
			timeline->setFrame(i, time, drawOrder);
		}
		timelines.add(timeline);
	}

	// Event timeline.
	int eventCount = readVarint(input, true);
	if (eventCount > 0) {
		EventTimeline *timeline = new (__FILE__, __LINE__) EventTimeline(eventCount);

		for (int i = 0; i < eventCount; ++i) {
			float time = readFloat(input);
			EventData *eventData = skeletonData->_events[readVarint(input, true)];
			Event *event = new (__FILE__, __LINE__) Event(time, *eventData);

			event->_intValue = readVarint(input, false);
			event->_floatValue = readFloat(input);
			const char *event_stringValue = readString(input);
			if (event_stringValue == nullptr) {
				event->_stringValue = eventData->_stringValue;
			} else {
				event->_stringValue = String(event_stringValue);
				SpineExtension::free(event_stringValue, __FILE__, __LINE__);
			}

			if (!eventData->_audioPath.isEmpty()) {
				event->_volume = readFloat(input);
				event->_balance = readFloat(input);
			}
			timeline->setFrame(i, event);
		}
		timelines.add(timeline);
	}

	float duration = 0;
	for (int i = 0, n = (int) timelines.size(); i < n; i++) {
		duration = MathUtil::max(duration, (timelines[i])->getDuration());
	}
	return new (__FILE__, __LINE__) Animation(String(name), timelines, duration);
}
