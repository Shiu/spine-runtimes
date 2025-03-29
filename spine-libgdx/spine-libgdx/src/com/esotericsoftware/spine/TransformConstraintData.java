/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated February 20, 2024. Replaces all prior versions.
 *
 * Copyright (c) 2013-2024, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * https://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software or
 * otherwise create derivative works of the Spine Runtimes (collectively,
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
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
 * SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

package com.esotericsoftware.spine;

import static com.esotericsoftware.spine.utils.SpineUtils.*;

import com.badlogic.gdx.utils.Array;

/** Stores the setup pose for a {@link TransformConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-transform-constraints">Transform constraints</a> in the Spine User Guide. */
public class TransformConstraintData extends ConstraintData {
	final Array<BoneData> bones = new Array();
	BoneData target;
	float mixRotate, mixX, mixY, mixScaleX, mixScaleY, mixShearY;
	boolean localFrom, localTo, relative, clamp;
	final Array<FromProperty> properties = new Array();

	public TransformConstraintData (String name) {
		super(name);
	}

	/** The bones that will be modified by this transform constraint. */
	public Array<BoneData> getBones () {
		return bones;
	}

	/** The target bone whose world transform will be copied to the constrained bones. */
	public BoneData getTarget () {
		return target;
	}

	public void setTarget (BoneData target) {
		if (target == null) throw new IllegalArgumentException("target cannot be null.");
		this.target = target;
	}

	/** The mapping of transform properties to other transform properties. */
	public Array<FromProperty> getProperties () {
		return properties;
	}

	/** A percentage (0-1) that controls the mix between the constrained and unconstrained rotation. */
	public float getMixRotate () {
		return mixRotate;
	}

	public void setMixRotate (float mixRotate) {
		this.mixRotate = mixRotate;
	}

	/** A percentage (0-1) that controls the mix between the constrained and unconstrained translation X. */
	public float getMixX () {
		return mixX;
	}

	public void setMixX (float mixX) {
		this.mixX = mixX;
	}

	/** A percentage (0-1) that controls the mix between the constrained and unconstrained translation Y. */
	public float getMixY () {
		return mixY;
	}

	public void setMixY (float mixY) {
		this.mixY = mixY;
	}

	/** A percentage (0-1) that controls the mix between the constrained and unconstrained scale X. */
	public float getMixScaleX () {
		return mixScaleX;
	}

	public void setMixScaleX (float mixScaleX) {
		this.mixScaleX = mixScaleX;
	}

	/** A percentage (0-1) that controls the mix between the constrained and unconstrained scale Y. */
	public float getMixScaleY () {
		return mixScaleY;
	}

	public void setMixScaleY (float mixScaleY) {
		this.mixScaleY = mixScaleY;
	}

	/** A percentage (0-1) that controls the mix between the constrained and unconstrained shear Y. */
	public float getMixShearY () {
		return mixShearY;
	}

	public void setMixShearY (float mixShearY) {
		this.mixShearY = mixShearY;
	}

	public boolean getLocalFrom () {
		return localFrom;
	}

	public void setLocalFrom (boolean localFrom) {
		this.localFrom = localFrom;
	}

	public boolean getLocalTo () {
		return localTo;
	}

	public void setLocalTo (boolean localTo) {
		this.localTo = localTo;
	}

	public boolean getRelative () {
		return relative;
	}

	public void setRelative (boolean relative) {
		this.relative = relative;
	}

	public boolean getClamp () {
		return clamp;
	}

	public void setClamp (boolean clamp) {
		this.clamp = clamp;
	}

	static abstract public class FromProperty {
		public float offset;
		public final Array<ToProperty> to = new Array();

		abstract public float value (Bone target, boolean local);

		abstract public float mix (TransformConstraint constraint);
	}

	static abstract public class ToProperty {
		public float offset, max, scale;

		abstract public void apply (TransformConstraint constraint, Bone bone, float value, boolean local, boolean relative);
	}

	static public class FromRotate extends FromProperty {
		public float value (Bone target, boolean local) {
			return local ? target.arotation : atan2(target.c, target.a) * radDeg;
		}

		public float mix (TransformConstraint constraint) {
			return constraint.mixRotate;
		}
	}

	static public class ToRotate extends ToProperty {
		public void apply (TransformConstraint constraint, Bone bone, float value, boolean local, boolean relative) {
			if (local) {
				if (!relative) value -= bone.arotation;
				bone.arotation += value * constraint.mixRotate;
			} else {
				float a = bone.a, b = bone.b, c = bone.c, d = bone.d;
				float r = value * degRad;
				if (!relative) r -= atan2(c, a);
				if (r > PI)
					r -= PI2;
				else if (r < -PI) //
					r += PI2;
				r *= constraint.mixRotate;
				float cos = cos(r), sin = sin(r);
				bone.a = cos * a - sin * c;
				bone.b = cos * b - sin * d;
				bone.c = sin * a + cos * c;
				bone.d = sin * b + cos * d;
			}
		}
	}

	static public class FromX extends FromProperty {
		public float value (Bone target, boolean local) {
			return local ? target.ax : target.worldX;
		}

		public float mix (TransformConstraint constraint) {
			return constraint.mixX;
		}
	}

	static public class ToX extends ToProperty {
		public void apply (TransformConstraint constraint, Bone bone, float value, boolean local, boolean relative) {
			if (local) {
				if (!relative) value -= bone.ax;
				bone.ax += value * constraint.mixX;
			} else {
				if (!relative) value -= bone.worldX;
				bone.worldX += value * constraint.mixX;
			}
		}
	}

	static public class FromY extends FromProperty {
		public float value (Bone target, boolean local) {
			return local ? target.ay : target.worldY;
		}

		public float mix (TransformConstraint constraint) {
			return constraint.mixY;
		}
	}

	static public class ToY extends ToProperty {
		public void apply (TransformConstraint constraint, Bone bone, float value, boolean local, boolean relative) {
			if (local) {
				if (!relative) value -= bone.ay;
				bone.ay += value * constraint.mixY;
			} else {
				if (!relative) value -= bone.worldY;
				bone.worldY += value * constraint.mixY;
			}
		}
	}

	static public class FromScaleX extends FromProperty {
		public float value (Bone target, boolean local) {
			return local ? target.arotation : (float)Math.sqrt(target.a * target.a + target.c * target.c);
		}

		public float mix (TransformConstraint constraint) {
			return constraint.mixScaleX;
		}
	}

	static public class ToScaleX extends ToProperty {
		public void apply (TransformConstraint constraint, Bone bone, float value, boolean local, boolean relative) {
			if (local) {
				if (relative)
					bone.ascaleX *= 1 + ((value - 1) * constraint.mixScaleX);
				else if (bone.ascaleX != 0) //
					bone.ascaleX = 1 + (value / bone.ascaleX - 1) * constraint.mixScaleX;
			} else {
				float s;
				if (relative)
					s = 1 + (value - 1) * constraint.mixScaleX;
				else {
					s = (float)Math.sqrt(bone.a * bone.a + bone.c * bone.c);
					if (s != 0) s = 1 + (value / s - 1) * constraint.mixScaleX;
				}
				bone.a *= s;
				bone.c *= s;
			}
		}
	}

	static public class FromScaleY extends FromProperty {
		public float value (Bone target, boolean local) {
			return local ? target.arotation : (float)Math.sqrt(target.b * target.b + target.d * target.d);
		}

		public float mix (TransformConstraint constraint) {
			return constraint.mixScaleY;
		}
	}

	static public class ToScaleY extends ToProperty {
		public void apply (TransformConstraint constraint, Bone bone, float value, boolean local, boolean relative) {
			if (local) {
				if (relative)
					bone.ascaleY *= 1 + ((value - 1) * constraint.mixScaleY);
				else if (bone.ascaleY != 0) //
					bone.ascaleY = 1 + (value / bone.ascaleY - 1) * constraint.mixScaleY;
			} else {
				float s;
				if (relative)
					s = 1 + (value - 1) * constraint.mixScaleY;
				else {
					s = (float)Math.sqrt(bone.b * bone.b + bone.d * bone.d);
					if (s != 0) s = 1 + (value / s - 1) * constraint.mixScaleY;
				}
				bone.b *= s;
				bone.d *= s;
			}
		}
	}

	static public class FromShearY extends FromProperty {
		public float value (Bone target, boolean local) {
			if (local) return target.ashearY;
			float r = atan2(target.d, target.b) - atan2(target.c, target.a);
			if (r > PI)
				r -= PI2;
			else if (r < -PI) //
				r += PI2;
			return r;
		}

		public float mix (TransformConstraint constraint) {
			return constraint.mixShearY;
		}
	}

	static public class ToShearY extends ToProperty {
		public void apply (TransformConstraint constraint, Bone bone, float value, boolean local, boolean relative) {
			if (local) {
				if (!relative) value -= bone.ashearY;
				bone.ashearY += value * constraint.mixShearY;
			} else {
				float b = bone.b, d = bone.d, by = atan2(d, b);
				if (relative)
					value -= PI / 2;
				else {
					value -= by - atan2(bone.c, bone.a);
					if (value > PI)
						value -= PI2;
					else if (value < -PI) //
						value += PI2;
				}
				value = by + value * constraint.mixShearY;
				float s = (float)Math.sqrt(b * b + d * d);
				bone.b = cos(value) * s;
				bone.d = sin(value) * s;
			}
		}
	}
}
