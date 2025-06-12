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

#include <spine/Skeleton.h>
#include <spine/SkeletonData.h>
#include <spine/BoneData.h>
#include <spine/SlotData.h>
#include <spine/ConstraintData.h>
#include <spine/PhysicsConstraintData.h>
#include <spine/IkConstraintData.h>
#include <spine/PathConstraintData.h>
#include <spine/TransformConstraintData.h>
#include <spine/Bone.h>
#include <spine/Slot.h>
#include <spine/IkConstraint.h>
#include <spine/PathConstraint.h>
#include <spine/PhysicsConstraint.h>
#include <spine/TransformConstraint.h>
#include <spine/Skin.h>
#include <spine/Attachment.h>
#include <spine/RegionAttachment.h>
#include <spine/MeshAttachment.h>
#include <spine/ClippingAttachment.h>
#include <spine/SkeletonClipping.h>
#include <spine/MathUtil.h>
#include <spine/BonePose.h>
#include <spine/SlotPose.h>
#include <spine/Posed.h>
#include <spine/Update.h>
#include <float.h>

using namespace spine;

static const unsigned short quadTriangles[] = {0, 1, 2, 2, 3, 0};

Skeleton::Skeleton(SkeletonData &skeletonData) : _data(skeletonData), _skin(NULL), _color(1, 1, 1, 1),
												 _scaleX(1), _scaleY(1), _x(0), _y(0), _time(0), _windX(1), _windY(0), _gravityX(0), _gravityY(1), _update(0) {

	// Create bones
	_bones.ensureCapacity(_data.getBones().size());
	Vector<BoneData *> &boneDataArray = _data.getBones();
	for (size_t i = 0; i < boneDataArray.size(); ++i) {
		BoneData *boneData = boneDataArray[i];
		Bone *bone;
		if (boneData->getParent() == NULL) {
			bone = new (__FILE__, __LINE__) Bone(*boneData, NULL);
		} else {
			Bone *parent = _bones[boneData->getParent()->getIndex()];
			bone = new (__FILE__, __LINE__) Bone(*boneData, parent);
			parent->getChildren().add(bone);
		}
		_bones.add(bone);
	}

	// Create slots
	_slots.ensureCapacity(_data.getSlots().size());
	_drawOrder.ensureCapacity(_data.getSlots().size());
	Vector<SlotData *> &slotDataArray = _data.getSlots();
	for (size_t i = 0; i < slotDataArray.size(); ++i) {
		SlotData *slotData = slotDataArray[i];
		Slot *slot = new (__FILE__, __LINE__) Slot(*slotData, *this);
		_slots.add(slot);
		_drawOrder.add(slot);
	}

	// Create constraints and physics
	_physics.ensureCapacity(8);
	_constraints.ensureCapacity(_data.getConstraints().size());
	Vector<ConstraintData *> &constraintDataArray = _data.getConstraints();
	for (size_t i = 0; i < constraintDataArray.size(); ++i) {
		ConstraintData *constraintData = constraintDataArray[i];
		Constraint *constraint = constraintData->create(*this);
		PhysicsConstraint *physicsConstraint = dynamic_cast<PhysicsConstraint *>(constraint);
		if (physicsConstraint != NULL) {
			_physics.add(physicsConstraint);
		}
		_constraints.add(constraint);
	}
	_physics.shrink();

	updateCache();
}

Skeleton::~Skeleton() {
	for (size_t i = 0; i < _bones.size(); ++i) {
		delete _bones[i];
	}
	for (size_t i = 0; i < _slots.size(); ++i) {
		delete _slots[i];
	}
	for (size_t i = 0; i < _constraints.size(); ++i) {
		delete _constraints[i];
	}
}

void Skeleton::updateCache() {
	_updateCache.clear();

	// Reset slot applied poses to current pose
	for (size_t i = 0; i < _slots.size(); ++i) {
		Slot *slot = _slots[i];
		slot->getAppliedPose().set(slot->getPose());
	}

	// Mark bones based on skin requirements
	size_t boneCount = _bones.size();
	for (size_t i = 0; i < boneCount; ++i) {
		Bone *bone = _bones[i];
		bone->_sorted = bone->getData().getSkinRequired();
		bone->_active = !bone->_sorted;
		bone->getAppliedPose().set(bone->getPose());
	}

	// Activate bones required by skin
	if (_skin != NULL) {
		Vector<BoneData *> &skinBones = _skin->getBones();
		for (size_t i = 0; i < skinBones.size(); ++i) {
			Bone *bone = _bones[skinBones[i]->getIndex()];
			do {
				bone->_sorted = false;
				bone->_active = true;
				bone = bone->getParent();
			} while (bone != NULL);
		}
	}

	// Set constraint applied poses and mark active constraints
	for (size_t i = 0; i < _constraints.size(); ++i) {
		Constraint *constraint = _constraints[i];
		constraint->getAppliedPose().set(constraint->getPose());
	}

	for (size_t i = 0; i < _constraints.size(); ++i) {
		Constraint *constraint = _constraints[i];
		constraint->_active = constraint->isSourceActive() &&
							  (!constraint->getData().getSkinRequired() || (_skin != NULL && _skin->getConstraints().contains(&constraint->getData(), true)));
		if (constraint->_active) {
			constraint->sort(*this);
		}
	}

	// Sort all bones
	for (size_t i = 0; i < boneCount; ++i) {
		sortBone(_bones[i]);
	}

	// Replace bone references in update cache with their applied poses
	for (size_t i = 0; i < _updateCache.size(); ++i) {
		Update *updateItem = _updateCache[i];
		Bone *bone = dynamic_cast<Bone *>(updateItem);
		if (bone != NULL) {
			_updateCache[i] = &bone->getAppliedPose();
		}
	}
}

void Skeleton::constrained(Posed &object) {
	if (&object.getPose() == &object.getAppliedPose()) {
		object.setAppliedPose(object.getConstrainedPose());
		// Add to reset cache - this would need a resetCache member like Java
	}
}

void Skeleton::sortBone(Bone *bone) {
	if (bone->_sorted || !bone->_active) return;
	Bone *parent = bone->getParent();
	if (parent != NULL) sortBone(parent);
	bone->_sorted = true;
	_updateCache.add(bone);
}

void Skeleton::sortReset(Vector<Bone *> &bones) {
	for (size_t i = 0; i < bones.size(); ++i) {
		Bone *bone = bones[i];
		if (bone->_active) {
			if (bone->_sorted) sortReset(bone->getChildren());
			bone->_sorted = false;
		}
	}
}

void Skeleton::updateWorldTransform(Physics physics) {
	_update++;

	// Reset all applied poses to their base poses
	// This would require a resetCache implementation like Java has

	// Update all items in update cache
	for (size_t i = 0; i < _updateCache.size(); ++i) {
		Update *updateItem = _updateCache[i];
		updateItem->update(*this, physics);
	}
}

void Skeleton::updateWorldTransform(Physics physics, BonePose *parent) {
	if (parent == NULL) return;

	_update++;

	// Reset all applied poses to their base poses
	// This would require a resetCache implementation like Java has

	// Apply the parent bone transform to the root bone
	BonePose &rootBone = getRootBone()->getAppliedPose();
	float pa = parent->getA(), pb = parent->getB(), pc = parent->getC(), pd = parent->getD();
	rootBone.setWorldX(pa * _x + pb * _y + parent->getWorldX());
	rootBone.setWorldY(pc * _x + pd * _y + parent->getWorldY());

	float rx = (rootBone.getRotation() + rootBone.getShearX()) * MathUtil::Deg_Rad;
	float ry = (rootBone.getRotation() + 90 + rootBone.getShearY()) * MathUtil::Deg_Rad;
	float la = MathUtil::cos(rx) * rootBone.getScaleX();
	float lb = MathUtil::cos(ry) * rootBone.getScaleY();
	float lc = MathUtil::sin(rx) * rootBone.getScaleX();
	float ld = MathUtil::sin(ry) * rootBone.getScaleY();
	rootBone.setA((pa * la + pb * lc) * _scaleX);
	rootBone.setB((pa * lb + pb * ld) * _scaleX);
	rootBone.setC((pc * la + pd * lc) * _scaleY);
	rootBone.setD((pc * lb + pd * ld) * _scaleY);

	// Update everything except root bone
	for (size_t i = 0; i < _updateCache.size(); ++i) {
		Update *updateItem = _updateCache[i];
		if (updateItem != &rootBone) {
			updateItem->update(*this, physics);
		}
	}
}

void Skeleton::setupPose() {
	setupPoseBones();
	setupPoseSlots();
}

void Skeleton::setupPoseBones() {
	for (size_t i = 0; i < _bones.size(); ++i) {
		_bones[i]->setupPose();
	}
	for (size_t i = 0; i < _constraints.size(); ++i) {
		_constraints[i]->setupPose();
	}
}

void Skeleton::setupPoseSlots() {
	// Copy slots to draw order in setup pose order
	for (size_t i = 0; i < _slots.size(); ++i) {
		_drawOrder[i] = _slots[i];
	}
	for (size_t i = 0; i < _slots.size(); ++i) {
		_slots[i]->setupPose();
	}
}

SkeletonData *Skeleton::getData() {
	return &_data;
}

Vector<Bone *> &Skeleton::getBones() {
	return _bones;
}

Vector<Update *> &Skeleton::getUpdateCache() {
	return _updateCache;
}

Bone *Skeleton::getRootBone() {
	return _bones.size() == 0 ? NULL : _bones[0];
}

Bone *Skeleton::findBone(const String &boneName) {
	if (boneName.isEmpty()) return NULL;
	for (size_t i = 0; i < _bones.size(); ++i) {
		if (_bones[i]->getData().getName() == boneName) {
			return _bones[i];
		}
	}
	return NULL;
}

Vector<Slot *> &Skeleton::getSlots() {
	return _slots;
}

Slot *Skeleton::findSlot(const String &slotName) {
	if (slotName.isEmpty()) return NULL;
	for (size_t i = 0; i < _slots.size(); ++i) {
		if (_slots[i]->getData().getName() == slotName) {
			return _slots[i];
		}
	}
	return NULL;
}

Vector<Slot *> &Skeleton::getDrawOrder() {
	return _drawOrder;
}

Skin *Skeleton::getSkin() {
	return _skin;
}

void Skeleton::setSkin(const String &skinName) {
	Skin *skin = _data.findSkin(skinName);
	if (skin == NULL && !skinName.isEmpty()) {
		// Handle error - skin not found
		return;
	}
	setSkin(skin);
}

void Skeleton::setSkin(Skin *newSkin) {
	if (newSkin == _skin) return;
	if (newSkin != NULL) {
		if (_skin != NULL) {
			newSkin->attachAll(*this, *_skin);
		} else {
			for (size_t i = 0; i < _slots.size(); ++i) {
				Slot *slot = _slots[i];
				const String &name = slot->getData().getAttachmentName();
				if (!name.isEmpty()) {
					Attachment *attachment = newSkin->getAttachment((int) i, name);
					if (attachment != NULL) {
						slot->getPose().setAttachment(attachment);
					}
				}
			}
		}
	}
	_skin = newSkin;
	updateCache();
}

Attachment *Skeleton::getAttachment(const String &slotName, const String &attachmentName) {
	SlotData *slotData = _data.findSlot(slotName);
	if (slotData == NULL) return NULL;
	return getAttachment(slotData->getIndex(), attachmentName);
}

Attachment *Skeleton::getAttachment(int slotIndex, const String &attachmentName) {
	if (attachmentName.isEmpty()) return NULL;
	if (_skin != NULL) {
		Attachment *attachment = _skin->getAttachment(slotIndex, attachmentName);
		if (attachment != NULL) return attachment;
	}
	if (_data.getDefaultSkin() != NULL) {
		return _data.getDefaultSkin()->getAttachment(slotIndex, attachmentName);
	}
	return NULL;
}

void Skeleton::setAttachment(const String &slotName, const String &attachmentName) {
	if (slotName.isEmpty()) return;
	Slot *slot = findSlot(slotName);
	if (slot == NULL) return;
	Attachment *attachment = NULL;
	if (!attachmentName.isEmpty()) {
		attachment = getAttachment(slot->getData().getIndex(), attachmentName);
		if (attachment == NULL) {
			// Handle error - attachment not found
			return;
		}
	}
	slot->getPose().setAttachment(attachment);
}

Vector<Constraint *> &Skeleton::getConstraints() {
	return _constraints;
}

Vector<PhysicsConstraint *> &Skeleton::getPhysicsConstraints() {
	return _physics;
}

void Skeleton::getBounds(float &outX, float &outY, float &outWidth, float &outHeight, Vector<float> &outVertexBuffer) {
	getBounds(outX, outY, outWidth, outHeight, outVertexBuffer, NULL);
}

void Skeleton::getBounds(float &outX, float &outY, float &outWidth, float &outHeight, Vector<float> &outVertexBuffer, SkeletonClipping *clipper) {
	float minX = FLT_MAX, minY = FLT_MAX, maxX = -FLT_MAX, maxY = -FLT_MAX;

	for (size_t i = 0; i < _drawOrder.size(); ++i) {
		Slot *slot = _drawOrder[i];
		if (!slot->getBone().isActive()) continue;

		size_t verticesLength = 0;
		float *vertices = NULL;
		const unsigned short *triangles = NULL;
		Attachment *attachment = slot->getPose().getAttachment();

		if (attachment != NULL) {
			RegionAttachment *region = dynamic_cast<RegionAttachment *>(attachment);
			if (region != NULL) {
				verticesLength = 8;
				outVertexBuffer.setSize(8);
				vertices = outVertexBuffer.buffer();
				region->computeWorldVertices(*slot, vertices, 0, 2);
				triangles = quadTriangles;
			} else {
				MeshAttachment *mesh = dynamic_cast<MeshAttachment *>(attachment);
				if (mesh != NULL) {
					verticesLength = mesh->getWorldVerticesLength();
					outVertexBuffer.setSize(verticesLength);
					vertices = outVertexBuffer.buffer();
					mesh->computeWorldVertices(*this, *slot, 0, verticesLength, vertices, 0, 2);
					triangles = mesh->getTriangles().buffer();
				} else {
					ClippingAttachment *clip = dynamic_cast<ClippingAttachment *>(attachment);
					if (clip != NULL && clipper != NULL) {
						clipper->clipEnd(*slot);
						clipper->clipStart(*this, *slot, *clip);
						continue;
					}
				}
			}

			if (vertices != NULL) {
				if (clipper != NULL && clipper->isClipping() && clipper->clipTriangles(vertices, triangles, 6)) {
					vertices = clipper->getClippedVertices().buffer();
					verticesLength = clipper->getClippedVertices().size();
				}
				for (size_t ii = 0; ii < verticesLength; ii += 2) {
					float x = vertices[ii], y = vertices[ii + 1];
					minX = MathUtil::min(minX, x);
					minY = MathUtil::min(minY, y);
					maxX = MathUtil::max(maxX, x);
					maxY = MathUtil::max(maxY, y);
				}
			}
		}
		if (clipper != NULL) clipper->clipEnd(*slot);
	}
	if (clipper != NULL) clipper->clipEnd();

	outX = minX;
	outY = minY;
	outWidth = maxX - minX;
	outHeight = maxY - minY;
}

Color &Skeleton::getColor() {
	return _color;
}

void Skeleton::setColor(Color &color) {
	_color = color;
}

float Skeleton::getScaleX() {
	return _scaleX;
}

void Skeleton::setScaleX(float inValue) {
	_scaleX = inValue;
}

float Skeleton::getScaleY() {
	return _scaleY;
}

void Skeleton::setScaleY(float inValue) {
	_scaleY = inValue;
}

void Skeleton::setScale(float scaleX, float scaleY) {
	_scaleX = scaleX;
	_scaleY = scaleY;
}

float Skeleton::getX() {
	return _x;
}

void Skeleton::setX(float inValue) {
	_x = inValue;
}

float Skeleton::getY() {
	return _y;
}

void Skeleton::setY(float inValue) {
	_y = inValue;
}

void Skeleton::setPosition(float x, float y) {
	_x = x;
	_y = y;
}

float Skeleton::getWindX() {
	return _windX;
}

void Skeleton::setWindX(float windX) {
	_windX = windX;
}

float Skeleton::getWindY() {
	return _windY;
}

void Skeleton::setWindY(float windY) {
	_windY = windY;
}

float Skeleton::getGravityX() {
	return _gravityX;
}

void Skeleton::setGravityX(float gravityX) {
	_gravityX = gravityX;
}

float Skeleton::getGravityY() {
	return _gravityY;
}

void Skeleton::setGravityY(float gravityY) {
	_gravityY = gravityY;
}

void Skeleton::physicsTranslate(float x, float y) {
	for (size_t i = 0; i < _physics.size(); ++i) {
		_physics[i]->translate(x, y);
	}
}

void Skeleton::physicsRotate(float x, float y, float degrees) {
	for (size_t i = 0; i < _physics.size(); ++i) {
		_physics[i]->rotate(x, y, degrees);
	}
}

float Skeleton::getTime() {
	return _time;
}

void Skeleton::setTime(float time) {
	_time = time;
}

void Skeleton::update(float delta) {
	_time += delta;
}