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

import com.esotericsoftware.spine.Animation.BoneTimeline;
import com.esotericsoftware.spine.Animation.ConstraintTimeline;
import com.esotericsoftware.spine.Animation.MixBlend;
import com.esotericsoftware.spine.Animation.MixDirection;
import com.esotericsoftware.spine.Animation.PhysicsConstraintTimeline;
import com.esotericsoftware.spine.Animation.SlotTimeline;
import com.esotericsoftware.spine.Animation.Timeline;

/** Stores the setup pose for a {@link PhysicsConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-physics-constraints">Physics constraints</a> in the Spine User Guide. */
public class Slider extends Constraint<Slider, SliderData, SliderPose> {
	static private final float[] offsets = new float[6];

	Bone bone;

	public Slider (SliderData data, Skeleton skeleton) {
		super(data, new SliderPose(), new SliderPose());
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");

		if (data.bone != null) bone = skeleton.bones.items[data.bone.index];
	}

	public Slider copy (Skeleton skeleton) {
		var copy = new Slider(data, skeleton);
		copy.pose.set(pose);
		return copy;
	}

	public void update (Skeleton skeleton, Physics physics) {
		if (pose.mix == 0) return;

		Animation animation = data.animation;
		if (bone != null && bone.active) {
			pose.time = (data.property.value(bone.applied, data.local, offsets) - data.property.offset) * data.scale;
			if (data.loop)
				pose.time = animation.duration + (pose.time % animation.duration);
			else
				pose.time = Math.max(0, pose.time);
		}

		SliderData data = this.data;
		Timeline[] timelines = animation.timelines.items;
		int timelineCount = animation.timelines.size;
		Bone[] bones = skeleton.bones.items;
		if (pose.mix == 1) {
			for (int i = 0; i < timelineCount; i++)
				if (timelines[i] instanceof BoneTimeline timeline) bones[timeline.getBoneIndex()].resetUpdate(skeleton);
		} else {
			for (int i = 0; i < timelineCount; i++) {
				if (timelines[i] instanceof BoneTimeline timeline) {
					Bone bone = bones[timeline.getBoneIndex()];
					bone.resetUpdate(skeleton);
					if (bone.applied.local == skeleton.update) bone.applied.updateLocalTransform(skeleton);
				}
			}
		}

		SliderPose pose = applied;
		animation.apply(skeleton, pose.time, pose.time, data.loop, null, pose.mix, data.additive ? MixBlend.add : MixBlend.replace,
			MixDirection.in, true);
	}

	void sort (Skeleton skeleton) {
		Timeline[] timelines = data.animation.timelines.items;
		int timelineCount = data.animation.timelines.size;
		Bone[] bones = skeleton.bones.items;
		for (int i = 0; i < timelineCount; i++)
			if (timelines[i] instanceof BoneTimeline timeline) skeleton.sortBone(bones[timeline.getBoneIndex()]);

		skeleton.updateCache.add(this);

		Slot[] slots = skeleton.slots.items;
		Constraint[] constraints = skeleton.constraints.items;
		PhysicsConstraint[] physics = skeleton.physics.items;
		int physicsCount = skeleton.physics.size;
		for (int i = 0; i < timelineCount; i++) {
			Timeline t = timelines[i];
			if (t instanceof BoneTimeline timeline) {
				Bone bone = bones[timeline.getBoneIndex()];
				skeleton.resetCache(bone);
				skeleton.sortReset(bone.children);
				bone.sorted = false;
			} else if (t instanceof SlotTimeline timeline)
				skeleton.resetCache(slots[timeline.getSlotIndex()]);
			else if (t instanceof PhysicsConstraintTimeline timeline) {
				if (timeline.constraintIndex == -1) {
					for (int ii = 0; ii < physicsCount; ii++)
						skeleton.resetCache(physics[ii]);
				} else
					skeleton.resetCache(constraints[timeline.constraintIndex]);
			} else if (t instanceof ConstraintTimeline timeline) //
				skeleton.resetCache(constraints[timeline.getConstraintIndex()]);
		}
	}

	public Bone getBone () {
		return bone;
	}

	public void setBone (Bone bone) {
		this.bone = bone;
	}
}
