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
	public Slider (SliderData data) {
		super(data, new SliderPose(), new SliderPose());
	}

	public Slider copy (Skeleton skeleton) {
		var copy = new Slider(data);
		copy.pose.set(pose);
		return copy;
	}

	public void update (Skeleton skeleton, Physics physics) {
		if (pose.mix == 0) return;
		SliderPose pose = applied;
		data.animation.apply(skeleton, pose.time, pose.time, false, null, pose.mix, MixBlend.replace, MixDirection.in, true);
	}

	void sort (Skeleton skeleton) {
		Timeline[] timelines = data.animation.timelines.items;
		int timelineCount = data.animation.timelines.size;

		Bone[] bones = skeleton.bones.items;
		for (int i = 0; i < timelineCount; i++)
			if (timelines[i] instanceof BoneTimeline boneTimeline) skeleton.sortBone(bones[boneTimeline.getBoneIndex()]);

		skeleton.updateCache.add(this);

		Slot[] slots = skeleton.slots.items;
		for (int i = 0; i < timelineCount; i++) {
			Timeline t = timelines[i];
			if (t instanceof BoneTimeline timeline) {
				Bone bone = bones[timeline.getBoneIndex()];
				skeleton.sortReset(bone.children);
				bone.sorted = false;
			} else if (t instanceof SlotTimeline timeline)
				skeleton.resetCache(slots[timeline.getSlotIndex()]);
			else if (t instanceof PhysicsConstraintTimeline timeline) {
				if (timeline.constraintIndex == -1) {
					PhysicsConstraint[] constraints = skeleton.physics.items;
					for (int ii = 0, nn = skeleton.physics.size; ii < nn; ii++)
						skeleton.resetCache(constraints[ii]);
				} else
					skeleton.resetCache(skeleton.constraints.items[timeline.constraintIndex]);
			} else if (t instanceof ConstraintTimeline timeline) //
				skeleton.resetCache(skeleton.constraints.items[timeline.getConstraintIndex()]);
		}
	}
}
