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

import static com.badlogic.gdx.math.MathUtils.*;

import com.badlogic.gdx.utils.Array;

import com.esotericsoftware.spine.TransformConstraintData.FromProperty;
import com.esotericsoftware.spine.TransformConstraintData.ToProperty;

/** Stores the current pose for a transform constraint. A transform constraint adjusts the world transform of the constrained
 * bones to match that of the source bone.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-transform-constraints">Transform constraints</a> in the Spine User Guide. */
public class TransformConstraint extends Constraint<TransformConstraint, TransformConstraintData, TransformConstraintPose> {
	final Array<BonePose> bones;
	Bone source;

	public TransformConstraint (TransformConstraintData data, Skeleton skeleton) {
		super(data, new TransformConstraintPose(), new TransformConstraintPose());
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");

		bones = new Array(data.bones.size);
		for (BoneData boneData : data.bones)
			bones.add(skeleton.bones.get(boneData.index).constrained);

		source = skeleton.bones.get(data.source.index);
	}

	public TransformConstraint copy (Skeleton skeleton) {
		var copy = new TransformConstraint(data, skeleton);
		copy.pose.set(pose);
		return copy;
	}

	/** Applies the constraint to the constrained bones. */
	public void update (Skeleton skeleton, Physics physics) {
		TransformConstraintPose pose = applied;
		if (pose.mixRotate == 0 && pose.mixX == 0 && pose.mixY == 0 && pose.mixScaleX == 0 && pose.mixScaleY == 0
			&& pose.mixShearY == 0) return;

		TransformConstraintData data = this.data;
		boolean localFrom = data.localSource, localTarget = data.localTarget, additive = data.additive, clamp = data.clamp;
		BonePose source = this.source.applied;
		Object[] fromItems = data.properties.items;
		int fn = data.properties.size;
		Object[] bones = this.bones.items;
		for (int i = 0, n = this.bones.size; i < n; i++) {
			var bone = (BonePose)bones[i];
			if (bone.bone.applied != bone.bone.constrained) System.out.println();
			for (int f = 0; f < fn; f++) {
				var from = (FromProperty)fromItems[f];
				float value = from.value(data, source, localFrom) - from.offset;
				Object[] toItems = from.to.items;
				for (int t = 0, tn = from.to.size; t < tn; t++) {
					var to = (ToProperty)toItems[t];
					if (to.mix(pose) != 0) {
						float clamped = to.offset + value * to.scale;
						if (clamp) {
							if (to.offset < to.max)
								clamped = clamp(clamped, to.offset, to.max);
							else
								clamped = clamp(clamped, to.max, to.offset);
						}
						to.apply(pose, bone, clamped, localTarget, additive);
					}
				}
			}
			if (localTarget)
				bone.update(skeleton, null);
			else
				bone.updateLocalTransform(skeleton);
		}
	}

	void sort (Skeleton skeleton) {
		skeleton.sortBone(source);

		Object[] bones = this.bones.items;
		int boneCount = this.bones.size;
		if (data.localSource) {
			for (int i = 0; i < boneCount; i++) {
				Bone child = ((BonePose)bones[i]).bone;
				skeleton.resetCache(child);
				skeleton.sortBone(child.parent);
				skeleton.sortBone(child);
			}
		} else {
			for (int i = 0; i < boneCount; i++) {
				Bone bone = ((BonePose)bones[i]).bone;
				skeleton.resetCache(bone);
				skeleton.sortBone(bone);
			}
		}

		skeleton.updateCache.add(this);

		for (int i = 0; i < boneCount; i++)
			skeleton.sortReset(((BonePose)bones[i]).bone.children);
		for (int i = 0; i < boneCount; i++)
			((BonePose)bones[i]).bone.sorted = true;
	}

	boolean isSourceActive () {
		return source.active;
	}

	/** The bones that will be modified by this transform constraint. */
	public Array<BonePose> getBones () {
		return bones;
	}

	/** The bone whose world transform will be copied to the constrained bones. */
	public Bone getSource () {
		return source;
	}

	public void setSource (Bone source) {
		if (source == null) throw new IllegalArgumentException("source cannot be null.");
		this.source = source;
	}
}
