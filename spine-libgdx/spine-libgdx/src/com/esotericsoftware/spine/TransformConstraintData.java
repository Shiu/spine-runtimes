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
	BoneData source;
	float mixRotate, mixX, mixY, mixScaleX, mixScaleY, mixShearY;
	boolean localSource, localTarget, relative, clamp;
	final Array<FromProperty> properties = new Array();

	public TransformConstraintData (String name) {
		super(name);
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
	public boolean getRelative () {
		return relative;
	}

	public void setRelative (boolean relative) {
		this.relative = relative;
	}

	/** Prevents constrained bones from exceeding the ranged defined by {@link ToProperty#offset} and {@link ToProperty#max}. */
	public boolean getClamp () {
		return clamp;
	}

	public void setClamp (boolean clamp) {
		this.clamp = clamp;
	}

	/** Source property for a {@link TransformConstraint}. */
	static abstract public class FromProperty {
		/** The value of this property that corresponds to {@link ToProperty#offset}. */
		public float offset;

		/** Constrained properties. */
		public final Array<ToProperty> to = new Array();

		/** Reads the mix for this property from the specified constraint. */
		abstract public float mix (TransformConstraint constraint);

		/** Reads this property from the specified bone. */
		abstract public float value (Bone source, boolean local);
	}

	/** Constrained property for a {@link TransformConstraint}. */
	static abstract public class ToProperty {
		/** The value of this property that corresponds to {@link FromProperty#offset}. */
		public float offset;

		/** The maximum value of this property when {@link TransformConstraintData#clamp clamped}. */
		public float max;

		/** The scale of the {@link FromProperty} value in relation to this property. */
		public float scale;

		/** Applies the value to this property. */
		abstract public void apply (Bone target, float value, boolean local, boolean relative, float mix);
	}

	static public class FromRotate extends FromProperty {
		public float mix (TransformConstraint constraint) {
			return constraint.mixRotate;
		}

		public float value (Bone source, boolean local) {
			return local ? source.arotation : atan2(source.c, source.a) * radDeg;
		}
	}

	static public class ToRotate extends ToProperty {
		public void apply (Bone target, float value, boolean local, boolean relative, float mix) {
			if (local) {
				if (!relative) value -= target.arotation;
				target.arotation += value * mix;
			} else {
				float a = target.a, b = target.b, c = target.c, d = target.d;
				value *= degRad;
				if (!relative) value -= atan2(c, a);
				if (value > PI)
					value -= PI2;
				else if (value < -PI) //
					value += PI2;
				value *= mix;
				float cos = cos(value), sin = sin(value);
				target.a = cos * a - sin * c;
				target.b = cos * b - sin * d;
				target.c = sin * a + cos * c;
				target.d = sin * b + cos * d;
			}
		}
	}

	static public class FromX extends FromProperty {
		public float mix (TransformConstraint constraint) {
			return constraint.mixX;
		}

		public float value (Bone source, boolean local) {
			return local ? source.ax : source.worldX;
		}
	}

	static public class ToX extends ToProperty {
		public void apply (Bone target, float value, boolean local, boolean relative, float mix) {
			if (local) {
				if (!relative) value -= target.ax;
				target.ax += value * mix;
			} else {
				if (!relative) value -= target.worldX;
				target.worldX += value * mix;
			}
		}
	}

	static public class FromY extends FromProperty {
		public float mix (TransformConstraint constraint) {
			return constraint.mixY;
		}

		public float value (Bone source, boolean local) {
			return local ? source.ay : source.worldY;
		}
	}

	static public class ToY extends ToProperty {
		public void apply (Bone target, float value, boolean local, boolean relative, float mix) {
			if (local) {
				if (!relative) value -= target.ay;
				target.ay += value * mix;
			} else {
				if (!relative) value -= target.worldY;
				target.worldY += value * mix;
			}
		}
	}

	static public class FromScaleX extends FromProperty {
		public float mix (TransformConstraint constraint) {
			return constraint.mixScaleX;
		}

		public float value (Bone source, boolean local) {
			return local ? source.ascaleX : (float)Math.sqrt(source.a * source.a + source.c * source.c);
		}
	}

	static public class ToScaleX extends ToProperty {
		public void apply (Bone target, float value, boolean local, boolean relative, float mix) {
			if (local) {
				if (relative)
					target.ascaleX *= 1 + ((value - 1) * mix);
				else if (target.ascaleX != 0) //
					target.ascaleX = 1 + (value / target.ascaleX - 1) * mix;
			} else {
				float s;
				if (relative)
					s = 1 + (value - 1) * mix;
				else {
					s = (float)Math.sqrt(target.a * target.a + target.c * target.c);
					if (s != 0) s = 1 + (value / s - 1) * mix;
				}
				target.a *= s;
				target.c *= s;
			}
		}
	}

	static public class FromScaleY extends FromProperty {
		public float mix (TransformConstraint constraint) {
			return constraint.mixScaleY;
		}

		public float value (Bone source, boolean local) {
			return local ? source.ascaleY : (float)Math.sqrt(source.b * source.b + source.d * source.d);
		}
	}

	static public class ToScaleY extends ToProperty {
		public void apply (Bone target, float value, boolean local, boolean relative, float mix) {
			if (local) {
				if (relative)
					target.ascaleY *= 1 + ((value - 1) * mix);
				else if (target.ascaleY != 0) //
					target.ascaleY = 1 + (value / target.ascaleY - 1) * mix;
			} else {
				float s;
				if (relative)
					s = 1 + (value - 1) * mix;
				else {
					s = (float)Math.sqrt(target.b * target.b + target.d * target.d);
					if (s != 0) s = 1 + (value / s - 1) * mix;
				}
				target.b *= s;
				target.d *= s;
			}
		}
	}

	static public class FromShearY extends FromProperty {
		public float mix (TransformConstraint constraint) {
			return constraint.mixShearY;
		}

		public float value (Bone source, boolean local) {
			return local ? source.ashearY : (atan2(source.d, source.b) - atan2(source.c, source.a)) * radDeg - 90;
		}
	}

	static public class ToShearY extends ToProperty {
		public void apply (Bone target, float value, boolean local, boolean relative, float mix) {
			if (local) {
				if (!relative) value -= target.ashearY;
				target.ashearY += value * mix;
			} else {
				float b = target.b, d = target.d, by = atan2(d, b);
				value = (value + 90) * degRad;
				if (relative)
					value -= PI / 2;
				else {
					value -= by - atan2(target.c, target.a);
					if (value > PI)
						value -= PI2;
					else if (value < -PI) //
						value += PI2;
				}
				value = by + value * mix;
				float s = (float)Math.sqrt(b * b + d * d);
				target.b = cos(value) * s;
				target.d = sin(value) * s;
			}
		}
	}
}
