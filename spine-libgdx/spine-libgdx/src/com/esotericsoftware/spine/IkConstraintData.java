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

/** Stores the setup pose for an {@link IkConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-ik-constraints">IK constraints</a> in the Spine User Guide. */
public class IkConstraintData extends ConstraintData<IkConstraint, IkConstraintPose> {
	final Array<BoneData> bones = new Array();
	BoneData target;
	boolean uniform;

	public IkConstraintData (String name) {
		super(name, new IkConstraintPose());
	}

	public IkConstraint create (Skeleton skeleton) {
		return new IkConstraint(this, skeleton);
	}

	/** The bones that are constrained by this IK constraint. */
	public Array<BoneData> getBones () {
		return bones;
	}

	/** The bone that is the IK target. */
	public BoneData getTarget () {
		return target;
	}

	public void setTarget (BoneData target) {
		if (target == null) throw new IllegalArgumentException("target cannot be null.");
		this.target = target;
	}

	/** When true and {@link IkConstraintPose#getCompress()} or {@link IkConstraintPose#getStretch()} is used, the bone is scaled
	 * on both the X and Y axes. */
	public boolean getUniform () {
		return uniform;
	}

	public void setUniform (boolean uniform) {
		this.uniform = uniform;
	}
}
