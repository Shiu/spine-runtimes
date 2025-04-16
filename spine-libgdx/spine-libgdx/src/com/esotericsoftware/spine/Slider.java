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

import com.esotericsoftware.spine.Animation.MixBlend;
import com.esotericsoftware.spine.Animation.MixDirection;

/** Stores the setup pose for a {@link PhysicsConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-physics-constraints">Physics constraints</a> in the Spine User Guide. */
public class Slider implements Constrained, Update {
	final SliderData data;
	final Skeleton skeleton;
	final SliderPose pose = new SliderPose(), constrained = new SliderPose();
	SliderPose applied = pose;

	boolean active;

	public Slider (SliderData data, Skeleton skeleton) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");
		this.data = data;
		this.skeleton = skeleton;

		setupPose();
	}

	/** Copy constructor. */
	public Slider (Slider slider, Skeleton skeleton) {
		this(slider.data, skeleton);
		pose.set(slider.pose);
	}

	public void update (Physics physics) {
		SliderPose pose = applied;
		data.animation.apply(skeleton, pose.time, pose.time, false, null, pose.mix, MixBlend.replace, MixDirection.in, true);
	}

	public void setupPose () {
		pose.set(data.setup);
	}

	public SliderPose getPose () {
		return pose;
	}

	public SliderPose getAppliedPose () {
		return applied;
	}

	public SliderPose getConstrainedPose () {
		return constrained;
	}

	public void setConstrained (boolean constrained) {
		applied = constrained ? this.constrained : pose;
	}

	public void resetAppliedPose () {
		applied.set(pose);
	}

	/** Returns false when this constraint won't be updated by
	 * {@link Skeleton#updateWorldTransform(com.esotericsoftware.spine.Physics)} because a skin is required and the
	 * {@link Skeleton#getSkin() active skin} does not contain this item.
	 * @see Skin#getBones()
	 * @see Skin#getConstraints()
	 * @see ConstraintData#getSkinRequired()
	 * @see Skeleton#updateCache() */
	public boolean isActive () {
		return active;
	}

	public String toString () {
		return data.name;
	}
}
