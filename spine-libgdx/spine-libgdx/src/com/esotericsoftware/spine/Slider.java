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
import com.esotericsoftware.spine.Skeleton.Physics;

/** Stores the setup pose for a {@link PhysicsConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-physics-constraints">Physics constraints</a> in the Spine User Guide. */
public class Slider implements Updatable {
	final SliderData data;
	final Skeleton skeleton;
	Animation animation;
	float time, mix;

	boolean active;

	public Slider (SliderData data, Skeleton skeleton) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");
		this.data = data;
		this.skeleton = skeleton;

		setToSetupPose();
	}

	/** Copy constructor. */
	public Slider (Slider slider, Skeleton skeleton) {
		this(slider.data, skeleton);
		setToSetupPose();
	}

	public void update (Physics physics) {
		animation.apply(skeleton, time, time, false, null, mix, MixBlend.replace, MixDirection.in, true);
	}

	public void setToSetupPose () {
		SliderData data = this.data;
		animation = data.animation;
		time = data.time;
		mix = data.mix;
	}

	/** Returns false when this constraint won't be updated by
	 * {@link Skeleton#updateWorldTransform(com.esotericsoftware.spine.Skeleton.Physics)} because a skin is required and the
	 * {@link Skeleton#getSkin() active skin} does not contain this item.
	 * @see Skin#getBones()
	 * @see Skin#getConstraints()
	 * @see ConstraintData#getSkinRequired()
	 * @see Skeleton#updateCache() */
	public boolean isActive () {
		return active;
	}

	public Animation getAnimation () {
		return animation;
	}

	public void setAnimation (Animation animation) {
		this.animation = animation;
	}

	public float getTime () {
		return time;
	}

	public void setTime (float time) {
		this.time = time;
	}

	public float getMix () {
		return mix;
	}

	public void setMix (float mix) {
		this.mix = mix;
	}
}
