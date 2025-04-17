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

import static com.esotericsoftware.spine.utils.SpineUtils.*;

import com.badlogic.gdx.utils.Array;

/** Stores the setup pose for a {@link TransformConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-transform-constraints">Transform constraints</a> in the Spine User Guide. */
public class TransformConstraintData extends PosedData<TransformConstraintPose> {
	final Array<BoneData> bones = new Array();
	BoneData source;
	float offsetRotation, offsetX, offsetY, offsetScaleX, offsetScaleY, offsetShearY;
	boolean localSource, localTarget, additive, clamp;
	final Array<FromProperty> properties = new Array();

	public TransformConstraintData (String name) {
		super(name, new TransformConstraintPose());
	}

	/** The bones that will be modified by this transform constraint. */
	public Array<BoneData> getBones () {
		return bones;
	}

	/** The bone whose world transform will be copied to the constrained bones. */
	public BoneData getSource () {
		return source;
	}

	public void setSource (BoneData source) {
		if (source == null) throw new IllegalArgumentException("source cannot be null.");
		this.source = source;
	}

	/** An offset added to the constrained bone rotation. */
	public float getOffsetRotation () {
		return offsetRotation;
	}

	public void setOffsetRotation (float offsetRotation) {
		this.offsetRotation = offsetRotation;
	}

	/** An offset added to the constrained bone X translation. */
	public float getOffsetX () {
		return offsetX;
	}

	public void setOffsetX (float offsetX) {
		this.offsetX = offsetX;
	}

	/** An offset added to the constrained bone Y translation. */
	public float getOffsetY () {
		return offsetY;
	}

	public void setOffsetY (float offsetY) {
		this.offsetY = offsetY;
	}

	/** An offset added to the constrained bone scaleX. */
	public float getOffsetScaleX () {
		return offsetScaleX;
	}

	public void setOffsetScaleX (float offsetScaleX) {
		this.offsetScaleX = offsetScaleX;
	}

	/** An offset added to the constrained bone scaleY. */
	public float getOffsetScaleY () {
		return offsetScaleY;
	}

	public void setOffsetScaleY (float offsetScaleY) {
		this.offsetScaleY = offsetScaleY;
	}

	/** An offset added to the constrained bone shearY. */
	public float getOffsetShearY () {
		return offsetShearY;
	}

	public void setOffsetShearY (float offsetShearY) {
		this.offsetShearY = offsetShearY;
	}

	/** Reads the source bone's local transform instead of its world transform. */
	public boolean getLocalSource () {
		return localSource;
	}

	public void setLocalSource (boolean localSource) {
		this.localSource = localSource;
	}

	/** Sets the constrained bones' local transforms instead of their world transforms. */
	public boolean getLocalTarget () {
		return localTarget;
	}

	public void setLocalTarget (boolean localTarget) {
		this.localTarget = localTarget;
	}

	/** Adds the source bone transform to the constrained bones instead of setting it absolutely. */
	public boolean getAdditive () {
		return additive;
	}

	public void setAdditive (boolean additive) {
		this.additive = additive;
	}

	/** Prevents constrained bones from exceeding the ranged defined by {@link ToProperty#offset} and {@link ToProperty#max}. */
	public boolean getClamp () {
		return clamp;
	}

	public void setClamp (boolean clamp) {
		this.clamp = clamp;
	}

	/** The mapping of transform properties to other transform properties. */
	public Array<FromProperty> getProperties () {
		return properties;
	}

	/** Source property for a {@link TransformConstraint}. */
	static abstract public class FromProperty {
		/** The value of this property that corresponds to {@link ToProperty#offset}. */
		public float offset;

		/** Constrained properties. */
		public final Array<ToProperty> to = new Array();

		/** Reads this property from the specified bone. */
		abstract public float value (TransformConstraintData data, BonePose source, boolean local);
	}

	/** Constrained property for a {@link TransformConstraint}. */
	static abstract public class ToProperty {
		/** The value of this property that corresponds to {@link FromProperty#offset}. */
		public float offset;

		/** The maximum value of this property when {@link TransformConstraintData#clamp clamped}. */
		public float max;

		/** The scale of the {@link FromProperty} value in relation to this property. */
		public float scale;

		/** Reads the mix for this property from the specified pose. */
		abstract public float mix (TransformConstraintPose pose);

		/** Applies the value to this property. */
		abstract public void apply (TransformConstraintPose pose, BonePose bone, float value, boolean local, boolean additive);
	}

	static public class FromRotate extends FromProperty {
		public float value (TransformConstraintData data, BonePose source, boolean local) {
			if (local) return source.rotation + data.offsetRotation;
			float value = atan2(source.c, source.a) * radDeg
				+ (source.a * source.d - source.b * source.c > 0 ? data.offsetRotation : -data.offsetRotation);
			if (value < 0) value += 360;
			return value;
		}
	}

	static public class ToRotate extends ToProperty {
		public float mix (TransformConstraintPose pose) {
			return pose.mixRotate;
		}

		public void apply (TransformConstraintPose pose, BonePose bone, float value, boolean local, boolean additive) {
			if (local) {
				if (!additive) value -= bone.rotation;
				bone.rotation += value * pose.mixRotate;
			} else {
				float a = bone.a, b = bone.b, c = bone.c, d = bone.d;
				value *= degRad;
				if (!additive) value -= atan2(c, a);
				if (value > PI)
					value -= PI2;
				else if (value < -PI) //
					value += PI2;
				value *= pose.mixRotate;
				float cos = cos(value), sin = sin(value);
				bone.a = cos * a - sin * c;
				bone.b = cos * b - sin * d;
				bone.c = sin * a + cos * c;
				bone.d = sin * b + cos * d;
			}
		}
	}

	static public class FromX extends FromProperty {
		public float value (TransformConstraintData data, BonePose source, boolean local) {
			return local ? source.x + data.offsetX : data.offsetX * source.a + data.offsetY * source.b + source.worldX;
		}
	}

	static public class ToX extends ToProperty {
		public float mix (TransformConstraintPose pose) {
			return pose.mixX;
		}

		public void apply (TransformConstraintPose pose, BonePose bone, float value, boolean local, boolean additive) {
			if (local) {
				if (!additive) value -= bone.x;
				bone.x += value * pose.mixX;
			} else {
				if (!additive) value -= bone.worldX;
				bone.worldX += value * pose.mixX;
			}
		}
	}

	static public class FromY extends FromProperty {
		public float value (TransformConstraintData data, BonePose source, boolean local) {
			return local ? source.y + data.offsetY : data.offsetX * source.c + data.offsetY * source.d + source.worldY;
		}
	}

	static public class ToY extends ToProperty {
		public float mix (TransformConstraintPose pose) {
			return pose.mixY;
		}

		public void apply (TransformConstraintPose pose, BonePose bone, float value, boolean local, boolean additive) {
			if (local) {
				if (!additive) value -= bone.y;
				bone.y += value * pose.mixY;
			} else {
				if (!additive) value -= bone.worldY;
				bone.worldY += value * pose.mixY;
			}
		}
	}

	static public class FromScaleX extends FromProperty {
		public float value (TransformConstraintData data, BonePose source, boolean local) {
			return (local ? source.scaleX : (float)Math.sqrt(source.a * source.a + source.c * source.c)) + data.offsetScaleX;
		}
	}

	static public class ToScaleX extends ToProperty {
		public float mix (TransformConstraintPose pose) {
			return pose.mixScaleX;
		}

		public void apply (TransformConstraintPose pose, BonePose bone, float value, boolean local, boolean additive) {
			if (local) {
				if (additive)
					bone.scaleX *= 1 + ((value - 1) * pose.mixScaleX);
				else if (bone.scaleX != 0) //
					bone.scaleX = 1 + (value / bone.scaleX - 1) * pose.mixScaleX;
			} else {
				float s;
				if (additive)
					s = 1 + (value - 1) * pose.mixScaleX;
				else {
					s = (float)Math.sqrt(bone.a * bone.a + bone.c * bone.c);
					if (s != 0) s = 1 + (value / s - 1) * pose.mixScaleX;
				}
				bone.a *= s;
				bone.c *= s;
			}
		}
	}

	static public class FromScaleY extends FromProperty {
		public float value (TransformConstraintData data, BonePose source, boolean local) {
			return (local ? source.scaleY : (float)Math.sqrt(source.b * source.b + source.d * source.d)) + data.offsetScaleY;
		}
	}

	static public class ToScaleY extends ToProperty {
		public float mix (TransformConstraintPose pose) {
			return pose.mixScaleY;
		}

		public void apply (TransformConstraintPose pose, BonePose bone, float value, boolean local, boolean additive) {
			if (local) {
				if (additive)
					bone.scaleY *= 1 + ((value - 1) * pose.mixScaleY);
				else if (bone.scaleY != 0) //
					bone.scaleY = 1 + (value / bone.scaleY - 1) * pose.mixScaleY;
			} else {
				float s;
				if (additive)
					s = 1 + (value - 1) * pose.mixScaleY;
				else {
					s = (float)Math.sqrt(bone.b * bone.b + bone.d * bone.d);
					if (s != 0) s = 1 + (value / s - 1) * pose.mixScaleY;
				}
				bone.b *= s;
				bone.d *= s;
			}
		}
	}

	static public class FromShearY extends FromProperty {
		public float value (TransformConstraintData data, BonePose source, boolean local) {
			return (local ? source.shearY : (atan2(source.d, source.b) - atan2(source.c, source.a)) * radDeg - 90)
				+ data.offsetShearY;
		}
	}

	static public class ToShearY extends ToProperty {
		public float mix (TransformConstraintPose pose) {
			return pose.mixShearY;
		}

		public void apply (TransformConstraintPose pose, BonePose bone, float value, boolean local, boolean additive) {
			if (local) {
				if (!additive) value -= bone.shearY;
				bone.shearY += value * pose.mixShearY;
			} else {
				float b = bone.b, d = bone.d, by = atan2(d, b);
				value = (value + 90) * degRad;
				if (additive)
					value -= PI / 2;
				else {
					value -= by - atan2(bone.c, bone.a);
					if (value > PI)
						value -= PI2;
					else if (value < -PI) //
						value += PI2;
				}
				value = by + value * pose.mixShearY;
				float s = (float)Math.sqrt(b * b + d * d);
				bone.b = cos(value) * s;
				bone.d = sin(value) * s;
			}
		}
	}
}
