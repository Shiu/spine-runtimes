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
import 'bone.dart';
import 'slot_data.dart';
import 'slot_pose.dart';
import 'skeleton.dart';

/// Slot wrapper
class Slot implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_slot_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  Slot.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Slot(SlotData data, Skeleton skeleton) {
    final ptr = _bindings.spine_slot_create(data.nativePtr.cast(), skeleton.nativePtr.cast());
    return Slot.fromPointer(ptr);
  }

  Bone get bone {
    final result = _bindings.spine_slot_get_bone(_ptr);
    return Bone.fromPointer(result);
  }

  void setupPose() {
    _bindings.spine_slot_setup_pose(_ptr);
  }

  SlotData get data {
    final result = _bindings.spine_slot_get_data(_ptr);
    return SlotData.fromPointer(result);
  }

  SlotPose get pose {
    final result = _bindings.spine_slot_get_pose(_ptr);
    return SlotPose.fromPointer(result);
  }

  SlotPose get appliedPose {
    final result = _bindings.spine_slot_get_applied_pose(_ptr);
    return SlotPose.fromPointer(result);
  }

  void resetConstrained() {
    _bindings.spine_slot_reset_constrained(_ptr);
  }

  void constrained() {
    _bindings.spine_slot_constrained(_ptr);
  }

  bool get isPoseEqualToApplied {
    final result = _bindings.spine_slot_is_pose_equal_to_applied(_ptr);
    return result;
  }

  void dispose() {
    _bindings.spine_slot_dispose(_ptr);
  }
}