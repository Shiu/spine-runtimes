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

import com.badlogic.gdx.utils.Null;

import com.esotericsoftware.spine.TransformConstraintData.FromProperty;

/** Stores the setup pose for a {@link PhysicsConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-physics-constraints">Physics constraints</a> in the Spine User Guide. */
public class SliderData extends ConstraintData<Slider, SliderPose> {
	Animation animation;
	boolean additive, loop;
	@Null BoneData bone;
	@Null FromProperty property;
	float offset, scale;
	boolean local;

	public SliderData (String name) {
		super(name, new SliderPose());
	}

	public Slider create (Skeleton skeleton) {
		return new Slider(this, skeleton);
	}

	public Animation getAnimation () {
		return animation;
	}

	public void setAnimation (Animation animation) {
		this.animation = animation;
	}

	public boolean getAdditive () {
		return additive;
	}

	public void setAdditive (boolean additive) {
		this.additive = additive;
	}

	public boolean getLoop () {
		return loop;
	}

	public void setLoop (boolean loop) {
		this.loop = loop;
	}

	public @Null BoneData getBone () {
		return bone;
	}

	public void setBone (@Null BoneData bone) {
		this.bone = bone;
	}

	public @Null FromProperty getProperty () {
		return property;
	}

	public void setProperty (@Null FromProperty property) {
		this.property = property;
	}

	public float getOffset () {
		return offset;
	}

	public void setOffset (float offset) {
		this.offset = offset;
	}

	public float getScale () {
		return scale;
	}

	public void setScale (float scale) {
		this.scale = scale;
	}

	public boolean getLocal () {
		return local;
	}

	public void setLocal (boolean local) {
		this.local = local;
	}
}
