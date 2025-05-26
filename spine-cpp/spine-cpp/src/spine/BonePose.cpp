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

#include <spine/BonePose.h>
#include <spine/Bone.h>
#include <spine/Skeleton.h>
#include <spine/MathUtil.h>

using namespace spine;

BonePose::BonePose() : _bone(nullptr), _a(1), _b(0), _worldX(0), _c(0), _d(1), _worldY(0), _world(0), _local(0) {
}

BonePose::~BonePose() {
}

void BonePose::update(Skeleton& skeleton, Physics physics) {
	if (_world != skeleton.getUpdate()) updateWorldTransform(skeleton);
}

void BonePose::updateWorldTransform(Skeleton& skeleton) {
	if (_local == skeleton.getUpdate()) {
		updateLocalTransform(skeleton);
	} else {
		_world = skeleton.getUpdate();
	}

	if (_bone->getParent() == nullptr) {
		float sx = skeleton.getScaleX(), sy = skeleton.getScaleY();
		float rx = (_rotation + _shearX) * MathUtil::Deg_Rad;
		float ry = (_rotation + 90 + _shearY) * MathUtil::Deg_Rad;
		_a = MathUtil::cos(rx) * _scaleX * sx;
		_b = MathUtil::cos(ry) * _scaleY * sx;
		_c = MathUtil::sin(rx) * _scaleX * sy;
		_d = MathUtil::sin(ry) * _scaleY * sy;
		_worldX = _x * sx + skeleton.getX();
		_worldY = _y * sy + skeleton.getY();
		return;
	}

	BonePose* parent = _bone->getParent()->getApplied();
	float pa = parent->_a, pb = parent->_b, pc = parent->_c, pd = parent->_d;
	_worldX = pa * _x + pb * _y + parent->_worldX;
	_worldY = pc * _x + pd * _y + parent->_worldY;

	switch (_inherit) {
	case Inherit_Normal: {
		float rx = (_rotation + _shearX) * MathUtil::Deg_Rad;
		float ry = (_rotation + 90 + _shearY) * MathUtil::Deg_Rad;
		float la = MathUtil::cos(rx) * _scaleX;
		float lb = MathUtil::cos(ry) * _scaleY;
		float lc = MathUtil::sin(rx) * _scaleX;
		float ld = MathUtil::sin(ry) * _scaleY;
		_a = pa * la + pb * lc;
		_b = pa * lb + pb * ld;
		_c = pc * la + pd * lc;
		_d = pc * lb + pd * ld;
		break;
	}
	case Inherit_OnlyTranslation: {
		float rx = (_rotation + _shearX) * MathUtil::Deg_Rad;
		float ry = (_rotation + 90 + _shearY) * MathUtil::Deg_Rad;
		_a = MathUtil::cos(rx) * _scaleX;
		_b = MathUtil::cos(ry) * _scaleY;
		_c = MathUtil::sin(rx) * _scaleX;
		_d = MathUtil::sin(ry) * _scaleY;
		break;
	}
	case Inherit_NoRotationOrReflection: {
		float sx = 1 / skeleton.getScaleX(), sy = 1 / skeleton.getScaleY();
		pa *= sx;
		pc *= sy;
		float s = pa * pa + pc * pc, prx;
		if (s > 0.0001f) {
			s = MathUtil::abs(pa * pd * sy - pb * sx * pc) / s;
			pb = pc * s;
			pd = pa * s;
			prx = MathUtil::atan2Deg(pc, pa);
		} else {
			pa = 0;
			pc = 0;
			prx = 90 - MathUtil::atan2Deg(pd, pb);
		}
		float rx = (_rotation + _shearX - prx) * MathUtil::Deg_Rad;
		float ry = (_rotation + _shearY - prx + 90) * MathUtil::Deg_Rad;
		float la = MathUtil::cos(rx) * _scaleX;
		float lb = MathUtil::cos(ry) * _scaleY;
		float lc = MathUtil::sin(rx) * _scaleX;
		float ld = MathUtil::sin(ry) * _scaleY;
		_a = pa * la - pb * lc;
		_b = pa * lb - pb * ld;
		_c = pc * la + pd * lc;
		_d = pc * lb + pd * ld;
		break;
	}
	case Inherit_NoScale:
	case Inherit_NoScaleOrReflection: {
		float rotation = _rotation * MathUtil::Deg_Rad;
		float cosVal = MathUtil::cos(rotation), sinVal = MathUtil::sin(rotation);
		float za = (pa * cosVal + pb * sinVal) / skeleton.getScaleX();
		float zc = (pc * cosVal + pd * sinVal) / skeleton.getScaleY();
		float s = MathUtil::sqrt(za * za + zc * zc);
		if (s > 0.00001f) s = 1 / s;
		za *= s;
		zc *= s;
		s = MathUtil::sqrt(za * za + zc * zc);
		if (_inherit == Inherit_NoScale && (pa * pd - pb * pc < 0) != (skeleton.getScaleX() < 0 != skeleton.getScaleY() < 0)) s = -s;
		rotation = MathUtil::Pi / 2 + MathUtil::atan2(zc, za);
		float zb = MathUtil::cos(rotation) * s;
		float zd = MathUtil::sin(rotation) * s;
		float shearX = _shearX * MathUtil::Deg_Rad;
		float shearY = (90 + _shearY) * MathUtil::Deg_Rad;
		float la = MathUtil::cos(shearX) * _scaleX;
		float lb = MathUtil::cos(shearY) * _scaleY;
		float lc = MathUtil::sin(shearX) * _scaleX;
		float ld = MathUtil::sin(shearY) * _scaleY;
		_a = za * la + zb * lc;
		_b = za * lb + zb * ld;
		_c = zc * la + zd * lc;
		_d = zc * lb + zd * ld;
		break;
	}
	}
	_a *= skeleton.getScaleX();
	_b *= skeleton.getScaleX();
	_c *= skeleton.getScaleY();
	_d *= skeleton.getScaleY();
}

void BonePose::updateLocalTransform(Skeleton& skeleton) {
	_local = 0;
	_world = skeleton.getUpdate();

	if (_bone->getParent() == nullptr) {
		_x = _worldX - skeleton.getX();
		_y = _worldY - skeleton.getY();
		float a = _a, b = _b, c = _c, d = _d;
		_rotation = MathUtil::atan2Deg(c, a);
		_scaleX = MathUtil::sqrt(a * a + c * c);
		_scaleY = MathUtil::sqrt(b * b + d * d);
		_shearX = 0;
		_shearY = MathUtil::atan2Deg(a * b + c * d, a * d - b * c);
		return;
	}

	BonePose* parent = _bone->getParent()->getApplied();
	float pa = parent->_a, pb = parent->_b, pc = parent->_c, pd = parent->_d;
	float pid = 1 / (pa * pd - pb * pc);
	float ia = pd * pid, ib = pb * pid, ic = pc * pid, id = pa * pid;
	float dx = _worldX - parent->_worldX, dy = _worldY - parent->_worldY;
	_x = (dx * ia - dy * ib);
	_y = (dy * id - dx * ic);

	float ra, rb, rc, rd;
	if (_inherit == Inherit_OnlyTranslation) {
		ra = _a;
		rb = _b;
		rc = _c;
		rd = _d;
	} else {
		switch (_inherit) {
		case Inherit_NoRotationOrReflection: {
			float s = MathUtil::abs(pa * pd - pb * pc) / (pa * pa + pc * pc);
			pb = -pc * skeleton.getScaleX() * s / skeleton.getScaleY();
			pd = pa * skeleton.getScaleY() * s / skeleton.getScaleX();
			pid = 1 / (pa * pd - pb * pc);
			ia = pd * pid;
			ib = pb * pid;
			break;
		}
		case Inherit_NoScale:
		case Inherit_NoScaleOrReflection: {
			float r = _rotation * MathUtil::Deg_Rad, cosVal = MathUtil::cos(r), sinVal = MathUtil::sin(r);
			pa = (pa * cosVal + pb * sinVal) / skeleton.getScaleX();
			pc = (pc * cosVal + pd * sinVal) / skeleton.getScaleY();
			float s = MathUtil::sqrt(pa * pa + pc * pc);
			if (s > 0.00001f) s = 1 / s;
			pa *= s;
			pc *= s;
			s = MathUtil::sqrt(pa * pa + pc * pc);
			if (_inherit == Inherit_NoScale && pid < 0 != (skeleton.getScaleX() < 0 != skeleton.getScaleY() < 0)) s = -s;
			r = MathUtil::Pi / 2 + MathUtil::atan2(pc, pa);
			pb = MathUtil::cos(r) * s;
			pd = MathUtil::sin(r) * s;
			pid = 1 / (pa * pd - pb * pc);
			ia = pd * pid;
			ib = pb * pid;
			ic = pc * pid;
			id = pa * pid;
			break;
		}
		}
		ra = ia * _a - ib * _c;
		rb = ia * _b - ib * _d;
		rc = id * _c - ic * _a;
		rd = id * _d - ic * _b;
	}

	_shearX = 0;
	_scaleX = MathUtil::sqrt(ra * ra + rc * rc);
	if (_scaleX > 0.0001f) {
		float det = ra * rd - rb * rc;
		_scaleY = det / _scaleX;
		_shearY = -MathUtil::atan2Deg(ra * rb + rc * rd, det);
		_rotation = MathUtil::atan2Deg(rc, ra);
	} else {
		_scaleX = 0;
		_scaleY = MathUtil::sqrt(rb * rb + rd * rd);
		_shearY = 0;
		_rotation = 90 - MathUtil::atan2Deg(rd, rb);
	}
}

void BonePose::validateLocalTransform(Skeleton& skeleton) {
	if (_local == skeleton.getUpdate()) updateLocalTransform(skeleton);
}

void BonePose::modifyLocal(Skeleton& skeleton) {
	if (_local == skeleton.getUpdate()) updateLocalTransform(skeleton);
	_world = 0;
	resetWorld(skeleton.getUpdate());
}

void BonePose::modifyWorld(int update) {
	_local = update;
	_world = update;
	resetWorld(update);
}

void BonePose::resetWorld(int update) {
	Vector<Bone*>& children = _bone->getChildren();
	for (int i = 0, n = children.size(); i < n; i++) {
		BonePose* child = children[i]->getApplied();
		if (child->_world == update) {
			child->_world = 0;
			child->_local = 0;
			child->resetWorld(update);
		}
	}
}

void BonePose::worldToLocal(float worldX, float worldY, float& outLocalX, float& outLocalY) {
	float det = _a * _d - _b * _c;
	float x = worldX - _worldX, y = worldY - _worldY;
	outLocalX = (x * _d - y * _b) / det;
	outLocalY = (y * _a - x * _c) / det;
}

void BonePose::localToWorld(float localX, float localY, float& outWorldX, float& outWorldY) {
	outWorldX = localX * _a + localY * _b + _worldX;
	outWorldY = localX * _c + localY * _d + _worldY;
}

void BonePose::worldToParent(float worldX, float worldY, float& outParentX, float& outParentY) {
	if (_bone == nullptr || _bone->getParent() == nullptr) {
		outParentX = worldX;
		outParentY = worldY;
		return;
	}
	_bone->getParent()->getApplied()->worldToLocal(worldX, worldY, outParentX, outParentY);
}

void BonePose::parentToWorld(float parentX, float parentY, float& outWorldX, float& outWorldY) {
	if (_bone == nullptr || _bone->getParent() == nullptr) {
		outWorldX = parentX;
		outWorldY = parentY;
		return;
	}
	_bone->getParent()->getApplied()->localToWorld(parentX, parentY, outWorldX, outWorldY);
}

float BonePose::worldToLocalRotation(float worldRotation) {
	worldRotation *= MathUtil::Deg_Rad;
	float sinVal = MathUtil::sin(worldRotation), cosVal = MathUtil::cos(worldRotation);
	return MathUtil::atan2Deg(_a * sinVal - _c * cosVal, _d * cosVal - _b * sinVal) + _rotation - _shearX;
}

float BonePose::localToWorldRotation(float localRotation) {
	localRotation = (localRotation - _rotation - _shearX) * MathUtil::Deg_Rad;
	float sinVal = MathUtil::sin(localRotation), cosVal = MathUtil::cos(localRotation);
	return MathUtil::atan2Deg(cosVal * _c + sinVal * _d, cosVal * _a + sinVal * _b);
}

void BonePose::rotateWorld(float degrees) {
	degrees *= MathUtil::Deg_Rad;
	float sinVal = MathUtil::sin(degrees), cosVal = MathUtil::cos(degrees);
	float ra = _a, rb = _b;
	_a = cosVal * ra - sinVal * _c;
	_b = cosVal * rb - sinVal * _d;
	_c = sinVal * ra + cosVal * _c;
	_d = sinVal * rb + cosVal * _d;
}

float BonePose::getA() const {
	return _a;
}

void BonePose::setA(float a) {
	_a = a;
}

float BonePose::getB() const {
	return _b;
}

void BonePose::setB(float b) {
	_b = b;
}

float BonePose::getC() const {
	return _c;
}

void BonePose::setC(float c) {
	_c = c;
}

float BonePose::getD() const {
	return _d;
}

void BonePose::setD(float d) {
	_d = d;
}

float BonePose::getWorldX() const {
	return _worldX;
}

void BonePose::setWorldX(float worldX) {
	_worldX = worldX;
}

float BonePose::getWorldY() const {
	return _worldY;
}

void BonePose::setWorldY(float worldY) {
	_worldY = worldY;
}

float BonePose::getWorldRotationX() const {
	return MathUtil::atan2Deg(_c, _a);
}

float BonePose::getWorldRotationY() const {
	return MathUtil::atan2Deg(_d, _b);
}

float BonePose::getWorldScaleX() const {
	return MathUtil::sqrt(_a * _a + _c * _c);
}

float BonePose::getWorldScaleY() const {
	return MathUtil::sqrt(_b * _b + _d * _d);
}