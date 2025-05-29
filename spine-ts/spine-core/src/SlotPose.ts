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

import { Pose } from "./Pose";
import { Color } from "./Utils";

import { VertexAttachment } from "./attachments/Attachment";
import { Attachment } from "./attachments/Attachment";
import type { Sequence } from "./attachments/Sequence";

/** Stores a slot's pose. Slots organize attachments for {@link Skeleton#drawOrder} purposes and provide a place to store state
 * for an attachment. State cannot be stored in an attachment itself because attachments are stateless and may be shared across
 * multiple skeletons. */
export class SlotPose implements Pose<SlotPose> {
	/** The color used to tint the slot's attachment. If {@link darkColor} is set, this is used as the light color for two
	 * color tinting. */
	readonly color = new Color(1, 1, 1, 1);

	/** The dark color used to tint the slot's attachment for two color tinting, or null if two color tinting is not used. The dark
	 * color's alpha is not used. */
	darkColor: Color | null = null;

	/** The current attachment for the slot, or null if the slot has no attachment. */
	attachment: Attachment | null = null; // Not used in setup pose.

	/** The index of the texture region to display when the slot's attachment has a {@link Sequence}. -1 represents the
	 * {@link Sequence.getSetupIndex()}. */
	sequenceIndex = 0;

	/** Values to deform the slot's attachment. For an unweighted mesh, the entries are local positions for each vertex. For a
	 * weighted mesh, the entries are an offset for each vertex which will be added to the mesh's local vertex positions.
	 *
	 * See {@link VertexAttachment.computeWorldVertices()} and
	 * {@link DeformTimeline}. */
	readonly deform = new Array<number>();

	SlotPose () {
	}

	public set (pose: SlotPose): void {
		if (pose == null) throw new Error("pose cannot be null.");
		this.color.setFromColor(pose.color);
		if (this.darkColor != null && pose.darkColor != null) this.darkColor.setFromColor(pose.darkColor);
		this.attachment = pose.attachment;
		this.sequenceIndex = pose.sequenceIndex;
		this.deform.length = 0;
		this.deform.push(...pose.deform);
	}

	/** The current attachment for the slot, or null if the slot has no attachment. */
	getAttachment (): Attachment | null {
		return this.attachment;
	}

	/** Sets the slot's attachment and, if the attachment changed, resets {@link #sequenceIndex} and clears the {@link #deform}.
	 * The deform is not cleared if the old attachment has the same {@link VertexAttachment.getTimelineAttachment()} as the
	 * specified attachment. */
	setAttachment (attachment: Attachment | null): void {
		if (this.attachment == attachment) return;
		if (!(attachment instanceof VertexAttachment) || !(this.attachment instanceof VertexAttachment)
			|| attachment.timelineAttachment != this.attachment.timelineAttachment) {
			this.deform.length = 0;
		}
		this.attachment = attachment;
		this.sequenceIndex = -1;
	}
}
