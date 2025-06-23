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

#include <spine/TransformConstraintData.h>
#include <spine/TransformConstraint.h>
#include <spine/BoneData.h>
#include <spine/BonePose.h>
#include <spine/TransformConstraintPose.h>
#include <spine/MathUtil.h>
#include <spine/ContainerUtil.h>
#include <spine/Skeleton.h>

using namespace spine;

RTTI_IMPL(TransformConstraintData, ConstraintData)

TransformConstraintData::TransformConstraintData(const String &name) : ConstraintData(name),
																	   PosedDataGeneric<TransformConstraintPose>(name),
																	   _source(NULL),
																	   _localSource(false),
																	   _localTarget(false),
																	   _additive(false),
																	   _clamp(false) {
	for (int i = 0; i < 6; i++) {
		_offsets[i] = 0;
	}
}

Vector<BoneData *> &TransformConstraintData::getBones() {
	return _bones;
}

BoneData *TransformConstraintData::getSource() {
	return _source;
}

void TransformConstraintData::setSource(BoneData *source) {
	_source = source;
}

float TransformConstraintData::getOffsetRotation() {
	return _offsets[ROTATION];
}

void TransformConstraintData::setOffsetRotation(float offsetRotation) {
	_offsets[ROTATION] = offsetRotation;
}

float TransformConstraintData::getOffsetX() {
	return _offsets[X];
}

void TransformConstraintData::setOffsetX(float offsetX) {
	_offsets[X] = offsetX;
}

float TransformConstraintData::getOffsetY() {
	return _offsets[Y];
}

void TransformConstraintData::setOffsetY(float offsetY) {
	_offsets[Y] = offsetY;
}

float TransformConstraintData::getOffsetScaleX() {
	return _offsets[SCALEX];
}

void TransformConstraintData::setOffsetScaleX(float offsetScaleX) {
	_offsets[SCALEX] = offsetScaleX;
}

float TransformConstraintData::getOffsetScaleY() {
	return _offsets[SCALEY];
}

void TransformConstraintData::setOffsetScaleY(float offsetScaleY) {
	_offsets[SCALEY] = offsetScaleY;
}

float TransformConstraintData::getOffsetShearY() {
	return _offsets[SHEARY];
}

void TransformConstraintData::setOffsetShearY(float offsetShearY) {
	_offsets[SHEARY] = offsetShearY;
}

bool TransformConstraintData::getLocalSource() {
	return _localSource;
}

void TransformConstraintData::setLocalSource(bool localSource) {
	_localSource = localSource;
}

bool TransformConstraintData::getLocalTarget() {
	return _localTarget;
}

void TransformConstraintData::setLocalTarget(bool localTarget) {
	_localTarget = localTarget;
}

bool TransformConstraintData::getAdditive() {
	return _additive;
}

void TransformConstraintData::setAdditive(bool additive) {
	_additive = additive;
}

bool TransformConstraintData::getClamp() {
	return _clamp;
}

void TransformConstraintData::setClamp(bool clamp) {
	_clamp = clamp;
}

Vector<FromProperty *> &TransformConstraintData::getProperties() {
	return _properties;
}

// ============================================================================
// Property Classes
// ============================================================================

// No RTTI for FromProperty

FromProperty::FromProperty() : SpineObject(), offset(0) {
}

FromProperty::~FromProperty() {
}

// No RTTI for ToProperty

ToProperty::ToProperty() : offset(0), max(0), scale(1) {
}

ToProperty::~ToProperty() {
}

// No RTTI for FromRotate

float FromRotate::value(BonePose &source, bool local, float *offsets) {
	if (local) return source.getRotation() + offsets[TransformConstraintData::ROTATION];
	float value = MathUtil::atan2(source._c, source._a) * MathUtil::Rad_Deg + (source._a * source._d - source._b * source._c > 0 ? offsets[TransformConstraintData::ROTATION] : -offsets[TransformConstraintData::ROTATION]);
	if (value < 0) value += 360;
	return value;
}

// No RTTI for ToRotate

float ToRotate::mix(TransformConstraintPose &pose) {
	return pose._mixRotate;
}

void ToRotate::apply(TransformConstraintPose &pose, BonePose &bone, float value, bool local, bool additive) {
	if (local) {
		if (!additive) value -= bone.getRotation();
		bone.setRotation(bone.getRotation() + value * pose._mixRotate);
	} else {
		float a = bone._a, b = bone._b, c = bone._c, d = bone._d;
		value *= MathUtil::Deg_Rad;
		if (!additive) value -= MathUtil::atan2(c, a);
		if (value > MathUtil::Pi)
			value -= MathUtil::Pi * 2;
		else if (value < -MathUtil::Pi)
			value += MathUtil::Pi * 2;
		value *= pose._mixRotate;
		float cosVal = MathUtil::cos(value), sinVal = MathUtil::sin(value);
		bone._a = cosVal * a - sinVal * c;
		bone._b = cosVal * b - sinVal * d;
		bone._c = sinVal * a + cosVal * c;
		bone._d = sinVal * b + cosVal * d;
	}
}

// No RTTI for FromX

float FromX::value(BonePose &source, bool local, float *offsets) {
	return local ? source.getX() + offsets[TransformConstraintData::X] : offsets[TransformConstraintData::X] * source._a + offsets[TransformConstraintData::Y] * source._b + source.getWorldX();
}

// No RTTI for ToX

float ToX::mix(TransformConstraintPose &pose) {
	return pose._mixX;
}

void ToX::apply(TransformConstraintPose &pose, BonePose &bone, float value, bool local, bool additive) {
	if (local) {
		if (!additive) value -= bone.getX();
		bone.setX(bone.getX() + value * pose._mixX);
	} else {
		if (!additive) value -= bone.getWorldX();
		bone.setWorldX(bone.getWorldX() + value * pose._mixX);
	}
}

// No RTTI for FromY

float FromY::value(BonePose &source, bool local, float *offsets) {
	return local ? source.getY() + offsets[TransformConstraintData::Y] : offsets[TransformConstraintData::X] * source._c + offsets[TransformConstraintData::Y] * source._d + source.getWorldY();
}

// No RTTI for ToY

float ToY::mix(TransformConstraintPose &pose) {
	return pose._mixY;
}

void ToY::apply(TransformConstraintPose &pose, BonePose &bone, float value, bool local, bool additive) {
	if (local) {
		if (!additive) value -= bone.getY();
		bone.setY(bone.getY() + value * pose._mixY);
	} else {
		if (!additive) value -= bone.getWorldY();
		bone.setWorldY(bone.getWorldY() + value * pose._mixY);
	}
}

// No RTTI for FromScaleX

float FromScaleX::value(BonePose &source, bool local, float *offsets) {
	return (local ? source.getScaleX() : MathUtil::sqrt(source._a * source._a + source._c * source._c)) + offsets[TransformConstraintData::SCALEX];
}

// No RTTI for ToScaleX

float ToScaleX::mix(TransformConstraintPose &pose) {
	return pose._mixScaleX;
}

void ToScaleX::apply(TransformConstraintPose &pose, BonePose &bone, float value, bool local, bool additive) {
	if (local) {
		if (additive)
			bone.setScaleX(bone.getScaleX() * (1 + ((value - 1) * pose._mixScaleX)));
		else if (bone.getScaleX() != 0)
			bone.setScaleX(bone.getScaleX() * (1 + (value / bone.getScaleX() - 1) * pose._mixScaleX));
	} else {
		float s;
		if (additive)
			s = 1 + (value - 1) * pose._mixScaleX;
		else {
			s = MathUtil::sqrt(bone._a * bone._a + bone._c * bone._c);
			if (s != 0) s = 1 + (value / s - 1) * pose._mixScaleX;
		}
		bone._a *= s;
		bone._c *= s;
	}
}

// No RTTI for FromScaleY

float FromScaleY::value(BonePose &source, bool local, float *offsets) {
	return (local ? source.getScaleY() : MathUtil::sqrt(source._b * source._b + source._d * source._d)) + offsets[TransformConstraintData::SCALEY];
}

// No RTTI for ToScaleY

float ToScaleY::mix(TransformConstraintPose &pose) {
	return pose._mixScaleY;
}

void ToScaleY::apply(TransformConstraintPose &pose, BonePose &bone, float value, bool local, bool additive) {
	if (local) {
		if (additive)
			bone.setScaleY(bone.getScaleY() * (1 + ((value - 1) * pose._mixScaleY)));
		else if (bone.getScaleY() != 0)
			bone.setScaleY(bone.getScaleY() * (1 + (value / bone.getScaleY() - 1) * pose._mixScaleY));
	} else {
		float s;
		if (additive)
			s = 1 + (value - 1) * pose._mixScaleY;
		else {
			s = MathUtil::sqrt(bone._b * bone._b + bone._d * bone._d);
			if (s != 0) s = 1 + (value / s - 1) * pose._mixScaleY;
		}
		bone._b *= s;
		bone._d *= s;
	}
}

// No RTTI for FromShearY

float FromShearY::value(BonePose &source, bool local, float *offsets) {
	return (local ? source.getShearY() : (MathUtil::atan2(source._d, source._b) - MathUtil::atan2(source._c, source._a)) * MathUtil::Rad_Deg - 90) + offsets[TransformConstraintData::SHEARY];
}

// No RTTI for ToShearY

float ToShearY::mix(TransformConstraintPose &pose) {
	return pose._mixShearY;
}

void ToShearY::apply(TransformConstraintPose &pose, BonePose &bone, float value, bool local, bool additive) {
	if (local) {
		if (!additive) value -= bone.getShearY();
		bone.setShearY(bone.getShearY() + value * pose._mixShearY);
	} else {
		float b = bone._b, d = bone._d, by = MathUtil::atan2(d, b);
		value = (value + 90) * MathUtil::Deg_Rad;
		if (additive)
			value -= MathUtil::Pi / 2;
		else {
			value -= by - MathUtil::atan2(bone._c, bone._a);
			if (value > MathUtil::Pi)
				value -= MathUtil::Pi * 2;
			else if (value < -MathUtil::Pi)
				value += MathUtil::Pi * 2;
		}
		value = by + value * pose._mixShearY;
		float s = MathUtil::sqrt(b * b + d * d);
		bone._b = MathUtil::cos(value) * s;
		bone._d = MathUtil::sin(value) * s;
	}
}

TransformConstraintData::~TransformConstraintData() {
	// Clean up all FromProperty objects, which will in turn clean up their ToProperty objects
	for (size_t i = 0; i < _properties.size(); i++) {
		FromProperty *fromProp = _properties[i];
		if (fromProp) {
			// Clean up the ToProperty objects in the FromProperty
			ContainerUtil::cleanUpVectorOfPointers(fromProp->to);
			delete fromProp;
		}
	}
	_properties.clear();
}

Constraint* TransformConstraintData::create(Skeleton& skeleton) {
	return new (__FILE__, __LINE__) TransformConstraint(*this, skeleton);
}