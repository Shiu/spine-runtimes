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

package spine;

/** Stores a bone's local pose. */
class BoneLocal implements Pose<BoneLocal> {

	/** The local x translation. */
	public var x:Float = 0;

	/** The local y translation. */
	public var y:Float = 0;

	/** The local rotation in degrees, counter clockwise. */
	public var rotation:Float = 0;

	/** The local scaleX. */
	public var scaleX:Float = 0;

	/** The local scaleY. */
	public var scaleY:Float = 0;

	/** The local shearX. */
	public var shearX:Float = 0;

	/** The local shearY. */
	public var shearY:Float = 0;

	/** Determines how parent world transforms affect this bone. */
	public var inherit(default, set):Inherit;
	function set_inherit (value:Inherit):Inherit {
		if (value == null) throw new SpineException("inherit cannot be null.");
		inherit = value;
		return value;
	}

	public function new () {
	}

	public function set (pose:BoneLocal):Void {
		if (pose == null) throw new SpineException("pose cannot be null.");
		x = pose.x;
		y = pose.y;
		rotation = pose.rotation;
		scaleX = pose.scaleX;
		scaleY = pose.scaleY;
		shearX = pose.shearX;
		shearY = pose.shearY;
		inherit = pose.inherit;
	}

}
