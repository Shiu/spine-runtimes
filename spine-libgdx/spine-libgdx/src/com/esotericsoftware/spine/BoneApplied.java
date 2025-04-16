
package com.esotericsoftware.spine;

import static com.badlogic.gdx.math.Matrix3.*;
import static com.esotericsoftware.spine.utils.SpineUtils.*;

import com.badlogic.gdx.math.Matrix3;
import com.badlogic.gdx.math.Vector2;

import com.esotericsoftware.spine.BoneData.Inherit;

/** The applied pose for a bone. This is the {@link Bone} pose with constraints applied and the world transform computed by
 * {@link Skeleton#updateWorldTransform(Physics)}. */
public class BoneApplied extends BonePose implements Update {
	final Bone bone;
	float a, b, worldX;
	float c, d, worldY;

	BoneApplied (Bone bone) {
		this.bone = bone;
	}

	/** Computes the world transform using the parent bone and this bone's local applied transform. */
	public void updateWorldTransform () {
		update(null);
	}

	/** Computes the world transform using the parent bone and this bone's local transform.
	 * <p>
	 * See {@link #updateWorldTransform(float, float, float, float, float, float, float)}. */
	/** Computes the world transform using the parent bone and the specified local transform. The applied transform is set to the
	 * specified local transform. Child bones are not updated.
	 * <p>
	 * See <a href="https://esotericsoftware.com/spine-runtime-skeletons#World-transforms">World transforms</a> in the Spine
	 * Runtimes Guide. */
	public void update (Physics physics) {
		if (bone.parent == null) { // Root bone.
			Skeleton skeleton = bone.skeleton;
			float sx = skeleton.scaleX, sy = skeleton.scaleY;
			float rx = (rotation + shearX) * degRad;
			float ry = (rotation + 90 + shearY) * degRad;
			a = cos(rx) * scaleX * sx;
			b = cos(ry) * scaleY * sx;
			c = sin(rx) * scaleX * sy;
			d = sin(ry) * scaleY * sy;
			worldX = x * sx + skeleton.x;
			worldY = y * sy + skeleton.y;
			return;
		}

		BoneApplied parent = bone.parent.applied;
		float pa = parent.a, pb = parent.b, pc = parent.c, pd = parent.d;
		worldX = pa * x + pb * y + parent.worldX;
		worldY = pc * x + pd * y + parent.worldY;

		switch (inherit) {
		case normal -> {
			float rx = (rotation + shearX) * degRad;
			float ry = (rotation + 90 + shearY) * degRad;
			float la = cos(rx) * scaleX;
			float lb = cos(ry) * scaleY;
			float lc = sin(rx) * scaleX;
			float ld = sin(ry) * scaleY;
			a = pa * la + pb * lc;
			b = pa * lb + pb * ld;
			c = pc * la + pd * lc;
			d = pc * lb + pd * ld;
			return;
		}
		case onlyTranslation -> {
			float rx = (rotation + shearX) * degRad;
			float ry = (rotation + 90 + shearY) * degRad;
			a = cos(rx) * scaleX;
			b = cos(ry) * scaleY;
			c = sin(rx) * scaleX;
			d = sin(ry) * scaleY;
		}
		case noRotationOrReflection -> {
			float sx = 1 / bone.skeleton.scaleX, sy = 1 / bone.skeleton.scaleY;
			pa *= sx;
			pc *= sy;
			float s = pa * pa + pc * pc, prx;
			if (s > 0.0001f) {
				s = Math.abs(pa * pd * sy - pb * sx * pc) / s;
				pb = pc * s;
				pd = pa * s;
				prx = atan2Deg(pc, pa);
			} else {
				pa = 0;
				pc = 0;
				prx = 90 - atan2Deg(pd, pb);
			}
			float rx = (rotation + shearX - prx) * degRad;
			float ry = (rotation + shearY - prx + 90) * degRad;
			float la = cos(rx) * scaleX;
			float lb = cos(ry) * scaleY;
			float lc = sin(rx) * scaleX;
			float ld = sin(ry) * scaleY;
			a = pa * la - pb * lc;
			b = pa * lb - pb * ld;
			c = pc * la + pd * lc;
			d = pc * lb + pd * ld;
		}
		case noScale, noScaleOrReflection -> {
			Skeleton skeleton = bone.skeleton;
			rotation *= degRad;
			float cos = cos(rotation), sin = sin(rotation);
			float za = (pa * cos + pb * sin) / skeleton.scaleX;
			float zc = (pc * cos + pd * sin) / skeleton.scaleY;
			float s = (float)Math.sqrt(za * za + zc * zc);
			if (s > 0.00001f) s = 1 / s;
			za *= s;
			zc *= s;
			s = (float)Math.sqrt(za * za + zc * zc);
			if (inherit == Inherit.noScale && (pa * pd - pb * pc < 0) != (skeleton.scaleX < 0 != skeleton.scaleY < 0)) s = -s;
			rotation = PI / 2 + atan2(zc, za);
			float zb = cos(rotation) * s;
			float zd = sin(rotation) * s;
			shearX *= degRad;
			shearY = (90 + shearY) * degRad;
			float la = cos(shearX) * scaleX;
			float lb = cos(shearY) * scaleY;
			float lc = sin(shearX) * scaleX;
			float ld = sin(shearY) * scaleY;
			a = za * la + zb * lc;
			b = za * lb + zb * ld;
			c = zc * la + zd * lc;
			d = zc * lb + zd * ld;
		}
		}
		Skeleton skeleton = bone.skeleton;
		a *= skeleton.scaleX;
		b *= skeleton.scaleX;
		c *= skeleton.scaleY;
		d *= skeleton.scaleY;
	}

	/** Computes the local transform values from the world transform.
	 * <p>
	 * If the world transform is modified (by a constraint, {@link #rotateWorld(float)}, etc) then this method should be called so
	 * the local transform matches the world transform. The local transform may be needed by other code (eg to apply another
	 * constraint).
	 * <p>
	 * Some information is ambiguous in the world transform, such as -1,-1 scale versus 180 rotation. The local transform after
	 * calling this method is equivalent to the local transform used to compute the world transform, but may not be identical. */
	public void updateLocalTransform () {
		BoneApplied parent = bone.parent.applied;
		if (parent == null) {
			x = worldX - bone.skeleton.x;
			y = worldY - bone.skeleton.y;
			float a = this.a, b = this.b, c = this.c, d = this.d;
			rotation = atan2Deg(c, a);
			scaleX = (float)Math.sqrt(a * a + c * c);
			scaleY = (float)Math.sqrt(b * b + d * d);
			shearX = 0;
			shearY = atan2Deg(a * b + c * d, a * d - b * c);
			return;
		}

		float pa = parent.a, pb = parent.b, pc = parent.c, pd = parent.d;
		float pid = 1 / (pa * pd - pb * pc);
		float ia = pd * pid, ib = pb * pid, ic = pc * pid, id = pa * pid;
		float dx = worldX - parent.worldX, dy = worldY - parent.worldY;
		x = (dx * ia - dy * ib);
		y = (dy * id - dx * ic);

		float ra, rb, rc, rd;
		if (inherit == Inherit.onlyTranslation) {
			ra = a;
			rb = b;
			rc = c;
			rd = d;
		} else {
			Skeleton skeleton = bone.skeleton;
			switch (inherit) {
			case noRotationOrReflection -> {
				float s = Math.abs(pa * pd - pb * pc) / (pa * pa + pc * pc);
				pb = -pc * skeleton.scaleX * s / skeleton.scaleY;
				pd = pa * skeleton.scaleY * s / skeleton.scaleX;
				pid = 1 / (pa * pd - pb * pc);
				ia = pd * pid;
				ib = pb * pid;
			}
			case noScale, noScaleOrReflection -> {
				float r = rotation * degRad, cos = cos(r), sin = sin(r);
				pa = (pa * cos + pb * sin) / skeleton.scaleX;
				pc = (pc * cos + pd * sin) / skeleton.scaleY;
				float s = (float)Math.sqrt(pa * pa + pc * pc);
				if (s > 0.00001f) s = 1 / s;
				pa *= s;
				pc *= s;
				s = (float)Math.sqrt(pa * pa + pc * pc);
				if (inherit == Inherit.noScale && pid < 0 != (skeleton.scaleX < 0 != skeleton.scaleY < 0)) s = -s;
				r = PI / 2 + atan2(pc, pa);
				pb = cos(r) * s;
				pd = sin(r) * s;
				pid = 1 / (pa * pd - pb * pc);
				ia = pd * pid;
				ib = pb * pid;
				ic = pc * pid;
				id = pa * pid;
			}
			}
			ra = ia * a - ib * c;
			rb = ia * b - ib * d;
			rc = id * c - ic * a;
			rd = id * d - ic * b;
		}

		shearX = 0;
		scaleX = (float)Math.sqrt(ra * ra + rc * rc);
		if (scaleX > 0.0001f) {
			float det = ra * rd - rb * rc;
			scaleY = det / scaleX;
			shearY = -atan2Deg(ra * rb + rc * rd, det);
			rotation = atan2Deg(rc, ra);
		} else {
			scaleX = 0;
			scaleY = (float)Math.sqrt(rb * rb + rd * rd);
			shearY = 0;
			rotation = 90 - atan2Deg(rd, rb);
		}
	}

	/** Part of the world transform matrix for the X axis. If changed, {@link #updateLocalTransform()} should be called. */
	public float getA () {
		return a;
	}

	public void setA (float a) {
		this.a = a;
	}

	/** Part of the world transform matrix for the Y axis. If changed, {@link #updateLocalTransform()} should be called. */
	public float getB () {
		return b;
	}

	public void setB (float b) {
		this.b = b;
	}

	/** Part of the world transform matrix for the X axis. If changed, {@link #updateLocalTransform()} should be called. */
	public float getC () {
		return c;
	}

	public void setC (float c) {
		this.c = c;
	}

	/** Part of the world transform matrix for the Y axis. If changed, {@link #updateLocalTransform()} should be called. */
	public float getD () {
		return d;
	}

	public void setD (float d) {
		this.d = d;
	}

	/** The world X position. If changed, {@link #updateLocalTransform()} should be called. */
	public float getWorldX () {
		return worldX;
	}

	public void setWorldX (float worldX) {
		this.worldX = worldX;
	}

	/** The world Y position. If changed, {@link #updateLocalTransform()} should be called. */
	public float getWorldY () {
		return worldY;
	}

	public void setWorldY (float worldY) {
		this.worldY = worldY;
	}

	/** The world rotation for the X axis, calculated using {@link #a} and {@link #c}. */
	public float getWorldRotationX () {
		return atan2Deg(c, a);
	}

	/** The world rotation for the Y axis, calculated using {@link #b} and {@link #d}. */
	public float getWorldRotationY () {
		return atan2Deg(d, b);
	}

	/** The magnitude (always positive) of the world scale X, calculated using {@link #a} and {@link #c}. */
	public float getWorldScaleX () {
		return (float)Math.sqrt(a * a + c * c);
	}

	/** The magnitude (always positive) of the world scale Y, calculated using {@link #b} and {@link #d}. */
	public float getWorldScaleY () {
		return (float)Math.sqrt(b * b + d * d);
	}

	public Matrix3 getWorldTransform (Matrix3 worldTransform) {
		if (worldTransform == null) throw new IllegalArgumentException("worldTransform cannot be null.");
		float[] val = worldTransform.val;
		val[M00] = a;
		val[M01] = b;
		val[M10] = c;
		val[M11] = d;
		val[M02] = worldX;
		val[M12] = worldY;
		val[M20] = 0;
		val[M21] = 0;
		val[M22] = 1;
		return worldTransform;
	}

	/** Transforms a point from world coordinates to the bone's local coordinates. */
	public Vector2 worldToLocal (Vector2 world) {
		if (world == null) throw new IllegalArgumentException("world cannot be null.");
		float det = a * d - b * c;
		float x = world.x - worldX, y = world.y - worldY;
		world.x = (x * d - y * b) / det;
		world.y = (y * a - x * c) / det;
		return world;
	}

	/** Transforms a point from the bone's local coordinates to world coordinates. */
	public Vector2 localToWorld (Vector2 local) {
		if (local == null) throw new IllegalArgumentException("local cannot be null.");
		float x = local.x, y = local.y;
		local.x = x * a + y * b + worldX;
		local.y = x * c + y * d + worldY;
		return local;
	}

	/** Transforms a point from world coordinates to the parent bone's local coordinates. */
	public Vector2 worldToParent (Vector2 world) {
		if (world == null) throw new IllegalArgumentException("world cannot be null.");
		return bone.parent == null ? world : bone.parent.applied.worldToLocal(world);
	}

	/** Transforms a point from the parent bone's coordinates to world coordinates. */
	public Vector2 parentToWorld (Vector2 world) {
		if (world == null) throw new IllegalArgumentException("world cannot be null.");
		return bone.parent == null ? world : bone.parent.applied.localToWorld(world);
	}

	/** Transforms a world rotation to a local rotation. */
	public float worldToLocalRotation (float worldRotation) {
		worldRotation *= degRad;
		float sin = sin(worldRotation), cos = cos(worldRotation);
		return atan2Deg(a * sin - c * cos, d * cos - b * sin) + rotation - shearX;
	}

	/** Transforms a local rotation to a world rotation. */
	public float localToWorldRotation (float localRotation) {
		localRotation = (localRotation - rotation - shearX) * degRad;
		float sin = sin(localRotation), cos = cos(localRotation);
		return atan2Deg(cos * c + sin * d, cos * a + sin * b);
	}

	/** Rotates the world transform the specified amount.
	 * <p>
	 * After changes are made to the world transform, {@link #updateLocalTransform()} should be called and {@link #update(Physics)}
	 * will need to be called on any child bones, recursively. */
	public void rotateWorld (float degrees) {
		degrees *= degRad;
		float sin = sin(degrees), cos = cos(degrees);
		float ra = a, rb = b;
		a = cos * ra - sin * c;
		b = cos * rb - sin * d;
		c = sin * ra + cos * c;
		d = sin * rb + cos * d;
	}

	public String toString () {
		return bone.data.name;
	}
}
