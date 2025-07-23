// ******************************************************************************
// Spine Runtimes License Agreement
// Last updated July 28, 2023. Replaces all prior versions.
//
// Copyright (c) 2013-2023, Esoteric Software LLC
//
// Integration of the Spine Runtimes into software or otherwise creating
// derivative works of the Spine Runtimes is permitted under the terms and
// conditions of Section 2 of the Spine Editor License Agreement:
// http://esotericsoftware.com/spine-editor-license
//
// Otherwise, it is permitted to integrate the Spine Runtimes into software or
// otherwise create derivative works of the Spine Runtimes (collectively,
// "Products"), provided that each user of the Products must obtain their own
// Spine Editor license and redistribution of the Products in any form must
// include this license and copyright notice.
//
// THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
// BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
// SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *****************************************************************************/

// AUTO GENERATED FILE, DO NOT EDIT.

/// Property enum
enum Property {
  rotate(1 << 0),
  x(1 << 1),
  y(1 << 2),
  scaleX(1 << 3),
  scaleY(1 << 4),
  shearX(1 << 5),
  shearY(1 << 6),
  inherit(1 << 7),
  rgb(1 << 8),
  alpha(1 << 9),
  rgb2(1 << 10),
  attachment(1 << 11),
  deform(1 << 12),
  event(1 << 13),
  drawOrder(1 << 14),
  ikConstraint(1 << 15),
  transformConstraint(1 << 16),
  pathConstraintPosition(1 << 17),
  pathConstraintSpacing(1 << 18),
  pathConstraintMix(1 << 19),
  physicsConstraintInertia(1 << 20),
  physicsConstraintStrength(1 << 21),
  physicsConstraintDamping(1 << 22),
  physicsConstraintMass(1 << 23),
  physicsConstraintWind(1 << 24),
  physicsConstraintGravity(1 << 25),
  physicsConstraintMix(1 << 26),
  physicsConstraintReset(1 << 27),
  sequence(1 << 28),
  sliderTime(1 << 29),
  sliderMix(1 << 30);

  const Property(this.value);
  final int value;

  static Property fromValue(int value) {
    return values.firstWhere(
      (e) => e.value == value,
      orElse: () => throw ArgumentError('Invalid Property value: $value'),
    );
  }
}