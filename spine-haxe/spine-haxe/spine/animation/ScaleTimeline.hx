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

package spine.animation;

import spine.Bone;
import spine.Event;
import spine.MathUtils;
import spine.Skeleton;

/** Changes a bone's local spine.Bone.scaleX and spine.Bone.scaleY. */
class ScaleTimeline extends BoneTimeline2 {
	public function new(frameCount:Int, bezierCount:Int, boneIndex:Int) {
		super(frameCount, bezierCount, boneIndex, Property.scaleX, Property.scaleY);
	}

	public function apply1 (pose:BoneLocal, setup:BoneLocal, time:Float, alpha:Float, blend:MixBlend, direction:MixDirection) {
		if (time < frames[0]) {
			switch (blend) {
				case MixBlend.setup:
					pose.scaleX = setup.scaleX;
					pose.scaleY = setup.scaleY;
				case MixBlend.first:
					pose.scaleX += (setup.scaleX - pose.scaleX) * alpha;
					pose.scaleY += (setup.scaleY - pose.scaleY) * alpha;
			}
			return;
		}

		var x:Float = 0, y:Float = 0;
		var i:Int = Timeline.search(frames, time, BoneTimeline2.ENTRIES);
		var curveType:Int = Std.int(curves[Std.int(i / BoneTimeline2.ENTRIES)]);
		switch (curveType) {
			case CurveTimeline.LINEAR:
				var before:Float = frames[i];
				x = frames[i + BoneTimeline2.VALUE1];
				y = frames[i + BoneTimeline2.VALUE2];
				var t:Float = (time - before) / (frames[i + BoneTimeline2.ENTRIES] - before);
				x += (frames[i + BoneTimeline2.ENTRIES + BoneTimeline2.VALUE1] - x) * t;
				y += (frames[i + BoneTimeline2.ENTRIES + BoneTimeline2.VALUE2] - y) * t;
			case CurveTimeline.STEPPED:
				x = frames[i + BoneTimeline2.VALUE1];
				y = frames[i + BoneTimeline2.VALUE2];
			default:
				x = getBezierValue(time, i, BoneTimeline2.VALUE1, curveType - CurveTimeline.BEZIER);
				y = getBezierValue(time, i, BoneTimeline2.VALUE2, curveType + CurveTimeline.BEZIER_SIZE - CurveTimeline.BEZIER);
		}
		x *= setup.scaleX;
		y *= setup.scaleY;

		if (alpha == 1) {
			if (blend == MixBlend.add) {
				pose.scaleX += x - setup.scaleX;
				pose.scaleY += y - setup.scaleY;
			} else {
				pose.scaleX = x;
				pose.scaleY = y;
			}
		} else {
			var bx:Float = 0, by:Float = 0;
			if (direction == MixDirection.mixOut) {
				switch (blend) {
					case MixBlend.setup:
						bx = setup.scaleX;
						by = setup.scaleY;
						pose.scaleX = bx + (Math.abs(x) * MathUtils.signum(bx) - bx) * alpha;
						pose.scaleY = by + (Math.abs(y) * MathUtils.signum(by) - by) * alpha;
					case MixBlend.first, MixBlend.replace:
						bx = pose.scaleX;
						by = pose.scaleY;
						pose.scaleX = bx + (Math.abs(x) * MathUtils.signum(bx) - bx) * alpha;
						pose.scaleY = by + (Math.abs(y) * MathUtils.signum(by) - by) * alpha;
					case MixBlend.add:
						pose.scaleX = (x - setup.scaleX) * alpha;
						pose.scaleY = (y - setup.scaleY) * alpha;
				}
			} else {
				switch (blend) {
					case MixBlend.setup:
						bx = Math.abs(setup.scaleX) * MathUtils.signum(x);
						by = Math.abs(setup.scaleY) * MathUtils.signum(y);
						pose.scaleX = bx + (x - bx) * alpha;
						pose.scaleY = by + (y - by) * alpha;
					case MixBlend.first, MixBlend.replace:
						bx = Math.abs(pose.scaleX) * MathUtils.signum(x);
						by = Math.abs(pose.scaleY) * MathUtils.signum(y);
						pose.scaleX = bx + (x - bx) * alpha;
						pose.scaleY = by + (y - by) * alpha;
					case MixBlend.add:
						pose.scaleX += (x - setup.scaleX) * alpha;
						pose.scaleY += (y - setup.scaleY) * alpha;
				}
			}
		}
	}
}
