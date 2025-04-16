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

import com.badlogic.gdx.graphics.Color;

/** Stores a slot's current pose. Slots organize attachments for {@link Skeleton#drawOrder} purposes and provide a place to store
 * state for an attachment. State cannot be stored in an attachment itself because attachments are stateless and may be shared
 * across multiple skeletons. */
public class Slot implements Constrained {
	final SlotData data;
	final Bone bone;
	final SlotPose pose = new SlotPose(), constrained = new SlotPose();
	SlotPose applied = pose;
	int attachmentState;

	public Slot (SlotData data, Skeleton skeleton) {
		if (data == null) throw new IllegalArgumentException("slot cannot be null.");
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");
		this.data = data;
		bone = skeleton.bones.get(data.boneData.index);
		if (data.setup.darkColor != null) {
			pose.darkColor = new Color();
			applied.darkColor = new Color();
		}
		setupPose();
	}

	/** Copy constructor. */
	public Slot (Slot slot, Bone bone) {
		if (slot == null) throw new IllegalArgumentException("slot cannot be null.");
		if (bone == null) throw new IllegalArgumentException("bone cannot be null.");
		data = slot.data;
		this.bone = bone;
		if (data.setup.darkColor != null) {
			pose.darkColor = new Color();
			applied.darkColor = new Color();
		}
		pose.set(slot.pose);
	}

	/** Sets this slot to the setup pose. */
	public void setupPose () {
		pose.set(data.setup);
		if (data.attachmentName != null) pose.setAttachment(bone.skeleton.getAttachment(data.index, data.attachmentName));
	}

	/** The slot's setup pose data. */
	public SlotData getData () {
		return data;
	}

	public SlotPose getPose () {
		return pose;
	}

	public SlotPose getAppliedPose () {
		return applied;
	}

	public SlotPose getConstrainedPose () {
		return constrained;
	}

	public void setConstrained (boolean constrained) {
		applied = constrained ? this.constrained : pose;
	}

	public void resetAppliedPose () {
		applied.set(pose);
	}

	/** The bone this slot belongs to. */
	public Bone getBone () {
		return bone;
	}

	/** The skeleton this slot belongs to. */
	public Skeleton getSkeleton () {
		return bone.skeleton;
	}

	public String toString () {
		return data.name;
	}
}
