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

import static com.esotericsoftware.spine.utils.SpineUtils.*;

import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.utils.Array;
import com.badlogic.gdx.utils.FloatArray;
import com.badlogic.gdx.utils.Null;

import com.esotericsoftware.spine.Animation.BoneTimeline;
import com.esotericsoftware.spine.Animation.Timeline;
import com.esotericsoftware.spine.Skin.SkinEntry;
import com.esotericsoftware.spine.attachments.Attachment;
import com.esotericsoftware.spine.attachments.ClippingAttachment;
import com.esotericsoftware.spine.attachments.MeshAttachment;
import com.esotericsoftware.spine.attachments.PathAttachment;
import com.esotericsoftware.spine.attachments.RegionAttachment;
import com.esotericsoftware.spine.utils.SkeletonClipping;

/** Stores the current pose for a skeleton.
 * <p>
 * See <a href="https://esotericsoftware.com/spine-runtime-architecture#Instance-objects">Instance objects</a> in the Spine
 * Runtimes Guide. */
public class Skeleton {
	static private final short[] quadTriangles = {0, 1, 2, 2, 3, 0};

	final SkeletonData data;
	final Array<Bone> bones;
	final Array<Slot> slots;
	Array<Slot> drawOrder;
	final Array<Slider> sliders;
	final Array<IkConstraint> ikConstraints;
	final Array<TransformConstraint> transformConstraints;
	final Array<PathConstraint> pathConstraints;
	final Array<PhysicsConstraint> physicsConstraints;
	final Array updateCache = new Array();
	final Array<Constrained> resetCache = new Array();
	@Null Skin skin;
	final Color color;
	float x, y, scaleX = 1, scaleY = 1, time;

	public Skeleton (SkeletonData data) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		this.data = data;

		bones = new Array(data.bones.size);
		Object[] bones = this.bones.items;
		for (BoneData boneData : data.bones) {
			Bone bone;
			if (boneData.parent == null)
				bone = new Bone(boneData, this, null);
			else {
				var parent = (Bone)bones[boneData.parent.index];
				bone = new Bone(boneData, this, parent);
				parent.children.add(bone);
			}
			this.bones.add(bone);
		}

		slots = new Array(data.slots.size);
		drawOrder = new Array(data.slots.size);
		for (SlotData slotData : data.slots) {
			var slot = new Slot(slotData, this);
			slots.add(slot);
			drawOrder.add(slot);
		}

		sliders = new Array(data.sliders.size);
		for (SliderData constraint : data.sliders)
			sliders.add(new Slider(constraint, this));

		ikConstraints = new Array(data.ikConstraints.size);
		for (IkConstraintData constraint : data.ikConstraints)
			ikConstraints.add(new IkConstraint(constraint, this));

		transformConstraints = new Array(data.transformConstraints.size);
		for (TransformConstraintData constraint : data.transformConstraints)
			transformConstraints.add(new TransformConstraint(constraint, this));

		pathConstraints = new Array(data.pathConstraints.size);
		for (PathConstraintData constraint : data.pathConstraints)
			pathConstraints.add(new PathConstraint(constraint, this));

		physicsConstraints = new Array(data.physicsConstraints.size);
		for (PhysicsConstraintData constraint : data.physicsConstraints)
			physicsConstraints.add(new PhysicsConstraint(constraint, this));

		color = new Color(1, 1, 1, 1);

		updateCache();
	}

	/** Copy constructor. */
	public Skeleton (Skeleton skeleton) {
		if (skeleton == null) throw new IllegalArgumentException("skeleton cannot be null.");
		data = skeleton.data;

		bones = new Array(skeleton.bones.size);
		for (Bone bone : skeleton.bones) {
			Bone newBone;
			if (bone.parent == null)
				newBone = new Bone(bone, this, null);
			else {
				Bone parent = bones.get(bone.parent.data.index);
				newBone = new Bone(bone, this, parent);
				parent.children.add(newBone);
			}
			bones.add(newBone);
		}

		slots = new Array(skeleton.slots.size);
		for (Slot slot : skeleton.slots) {
			Bone bone = bones.get(slot.bone.data.index);
			slots.add(new Slot(slot, bone));
		}

		drawOrder = new Array(slots.size);
		for (Slot slot : skeleton.drawOrder)
			drawOrder.add(slots.get(slot.data.index));

		sliders = new Array(skeleton.sliders.size);
		for (Slider constraint : skeleton.sliders)
			sliders.add(new Slider(constraint, skeleton));

		ikConstraints = new Array(skeleton.ikConstraints.size);
		for (IkConstraint constraint : skeleton.ikConstraints)
			ikConstraints.add(new IkConstraint(constraint, skeleton));

		transformConstraints = new Array(skeleton.transformConstraints.size);
		for (TransformConstraint constraint : skeleton.transformConstraints)
			transformConstraints.add(new TransformConstraint(constraint, skeleton));

		pathConstraints = new Array(skeleton.pathConstraints.size);
		for (PathConstraint constraint : skeleton.pathConstraints)
			pathConstraints.add(new PathConstraint(constraint, skeleton));

		physicsConstraints = new Array(skeleton.physicsConstraints.size);
		for (PhysicsConstraint constraint : skeleton.physicsConstraints)
			physicsConstraints.add(new PhysicsConstraint(constraint, skeleton));

		skin = skeleton.skin;
		color = new Color(skeleton.color);
		x = skeleton.x;
		y = skeleton.y;
		scaleX = skeleton.scaleX;
		scaleY = skeleton.scaleY;
		time = skeleton.time;

		updateCache();
	}

	/** Caches information about bones and constraints. Must be called if the {@link #getSkin()} is modified or if bones,
	 * constraints, or weighted path attachments are added or removed. */
	public void updateCache () {
		updateCache.clear();
		resetCache.clear();

		int boneCount = bones.size;
		Object[] bones = this.bones.items;
		for (int i = 0; i < boneCount; i++) {
			var bone = (Bone)bones[i];
			bone.sorted = bone.data.skinRequired;
			bone.active = !bone.sorted;
			bone.setConstrained(false);
		}
		if (skin != null) {
			Object[] skinBones = skin.bones.items;
			for (int i = 0, n = skin.bones.size; i < n; i++) {
				var bone = (Bone)bones[((BoneData)skinBones[i]).index];
				do {
					bone.sorted = false;
					bone.active = true;
					bone = bone.parent;
				} while (bone != null);
			}
		}

		int sliderCount = sliders.size, ikCount = ikConstraints.size, transformCount = transformConstraints.size,
			pathCount = pathConstraints.size, physicsCount = physicsConstraints.size;
		Object[] sliders = this.sliders.items, ikConstraints = this.ikConstraints.items,
			transformConstraints = this.transformConstraints.items, pathConstraints = this.pathConstraints.items,
			physicsConstraints = this.physicsConstraints.items;
		for (int ii = 0; ii < sliderCount; ii++)
			((Slider)sliders[ii]).setConstrained(false);
		for (int ii = 0; ii < ikCount; ii++)
			((IkConstraint)ikConstraints[ii]).setConstrained(false);
		for (int ii = 0; ii < transformCount; ii++)
			((TransformConstraint)transformConstraints[ii]).setConstrained(false);
		for (int ii = 0; ii < pathCount; ii++)
			((PathConstraint)pathConstraints[ii]).setConstrained(false);
		for (int ii = 0; ii < physicsCount; ii++)
			((PhysicsConstraint)physicsConstraints[ii]).setConstrained(false);

		int constraintCount = ikCount + transformCount + pathCount + physicsCount;
		outer:
		for (int i = 0; i < constraintCount; i++) {
			for (int ii = 0; ii < sliderCount; ii++) {
				var constraint = (Slider)sliders[ii];
				if (constraint.data.order == i) {
					sortSlider(constraint);
					continue outer;
				}
			}
			for (int ii = 0; ii < ikCount; ii++) {
				var constraint = (IkConstraint)ikConstraints[ii];
				if (constraint.data.order == i) {
					sortIkConstraint(constraint);
					continue outer;
				}
			}
			for (int ii = 0; ii < transformCount; ii++) {
				var constraint = (TransformConstraint)transformConstraints[ii];
				if (constraint.data.order == i) {
					sortTransformConstraint(constraint);
					continue outer;
				}
			}
			for (int ii = 0; ii < pathCount; ii++) {
				var constraint = (PathConstraint)pathConstraints[ii];
				if (constraint.data.order == i) {
					sortPathConstraint(constraint);
					continue outer;
				}
			}
			for (int ii = 0; ii < physicsCount; ii++) {
				var constraint = (PhysicsConstraint)physicsConstraints[ii];
				if (constraint.data.order == i) {
					sortPhysicsConstraint(constraint);
					continue outer;
				}
			}
		}

		for (int i = 0; i < boneCount; i++)
			sortBone((Bone)bones[i]);

		Object[] updateCache = this.updateCache.items;
		for (int i = 0, n = this.updateCache.size; i < n; i++)
			if (updateCache[i] instanceof Bone bone) updateCache[i] = bone.applied;
	}

	private void sortIkConstraint (IkConstraint constraint) {
		constraint.active = constraint.target.active
			&& (!constraint.data.skinRequired || (skin != null && skin.constraints.contains(constraint.data, true)));
		if (!constraint.active) return;

		sortBone(constraint.target);

		Array<BoneApplied> constrained = constraint.bones;
		Bone parent = constrained.first().bone;
		sortBone(parent);
		resetCache(parent);
		if (constrained.size == 1) {
			updateCache.add(constraint);
			sortReset(parent.children);
		} else {
			Bone child = constrained.peek().bone;
			resetCache(child);
			sortBone(child);

			updateCache.add(constraint);

			sortReset(parent.children);
			child.sorted = true;
		}
	}

	private void sortTransformConstraint (TransformConstraint constraint) {
		constraint.active = constraint.source.active
			&& (!constraint.data.skinRequired || (skin != null && skin.constraints.contains(constraint.data, true)));
		if (!constraint.active) return;

		sortBone(constraint.source);

		Object[] constrained = constraint.bones.items;
		int boneCount = constraint.bones.size;
		if (constraint.data.localSource) {
			for (int i = 0; i < boneCount; i++) {
				Bone child = ((BoneApplied)constrained[i]).bone;
				resetCache(child);
				sortBone(child.parent);
				sortBone(child);
			}
		} else {
			for (int i = 0; i < boneCount; i++) {
				Bone bone = ((BoneApplied)constrained[i]).bone;
				resetCache(bone);
				sortBone(bone);
			}
		}

		updateCache.add(constraint);

		for (int i = 0; i < boneCount; i++)
			sortReset(((BoneApplied)constrained[i]).bone.children);
		for (int i = 0; i < boneCount; i++)
			((BoneApplied)constrained[i]).bone.sorted = true;
	}

	private void sortPathConstraint (PathConstraint constraint) {
		constraint.active = constraint.slot.bone.active
			&& (!constraint.data.skinRequired || (skin != null && skin.constraints.contains(constraint.data, true)));
		if (!constraint.active) return;

		Slot slot = constraint.slot;
		int slotIndex = slot.getData().index;
		Bone slotBone = slot.bone;
		if (skin != null) sortPathConstraintAttachment(skin, slotIndex, slotBone);
		if (data.defaultSkin != null && data.defaultSkin != skin)
			sortPathConstraintAttachment(data.defaultSkin, slotIndex, slotBone);

		sortPathConstraintAttachment(slot.pose.attachment, slotBone);

		Object[] constrained = constraint.bones.items;
		int boneCount = constraint.bones.size;
		for (int i = 0; i < boneCount; i++) {
			Bone bone = ((BoneApplied)constrained[i]).bone;
			resetCache(bone);
			sortBone(bone);
		}

		updateCache.add(constraint);

		for (int i = 0; i < boneCount; i++)
			sortReset(((BoneApplied)constrained[i]).bone.children);
		for (int i = 0; i < boneCount; i++)
			((BoneApplied)constrained[i]).bone.sorted = true;
	}

	private void sortPathConstraintAttachment (Skin skin, int slotIndex, Bone slotBone) {
		Object[] entries = skin.attachments.orderedItems().items;
		for (int i = 0, n = skin.attachments.size; i < n; i++) {
			var entry = (SkinEntry)entries[i];
			if (entry.slotIndex == slotIndex) sortPathConstraintAttachment(entry.attachment, slotBone);
		}
	}

	private void sortPathConstraintAttachment (Attachment attachment, Bone slotBone) {
		if (!(attachment instanceof PathAttachment pathAttachment)) return;
		int[] pathBones = pathAttachment.getBones();
		if (pathBones == null)
			sortBone(slotBone);
		else {
			Object[] bones = this.bones.items;
			for (int i = 0, n = pathBones.length; i < n;) {
				int nn = pathBones[i++];
				nn += i;
				while (i < nn)
					sortBone((Bone)bones[pathBones[i++]]);
			}
		}
	}

	private void sortPhysicsConstraint (PhysicsConstraint constraint) {
		Bone bone = constraint.bone.bone;
		constraint.active = bone.active
			&& (!constraint.data.skinRequired || (skin != null && skin.constraints.contains(constraint.data, true)));
		if (!constraint.active) return;

		sortBone(bone);

		resetCache(bone);
		updateCache.add(constraint);

		sortReset(bone.children);
		bone.sorted = true;
	}

	private void sortSlider (Slider constraint) {
		constraint.active = !constraint.data.skinRequired || (skin != null && skin.constraints.contains(constraint.data, true));
		if (!constraint.active) return;

		Object[] timelines = constraint.data.animation.timelines.items;
		int timelineCount = constraint.data.animation.timelines.size;

		Object[] bones = this.bones.items;
		for (int i = 0; i < timelineCount; i++) {
			var timeline = (Timeline)timelines[i];
			if (timeline instanceof BoneTimeline boneTimeline) sortBone((Bone)bones[boneTimeline.getBoneIndex()]);
		}

		updateCache.add(constraint);

		for (int i = 0; i < timelineCount; i++) {
			if (timelines[i] instanceof BoneTimeline boneTimeline) {
				var bone = (Bone)bones[boneTimeline.getBoneIndex()];
				resetCache(bone);
				sortReset(bone.children);
				bone.sorted = false;
			}
		}
		for (int i = 0; i < timelineCount; i++)
			if (timelines[i] instanceof BoneTimeline boneTimeline) sortBone((Bone)bones[boneTimeline.getBoneIndex()]);
	}

	private void resetCache (Constrained object) {
		if (!resetCache.contains(object, true)) {
			resetCache.add(object);
			object.setConstrained(true);
		}
	}

	private void sortBone (Bone bone) {
		if (bone.sorted) return;
		Bone parent = bone.parent;
		if (parent != null) sortBone(parent);
		bone.sorted = true;
		updateCache.add(bone);
	}

	private void sortReset (Array<Bone> bones) {
		Object[] items = bones.items;
		for (int i = 0, n = bones.size; i < n; i++) {
			var bone = (Bone)items[i];
			if (!bone.active) continue;
			if (bone.sorted) sortReset(bone.children);
			bone.sorted = false;
		}
	}

	/** Updates the world transform for each bone and applies all constraints.
	 * <p>
	 * See <a href="https://esotericsoftware.com/spine-runtime-skeletons#World-transforms">World transforms</a> in the Spine
	 * Runtimes Guide. */
	public void updateWorldTransform (Physics physics) {
		Object[] resetCache = this.resetCache.items;
		for (int i = 0, n = this.resetCache.size; i < n; i++)
			((Constrained)resetCache[i]).resetAppliedPose();

		Object[] updateCache = this.updateCache.items;
		for (int i = 0, n = this.updateCache.size; i < n; i++)
			((Update)updateCache[i]).update(physics);
	}

	/** Temporarily sets the root bone as a child of the specified bone, then updates the world transform for each bone and applies
	 * all constraints.
	 * <p>
	 * See <a href="https://esotericsoftware.com/spine-runtime-skeletons#World-transforms">World transforms</a> in the Spine
	 * Runtimes Guide. */
	public void updateWorldTransform (Physics physics, BoneApplied parent) {
		if (parent == null) throw new IllegalArgumentException("parent cannot be null.");

		Object[] resetCache = this.resetCache.items;
		for (int i = 0, n = this.resetCache.size; i < n; i++)
			((Constrained)resetCache[i]).resetAppliedPose();

		// Apply the parent bone transform to the root bone. The root bone always inherits scale, rotation and reflection.
		BoneApplied rootBone = getRootBone().applied;
		float pa = parent.a, pb = parent.b, pc = parent.c, pd = parent.d;
		rootBone.worldX = pa * x + pb * y + parent.worldX;
		rootBone.worldY = pc * x + pd * y + parent.worldY;

		float rx = (rootBone.rotation + rootBone.shearX) * degRad;
		float ry = (rootBone.rotation + 90 + rootBone.shearY) * degRad;
		float la = cos(rx) * rootBone.scaleX;
		float lb = cos(ry) * rootBone.scaleY;
		float lc = sin(rx) * rootBone.scaleX;
		float ld = sin(ry) * rootBone.scaleY;
		rootBone.a = (pa * la + pb * lc) * scaleX;
		rootBone.b = (pa * lb + pb * ld) * scaleX;
		rootBone.c = (pc * la + pd * lc) * scaleY;
		rootBone.d = (pc * lb + pd * ld) * scaleY;

		// Update everything except root bone.
		Object[] updateCache = this.updateCache.items;
		for (int i = 0, n = this.updateCache.size; i < n; i++) {
			var updatable = (Update)updateCache[i];
			if (updatable != rootBone) updatable.update(physics);
		}
	}

	/** Sets the bones, constraints, slots, and draw order to their setup pose values. */
	public void setupPose () {
		setupPoseBones();
		setupPoseSlots();
	}

	/** Sets the bones and constraints to their setup pose values. */
	public void setupPoseBones () {
		Object[] bones = this.bones.items;
		for (int i = 0, n = this.bones.size; i < n; i++)
			((Bone)bones[i]).setupPose();

		Object[] constraints = sliders.items;
		for (int i = 0, n = sliders.size; i < n; i++)
			((Slider)constraints[i]).setupPose();

		constraints = ikConstraints.items;
		for (int i = 0, n = ikConstraints.size; i < n; i++)
			((IkConstraint)constraints[i]).setupPose();

		constraints = transformConstraints.items;
		for (int i = 0, n = transformConstraints.size; i < n; i++)
			((TransformConstraint)constraints[i]).setupPose();

		constraints = pathConstraints.items;
		for (int i = 0, n = pathConstraints.size; i < n; i++)
			((PathConstraint)constraints[i]).setupPose();

		constraints = physicsConstraints.items;
		for (int i = 0, n = physicsConstraints.size; i < n; i++)
			((PhysicsConstraint)constraints[i]).setupPose();
	}

	/** Sets the slots and draw order to their setup pose values. */
	public void setupPoseSlots () {
		Object[] slots = this.slots.items;
		int n = this.slots.size;
		arraycopy(slots, 0, drawOrder.items, 0, n);
		for (int i = 0; i < n; i++)
			((Slot)slots[i]).setupPose();
	}

	/** The skeleton's setup pose data. */
	public SkeletonData getData () {
		return data;
	}

	/** The skeleton's bones, sorted parent first. The root bone is always the first bone. */
	public Array<Bone> getBones () {
		return bones;
	}

	/** The list of bones and constraints, sorted in the order they should be updated, as computed by {@link #updateCache()}. */
	public Array<Update> getUpdateCache () {
		return updateCache;
	}

	/** Returns the root bone, or null if the skeleton has no bones. */
	public Bone getRootBone () {
		return bones.size == 0 ? null : bones.first();
	}

	/** Finds a bone by comparing each bone's name. It is more efficient to cache the results of this method than to call it
	 * repeatedly. */
	public @Null Bone findBone (String boneName) {
		if (boneName == null) throw new IllegalArgumentException("boneName cannot be null.");
		Object[] bones = this.bones.items;
		for (int i = 0, n = this.bones.size; i < n; i++) {
			var bone = (Bone)bones[i];
			if (bone.data.name.equals(boneName)) return bone;
		}
		return null;
	}

	/** The skeleton's slots. */
	public Array<Slot> getSlots () {
		return slots;
	}

	/** Finds a slot by comparing each slot's name. It is more efficient to cache the results of this method than to call it
	 * repeatedly. */
	public @Null Slot findSlot (String slotName) {
		if (slotName == null) throw new IllegalArgumentException("slotName cannot be null.");
		Object[] slots = this.slots.items;
		for (int i = 0, n = this.slots.size; i < n; i++) {
			var slot = (Slot)slots[i];
			if (slot.data.name.equals(slotName)) return slot;
		}
		return null;
	}

	/** The skeleton's slots in the order they should be drawn. The returned array may be modified to change the draw order. */
	public Array<Slot> getDrawOrder () {
		return drawOrder;
	}

	public void setDrawOrder (Array<Slot> drawOrder) {
		if (drawOrder == null) throw new IllegalArgumentException("drawOrder cannot be null.");
		this.drawOrder = drawOrder;
	}

	/** The skeleton's current skin. */
	public @Null Skin getSkin () {
		return skin;
	}

	/** Sets a skin by name.
	 * <p>
	 * See {@link #setSkin(Skin)}. */
	public void setSkin (String skinName) {
		Skin skin = data.findSkin(skinName);
		if (skin == null) throw new IllegalArgumentException("Skin not found: " + skinName);
		setSkin(skin);
	}

	/** Sets the skin used to look up attachments before looking in the {@link SkeletonData#getDefaultSkin() default skin}. If the
	 * skin is changed, {@link #updateCache()} is called.
	 * <p>
	 * Attachments from the new skin are attached if the corresponding attachment from the old skin was attached. If there was no
	 * old skin, each slot's setup mode attachment is attached from the new skin.
	 * <p>
	 * After changing the skin, the visible attachments can be reset to those attached in the setup pose by calling
	 * {@link #setupPoseSlots()}. Also, often {@link AnimationState#apply(Skeleton)} is called before the next time the skeleton is
	 * rendered to allow any attachment keys in the current animation(s) to hide or show attachments from the new skin. */
	public void setSkin (@Null Skin newSkin) {
		if (newSkin == skin) return;
		if (newSkin != null) {
			if (skin != null)
				newSkin.attachAll(this, skin);
			else {
				Object[] slots = this.slots.items;
				for (int i = 0, n = this.slots.size; i < n; i++) {
					var slot = (Slot)slots[i];
					String name = slot.data.attachmentName;
					if (name != null) {
						Attachment attachment = newSkin.getAttachment(i, name);
						if (attachment != null) slot.pose.setAttachment(attachment);
					}
				}
			}
		}
		skin = newSkin;
		updateCache();
	}

	/** Finds an attachment by looking in the {@link #skin} and {@link SkeletonData#defaultSkin} using the slot name and attachment
	 * name.
	 * <p>
	 * See {@link #getAttachment(int, String)}. */
	public @Null Attachment getAttachment (String slotName, String attachmentName) {
		SlotData slot = data.findSlot(slotName);
		if (slot == null) throw new IllegalArgumentException("Slot not found: " + slotName);
		return getAttachment(slot.getIndex(), attachmentName);
	}

	/** Finds an attachment by looking in the {@link #skin} and {@link SkeletonData#defaultSkin} using the slot index and
	 * attachment name. First the skin is checked and if the attachment was not found, the default skin is checked.
	 * <p>
	 * See <a href="https://esotericsoftware.com/spine-runtime-skins">Runtime skins</a> in the Spine Runtimes Guide. */
	public @Null Attachment getAttachment (int slotIndex, String attachmentName) {
		if (attachmentName == null) throw new IllegalArgumentException("attachmentName cannot be null.");
		if (skin != null) {
			Attachment attachment = skin.getAttachment(slotIndex, attachmentName);
			if (attachment != null) return attachment;
		}
		if (data.defaultSkin != null) return data.defaultSkin.getAttachment(slotIndex, attachmentName);
		return null;
	}

	/** A convenience method to set an attachment by finding the slot with {@link #findSlot(String)}, finding the attachment with
	 * {@link #getAttachment(int, String)}, then setting the slot's {@link SlotPose#attachment}.
	 * @param attachmentName May be null to clear the slot's attachment. */
	public void setAttachment (String slotName, @Null String attachmentName) {
		if (slotName == null) throw new IllegalArgumentException("slotName cannot be null.");
		Slot slot = findSlot(slotName);
		if (slot == null) throw new IllegalArgumentException("Slot not found: " + slotName);
		Attachment attachment = null;
		if (attachmentName != null) {
			attachment = getAttachment(slot.data.index, attachmentName);
			if (attachment == null)
				throw new IllegalArgumentException("Attachment not found: " + attachmentName + ", for slot: " + slotName);
		}
		slot.pose.setAttachment(attachment);
	}

	/** The skeleton's sliders. */
	public Array<Slider> getSliders () {
		return sliders;
	}

	/** Finds a slider by comparing each slider's name. It is more efficient to cache the results of this method than to call it
	 * repeatedly. */
	public @Null Slider findSlider (String constraintName) {
		if (constraintName == null) throw new IllegalArgumentException("constraintName cannot be null.");
		Object[] sliders = this.sliders.items;
		for (int i = 0, n = this.sliders.size; i < n; i++) {
			var slider = (Slider)sliders[i];
			if (slider.data.name.equals(constraintName)) return slider;
		}
		return null;
	}

	/** The skeleton's IK constraints. */
	public Array<IkConstraint> getIkConstraints () {
		return ikConstraints;
	}

	/** Finds an IK constraint by comparing each IK constraint's name. It is more efficient to cache the results of this method
	 * than to call it repeatedly. */
	public @Null IkConstraint findIkConstraint (String constraintName) {
		if (constraintName == null) throw new IllegalArgumentException("constraintName cannot be null.");
		Object[] ikConstraints = this.ikConstraints.items;
		for (int i = 0, n = this.ikConstraints.size; i < n; i++) {
			var ikConstraint = (IkConstraint)ikConstraints[i];
			if (ikConstraint.data.name.equals(constraintName)) return ikConstraint;
		}
		return null;
	}

	/** The skeleton's transform constraints. */
	public Array<TransformConstraint> getTransformConstraints () {
		return transformConstraints;
	}

	/** Finds a transform constraint by comparing each transform constraint's name. It is more efficient to cache the results of
	 * this method than to call it repeatedly. */
	public @Null TransformConstraint findTransformConstraint (String constraintName) {
		if (constraintName == null) throw new IllegalArgumentException("constraintName cannot be null.");
		Object[] transformConstraints = this.transformConstraints.items;
		for (int i = 0, n = this.transformConstraints.size; i < n; i++) {
			var constraint = (TransformConstraint)transformConstraints[i];
			if (constraint.data.name.equals(constraintName)) return constraint;
		}
		return null;
	}

	/** The skeleton's path constraints. */
	public Array<PathConstraint> getPathConstraints () {
		return pathConstraints;
	}

	/** Finds a path constraint by comparing each path constraint's name. It is more efficient to cache the results of this method
	 * than to call it repeatedly. */
	public @Null PathConstraint findPathConstraint (String constraintName) {
		if (constraintName == null) throw new IllegalArgumentException("constraintName cannot be null.");
		Object[] pathConstraints = this.pathConstraints.items;
		for (int i = 0, n = this.pathConstraints.size; i < n; i++) {
			var constraint = (PathConstraint)pathConstraints[i];
			if (constraint.data.name.equals(constraintName)) return constraint;
		}
		return null;
	}

	/** The skeleton's physics constraints. */
	public Array<PhysicsConstraint> getPhysicsConstraints () {
		return physicsConstraints;
	}

	/** Finds a physics constraint by comparing each physics constraint's name. It is more efficient to cache the results of this
	 * method than to call it repeatedly. */
	public @Null PhysicsConstraint findPhysicsConstraint (String constraintName) {
		if (constraintName == null) throw new IllegalArgumentException("constraintName cannot be null.");
		Object[] physicsConstraints = this.physicsConstraints.items;
		for (int i = 0, n = this.physicsConstraints.size; i < n; i++) {
			var constraint = (PhysicsConstraint)physicsConstraints[i];
			if (constraint.data.name.equals(constraintName)) return constraint;
		}
		return null;
	}

	/** Returns the axis aligned bounding box (AABB) of the region and mesh attachments for the current pose.
	 * @param offset An output value, the distance from the skeleton origin to the bottom left corner of the AABB.
	 * @param size An output value, the width and height of the AABB.
	 * @param temp Working memory to temporarily store attachments' computed world vertices. */
	public void getBounds (Vector2 offset, Vector2 size, FloatArray temp) {
		getBounds(offset, size, temp, null);
	}

	/** Returns the axis aligned bounding box (AABB) of the region and mesh attachments for the current pose. Optionally applies
	 * clipping.
	 * @param offset An output value, the distance from the skeleton origin to the bottom left corner of the AABB.
	 * @param size An output value, the width and height of the AABB.
	 * @param temp Working memory to temporarily store attachments' computed world vertices.
	 * @param clipper {@link SkeletonClipping} to use. If <code>null</code>, no clipping is applied. */
	public void getBounds (Vector2 offset, Vector2 size, FloatArray temp, SkeletonClipping clipper) {
		if (offset == null) throw new IllegalArgumentException("offset cannot be null.");
		if (size == null) throw new IllegalArgumentException("size cannot be null.");
		if (temp == null) throw new IllegalArgumentException("temp cannot be null.");
		Object[] drawOrder = this.drawOrder.items;
		float minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
		for (int i = 0, n = this.drawOrder.size; i < n; i++) {
			var slot = (Slot)drawOrder[i];
			if (!slot.bone.active) continue;
			int verticesLength = 0;
			float[] vertices = null;
			short[] triangles = null;
			Attachment attachment = slot.pose.attachment;
			if (attachment instanceof RegionAttachment region) {
				verticesLength = 8;
				vertices = temp.setSize(8);
				region.computeWorldVertices(slot, vertices, 0, 2);
				triangles = quadTriangles;
			} else if (attachment instanceof MeshAttachment mesh) {
				verticesLength = mesh.getWorldVerticesLength();
				vertices = temp.setSize(verticesLength);
				mesh.computeWorldVertices(slot, 0, verticesLength, vertices, 0, 2);
				triangles = mesh.getTriangles();
			} else if (attachment instanceof ClippingAttachment clip && clipper != null) {
				clipper.clipStart(slot, clip);
				continue;
			}
			if (vertices != null) {
				if (clipper != null && clipper.isClipping() && clipper.clipTriangles(vertices, triangles, triangles.length)) {
					vertices = clipper.getClippedVertices().items;
					verticesLength = clipper.getClippedVertices().size;
				}
				for (int ii = 0; ii < verticesLength; ii += 2) {
					float x = vertices[ii], y = vertices[ii + 1];
					minX = Math.min(minX, x);
					minY = Math.min(minY, y);
					maxX = Math.max(maxX, x);
					maxY = Math.max(maxY, y);
				}
			}
			if (clipper != null) clipper.clipEnd(slot);
		}
		if (clipper != null) clipper.clipEnd();
		offset.set(minX, minY);
		size.set(maxX - minX, maxY - minY);
	}

	/** The color to tint all the skeleton's attachments. */
	public Color getColor () {
		return color;
	}

	/** A convenience method for setting the skeleton color. The color can also be set by modifying {@link #getColor()}. */
	public void setColor (Color color) {
		if (color == null) throw new IllegalArgumentException("color cannot be null.");
		this.color.set(color);
	}

	/** A convenience method for setting the skeleton color. The color can also be set by modifying {@link #getColor()}. */
	public void setColor (float r, float g, float b, float a) {
		color.set(r, g, b, a);
	}

	/** Scales the entire skeleton on the X axis.
	 * <p>
	 * Bones that do not inherit scale are still affected by this property. */
	public float getScaleX () {
		return scaleX;
	}

	public void setScaleX (float scaleX) {
		this.scaleX = scaleX;
	}

	/** Scales the entire skeleton on the Y axis.
	 * <p>
	 * Bones that do not inherit scale are still affected by this property. */
	public float getScaleY () {
		return scaleY;
	}

	public void setScaleY (float scaleY) {
		this.scaleY = scaleY;
	}

	/** Scales the entire skeleton on the X and Y axes.
	 * <p>
	 * Bones that do not inherit scale are still affected by this property. */
	public void setScale (float scaleX, float scaleY) {
		this.scaleX = scaleX;
		this.scaleY = scaleY;
	}

	/** Sets the skeleton X position, which is added to the root bone worldX position.
	 * <p>
	 * Bones that do not inherit translation are still affected by this property. */
	public float getX () {
		return x;
	}

	public void setX (float x) {
		this.x = x;
	}

	/** Sets the skeleton Y position, which is added to the root bone worldY position.
	 * <p>
	 * Bones that do not inherit translation are still affected by this property. */
	public float getY () {
		return y;
	}

	public void setY (float y) {
		this.y = y;
	}

	/** Sets the skeleton X and Y position, which is added to the root bone worldX and worldY position.
	 * <p>
	 * Bones that do not inherit translation are still affected by this property. */
	public void setPosition (float x, float y) {
		this.x = x;
		this.y = y;
	}

	/** Calls {@link PhysicsConstraint#translate(float, float)} for each physics constraint. */
	public void physicsTranslate (float x, float y) {
		Object[] physicsConstraints = this.physicsConstraints.items;
		for (int i = 0, n = this.physicsConstraints.size; i < n; i++)
			((PhysicsConstraint)physicsConstraints[i]).translate(x, y);
	}

	/** Calls {@link PhysicsConstraint#rotate(float, float, float)} for each physics constraint. */
	public void physicsRotate (float x, float y, float degrees) {
		Object[] physicsConstraints = this.physicsConstraints.items;
		for (int i = 0, n = this.physicsConstraints.size; i < n; i++)
			((PhysicsConstraint)physicsConstraints[i]).rotate(x, y, degrees);
	}

	/** Returns the skeleton's time. This is used for time-based manipulations, such as {@link PhysicsConstraint}.
	 * <p>
	 * See {@link #update(float)}. */
	public float getTime () {
		return time;
	}

	public void setTime (float time) {
		this.time = time;
	}

	/** Increments the skeleton's {@link #time}. */
	public void update (float delta) {
		time += delta;
	}

	public String toString () {
		return data.name != null ? data.name : super.toString();
	}
}
