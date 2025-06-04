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

/**
 * Constants for animation property types.
 */
enum abstract Property(String) from String to String {
	var rotate = "0";
	var x = "1";
	var y = "2";
	var scaleX = "3";
	var scaleY = "4";
	var shearX = "5";
	var shearY = "6";
	var inherit = "7";

	var rgb = "8";
	var alpha = "9";
	var rgb2 = "10";

	var attachment = "11";
	var deform = "12";

	var event = "13";
	var drawOrder = "14";

	var ikConstraint = "15";
	var transformConstraint = "16";

	var pathConstraintPosition = "17";
	var pathConstraintSpacing = "18";
	var pathConstraintMix = "19";

	var physicsConstraintInertia = "20";
	var physicsConstraintStrength = "21";
	var physicsConstraintDamping = "22";
	var physicsConstraintMass = "23";
	var physicsConstraintWind = "24";
	var physicsConstraintGravity = "25";
	var physicsConstraintMix = "26";
	var physicsConstraintReset = "27";

	var sequence = "28";

	var sliderTime = "29";
	var sliderMix = "30";
}