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

import 'dart:ffi';
import 'spine_flutter_bindings_generated.dart';
import 'color.dart';
import 'attachment.dart';
import 'arrays.dart';

/// SlotPose wrapper
class SlotPose implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_slot_pose_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  SlotPose.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory SlotPose() {
    final ptr = _bindings.spine_slot_pose_create();
    return SlotPose.fromPointer(ptr);
  }

  void set(SlotPose pose) {
    _bindings.spine_slot_pose_set(_ptr, pose.nativePtr.cast());
  }

  Color get color {
    final result = _bindings.spine_slot_pose_get_color(_ptr);
    return Color.fromPointer(result);
  }

  Color get darkColor {
    final result = _bindings.spine_slot_pose_get_dark_color(_ptr);
    return Color.fromPointer(result);
  }

  bool get hasDarkColor {
    final result = _bindings.spine_slot_pose_has_dark_color(_ptr);
    return result;
  }

  set hasDarkColor(bool value) {
    _bindings.spine_slot_pose_set_has_dark_color(_ptr, value);
  }

  Attachment get attachment {
    final result = _bindings.spine_slot_pose_get_attachment(_ptr);
    return Attachment.fromPointer(result);
  }

  set attachment(Attachment value) {
    _bindings.spine_slot_pose_set_attachment(_ptr, value.nativePtr.cast());
  }

  int get sequenceIndex {
    final result = _bindings.spine_slot_pose_get_sequence_index(_ptr);
    return result;
  }

  set sequenceIndex(int value) {
    _bindings.spine_slot_pose_set_sequence_index(_ptr, value);
  }

  ArrayFloat get deform {
    final result = _bindings.spine_slot_pose_get_deform(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_slot_pose_dispose(_ptr);
  }
}