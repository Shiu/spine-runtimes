/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated July 28, 2023. Replaces all prior versions.
 *
 * Copyright (c) 2013-2023, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software or
 * otherwise create derivative works of the Spine Runtimes (collectively,
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
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
 * SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

package spine;

/** Stores the setup pose for a spine.IkConstraint.
 * 
 * @see https://esotericsoftware.com/spine-ik-constraints IK constraints in the Spine User Guide */
class IkConstraintData extends ConstraintData {
	/** The bones that are constrained by this IK constraint. */
	public var bones:Array<BoneData> = new Array<BoneData>();
	/** The bone that is the IK target. */
	public var target:BoneData;
	/** A percentage (0-1) that controls the mix between the constrained and unconstrained rotation.
	 * 
	 * For two bone IK: if the parent bone has local nonuniform scale, the child bone's local Y translation is set to 0. */
	public var mix:Float = 0;
	/** For two bone IK, controls the bend direction of the IK bones, either 1 or -1. */
	public var bendDirection:Int = 0;
	/** For one bone IK, when true and the target is too close, the bone is scaled to reach it. */
	public var compress:Bool = false;
	/** When true and the target is out of range, the parent bone is scaled to reach it.
	 * 
	 * For two bone IK: 1) the child bone's local Y translation is set to 0, 2) stretch is not applied if softness is
	 * > 0, and 3) if the parent bone has local nonuniform scale, stretch is not applied. */
	public var stretch:Bool = false;
	/** When true and compress or stretch is used, the bone is scaled on both the X and Y axes. */
	public var uniform:Bool = false;
	/** For two bone IK, the target bone's distance from the maximum reach of the bones where rotation begins to slow. The bones
	 * will not straighten completely until the target is this far out of range. */
	public var softness:Float = 0;

	public function new(name:String) {
		super(name, 0, false);
	}
}
