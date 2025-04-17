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

/** Stores the setup pose for a {@link PathConstraint}.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-path-constraints">Path constraints</a> in the Spine User Guide. */
public class PathConstraintData extends PosedData<PathConstraintPose> {
	final Array<BoneData> bones = new Array();
	SlotData slot;
	PositionMode positionMode;
	SpacingMode spacingMode;
	RotateMode rotateMode;
	float offsetRotation;

	public PathConstraintData (String name) {
		super(name, new PathConstraintPose());
	}

	/** The bones that will be modified by this path constraint. */
	public Array<BoneData> getBones () {
		return bones;
	}

	/** The slot whose path attachment will be used to constrained the bones. */
	public SlotData getSlot () {
		return slot;
	}

	public void setSlot (SlotData slot) {
		if (slot == null) throw new IllegalArgumentException("slot cannot be null.");
		this.slot = slot;
	}

	/** The mode for positioning the first bone on the path. */
	public PositionMode getPositionMode () {
		return positionMode;
	}

	public void setPositionMode (PositionMode positionMode) {
		if (positionMode == null) throw new IllegalArgumentException("positionMode cannot be null.");
		this.positionMode = positionMode;
	}

	/** The mode for positioning the bones after the first bone on the path. */
	public SpacingMode getSpacingMode () {
		return spacingMode;
	}

	public void setSpacingMode (SpacingMode spacingMode) {
		if (spacingMode == null) throw new IllegalArgumentException("spacingMode cannot be null.");
		this.spacingMode = spacingMode;
	}

	/** The mode for adjusting the rotation of the bones. */
	public RotateMode getRotateMode () {
		return rotateMode;
	}

	public void setRotateMode (RotateMode rotateMode) {
		if (rotateMode == null) throw new IllegalArgumentException("rotateMode cannot be null.");
		this.rotateMode = rotateMode;
	}

	/** An offset added to the constrained bone rotation. */
	public float getOffsetRotation () {
		return offsetRotation;
	}

	public void setOffsetRotation (float offsetRotation) {
		this.offsetRotation = offsetRotation;
	}

	/** Controls how the first bone is positioned along the path.
	 * <p>
	 * See <a href="https://esotericsoftware.com/spine-path-constraints#Position-mode">Position mode</a> in the Spine User
	 * Guide. */
	static public enum PositionMode {
		fixed, percent;

		static public final PositionMode[] values = PositionMode.values();
	}

	/** Controls how bones after the first bone are positioned along the path.
	 * <p>
	 * See <a href="https://esotericsoftware.com/spine-path-constraints#Spacing-mode">Spacing mode</a> in the Spine User Guide. */
	static public enum SpacingMode {
		length, fixed, percent, proportional;

		static public final SpacingMode[] values = SpacingMode.values();
	}

	/** Controls how bones are rotated, translated, and scaled to match the path.
	 * <p>
	 * See <a href="https://esotericsoftware.com/spine-path-constraints#Rotate-Mix">Rotate mode</a> in the Spine User Guide. */
	static public enum RotateMode {
		tangent, chain,
		/** When chain scale, constrained bones should all have the same parent. That way when the path constraint scales a bone, it
		 * doesn't affect other constrained bones. */
		chainScale;

		static public final RotateMode[] values = RotateMode.values();
	}
}
