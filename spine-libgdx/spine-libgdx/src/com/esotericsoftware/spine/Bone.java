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

import com.badlogic.gdx.utils.Array;
import com.badlogic.gdx.utils.Null;

/** Stores a bone's current pose.
 * <p>
 * A bone has a local transform which is used to compute its world transform. A bone also has an applied transform, which is a
 * local transform that can be applied to compute the world transform. The local transform and applied transform may differ if a
 * constraint or application code modifies the world transform after it was computed from the local transform. */
public class Bone extends BonePose {
	final BoneData data;
	final Skeleton skeleton;
	@Null final Bone parent;
	final Array<Bone> children;
	final BoneApplied applied = new BoneApplied(this);

	boolean sorted, active;

	public Bone (BoneData data, Skeleton skeleton, @Null Bone parent) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");
		this.data = data;
		this.skeleton = skeleton;
		this.parent = parent;
		children = new Array();

		setToSetupPose();
	}

	/** Copy constructor. Does not copy the {@link #getChildren()} bones. */
	public Bone (Bone bone, Skeleton skeleton, @Null Bone parent) {
		super(bone);
		this.skeleton = skeleton;
		this.parent = parent;
		children = new Array();
		data = bone.data;
	}

	/** Sets this bone's local transform to the setup pose. */
	public void setToSetupPose () {
		BoneData data = this.data;
		x = data.x;
		y = data.y;
		rotation = data.rotation;
		scaleX = data.scaleX;
		scaleY = data.scaleY;
		shearX = data.shearX;
		shearY = data.shearY;
		inherit = data.inherit;
	}

	/** The bone's setup pose data. */
	public BoneData getData () {
		return data;
	}

	/** The skeleton this bone belongs to. */
	public Skeleton getSkeleton () {
		return skeleton;
	}

	/** The parent bone, or null if this is the root bone. */
	public @Null Bone getParent () {
		return parent;
	}

	/** The immediate children of this bone. */
	public Array<Bone> getChildren () {
		return children;
	}

	/** Returns false when this bone won't be updated by
	 * {@link Skeleton#updateWorldTransform(com.esotericsoftware.spine.Skeleton.Physics)} because a skin is required and the
	 * {@link Skeleton#getSkin() active skin} does not contain this item.
	 * @see Skin#getBones()
	 * @see Skin#getConstraints()
	 * @see BoneData#getSkinRequired()
	 * @see Skeleton#updateCache() */
	public boolean isActive () {
		return active;
	}

	/** Returns the bone for applied pose. */
	public BoneApplied getApplied () {
		return applied;
	}

	public String toString () {
		return data.name;
	}
}
