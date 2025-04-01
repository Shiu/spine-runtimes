/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated July 28, 2023. Replaces all prior versions.
 *
 * Copyright (c) 2013-2023, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
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

import { ConstraintData } from "./ConstraintData.js";
import { BoneData } from "./BoneData.js";
import { Bone } from "./Bone.js";
import { TransformConstraint } from "./TransformConstraint.js";
import { MathUtils } from "./Utils.js";

/** Stores the setup pose for a {@link TransformConstraint}.
 *
 * See [Transform constraints](http://esotericsoftware.com/spine-transform-constraints) in the Spine User Guide. */
export class TransformConstraintData extends ConstraintData {

	/** The bones that will be modified by this transform constraint. */
	bones = new Array<BoneData>();

	/** The target bone whose world transform will be copied to the constrained bones. */
	private _target: BoneData | null = null;
	public set target (boneData: BoneData) { this._target = boneData; }
	public get target () {
		if (!this._target) throw new Error("BoneData not set.")
		else return this._target;
	}

	mixRotate = 0;
	mixX = 0;
	mixY = 0;
	mixScaleX = 0;
	mixScaleY = 0;
	mixShearY = 0;

	/** Reads the target bone's local transform instead of its world transform. */
	localFrom = false;

	/** Sets the constrained bones' local transforms instead of their world transforms. */
	localTo = false;

	/** Adds the target bone transform to the constrained bones instead of setting it absolutely. */
	relative = false;

	/** Prevents constrained bones from exceeding the ranged defined by {@link ToProperty#offset} and {@link ToProperty#max}. */
	clamp = false;

	/** The mapping of transform properties to other transform properties. */
	readonly properties: Array<FromProperty> = [];

	constructor (name: string) {
		super(name, 0, false);
	}

}

/** Source property for a {@link TransformConstraint}. */
export abstract class FromProperty {
	/** The value of this property that corresponds to {@link ToProperty#offset}. */
	offset = 0;

	/** Constrained properties. */
	readonly to: Array<ToProperty> = [];

	/** Reads this property from the specified bone. */
	abstract value (target: Bone, local: boolean): number;

	/** Reads the mix for this property from the specified constraint. */
	abstract mix (constraint: TransformConstraint): number;
}

/** Constrained property for a {@link TransformConstraint}. */
export abstract class ToProperty {
	/** The value of this property that corresponds to {@link FromProperty#offset}. */
	offset = 0;

	/** The maximum value of this property when {@link TransformConstraintData#clamp clamped}. */
	max = 0;

	/** The scale of the {@link FromProperty} value in relation to this property. */
	scale = 0;

	/** Applies the value to this property. */
	abstract apply (bone: Bone, value: number, local: boolean, relative: boolean, mix: number): void;
}

export class FromRotate extends FromProperty {
	value (target: Bone, local: boolean): number {
		return local ? target.arotation : Math.atan2(target.c, target.a) * MathUtils.radDeg;
	}

	mix (constraint: TransformConstraint): number {
		return constraint.mixRotate;
	}
}

export class ToRotate extends ToProperty {
	apply (bone: Bone, value: number, local: boolean, relative: boolean, mix: number): void {
		if (local) {
			if (!relative) value -= bone.arotation;
			bone.arotation += value * mix;
		} else {
			const a = bone.a, b = bone.b, c = bone.c, d = bone.d;
			value *= MathUtils.degRad;
			if (!relative) value -= Math.atan2(c, a);
			if (value > MathUtils.PI)
				value -= MathUtils.PI2;
			else if (value < -MathUtils.PI) //
				value += MathUtils.PI2;
			value *= mix;
			const cos = Math.cos(value), sin = Math.sin(value);
			bone.a = cos * a - sin * c;
			bone.b = cos * b - sin * d;
			bone.c = sin * a + cos * c;
			bone.d = sin * b + cos * d;
		}
	}
}

export class FromX extends FromProperty {
	value (target: Bone, local: boolean): number {
		return local ? target.ax : target.worldX;
	}

	mix (constraint: TransformConstraint): number {
		return constraint.mixX;
	}
}

export class ToX extends ToProperty {
	apply (bone: Bone, value: number, local: boolean, relative: boolean, mix: number): void {
		if (local) {
			if (!relative) value -= bone.ax;
			bone.ax += value * mix;
		} else {
			if (!relative) value -= bone.worldX;
			bone.worldX += value * mix;
		}
	}
}

export class FromY extends FromProperty {
	value (target: Bone, local: boolean): number {
		return local ? target.ay : target.worldY;
	}

	mix (constraint: TransformConstraint): number {
		return constraint.mixY;
	}
}

export class ToY extends ToProperty {
	apply (bone: Bone, value: number, local: boolean, relative: boolean, mix: number): void {
		if (local) {
			if (!relative) value -= bone.ay;
			bone.ay += value * mix;
		} else {
			if (!relative) value -= bone.worldY;
			bone.worldY += value * mix;
		}
	}
}

export class FromScaleX extends FromProperty {
	value (target: Bone, local: boolean): number {
		return local ? target.ascaleX : Math.sqrt(target.a * target.a + target.c * target.c);
	}

	mix (constraint: TransformConstraint): number {
		return constraint.mixScaleX;
	}
}

export class ToScaleX extends ToProperty {
	apply (bone: Bone, value: number, local: boolean, relative: boolean, mix: number): void {
		if (local) {
			if (relative)
				bone.ascaleX *= 1 + ((value - 1) * mix);
			else if (bone.ascaleX != 0) //
				bone.ascaleX = 1 + (value / bone.ascaleX - 1) * mix;
		} else {
			let s: number;
			if (relative)
				s = 1 + (value - 1) * mix;
			else {
				s = Math.sqrt(bone.a * bone.a + bone.c * bone.c);
				if (s != 0) s = 1 + (value / s - 1) * mix;
			}
			bone.a *= s;
			bone.c *= s;
		}
	}
}

export class FromScaleY extends FromProperty {
	value (target: Bone, local: boolean): number {
		return local ? target.ascaleY : Math.sqrt(target.b * target.b + target.d * target.d);
	}

	mix (constraint: TransformConstraint): number {
		return constraint.mixScaleY;
	}
}

export class ToScaleY extends ToProperty {
	apply (bone: Bone, value: number, local: boolean, relative: boolean, mix: number): void {
		if (local) {
			if (relative)
				bone.ascaleY *= 1 + ((value - 1) * mix);
			else if (bone.ascaleY != 0) //
				bone.ascaleY = 1 + (value / bone.ascaleY - 1) * mix;
		} else {
			let s: number;
			if (relative)
				s = 1 + (value - 1) * mix;
			else {
				s = Math.sqrt(bone.b * bone.b + bone.d * bone.d);
				if (s != 0) s = 1 + (value / s - 1) * mix;
			}
			bone.b *= s;
			bone.d *= s;
		}
	}
}

export class FromShearY extends FromProperty {
	value (target: Bone, local: boolean): number {
		return local ? target.ashearY : (Math.atan2(target.d, target.b) - Math.atan2(target.c, target.a)) * MathUtils.radDeg - 90;
	}

	mix (constraint: TransformConstraint): number {
		return constraint.mixShearY;
	}
}

export class ToShearY extends ToProperty {
	apply (bone: Bone, value: number, local: boolean, relative: boolean, mix: number): void {
		if (local) {
			if (!relative) value -= bone.ashearY;
			bone.ashearY += value * mix;
		} else {
			const b = bone.b, d = bone.d, by = Math.atan2(d, b);
			value = (value + 90) * MathUtils.degRad;
			if (relative)
				value -= MathUtils.PI / 2;
			else {
				value -= by - Math.atan2(bone.c, bone.a);
				if (value > MathUtils.PI)
					value -= MathUtils.PI2;
				else if (value < -MathUtils.PI) //
					value += MathUtils.PI2;
			}
			value = by + value * mix;
			const s = Math.sqrt(b * b + d * d);
			bone.b = Math.cos(value) * s;
			bone.d = Math.sin(value) * s;
		}
	}
}