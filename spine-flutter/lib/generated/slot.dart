//
// Spine Runtimes License Agreement
// Last updated April 5, 2025. Replaces all prior versions.
//
// Copyright (c) 2013-2025, Esoteric Software LLC
//
// Integration of the Spine Runtimes into software or otherwise creating
// derivative works of the Spine Runtimes is permitted under the terms and
// conditions of Section 2 of the Spine Editor License Agreement:
// http://esotericsoftware.com/spine-editor-license
//
// Otherwise, it is permitted to integrate the Spine Runtimes into software
// or otherwise create derivative works of the Spine Runtimes (collectively,
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
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

// AUTO GENERATED FILE, DO NOT EDIT.

import 'dart:ffi';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'bone.dart';
import 'posed.dart';
import 'skeleton.dart';
import 'slot_data.dart';
import 'slot_pose.dart';

/// Slot wrapper
class Slot implements Posed {
  final Pointer<spine_slot_wrapper> _ptr;

  Slot.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Slot(SlotData data, Skeleton skeleton) {
    final ptr = SpineBindings.bindings.spine_slot_create(data.nativePtr.cast(), skeleton.nativePtr.cast());
    return Slot.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_slot_dispose(_ptr);
  }

  Bone get bone {
    final result = SpineBindings.bindings.spine_slot_get_bone(_ptr);
    return Bone.fromPointer(result);
  }

  void setupPose() {
    SpineBindings.bindings.spine_slot_setup_pose(_ptr);
  }

  SlotData get data {
    final result = SpineBindings.bindings.spine_slot_get_data(_ptr);
    return SlotData.fromPointer(result);
  }

  SlotPose get pose {
    final result = SpineBindings.bindings.spine_slot_get_pose(_ptr);
    return SlotPose.fromPointer(result);
  }

  SlotPose get appliedPose {
    final result = SpineBindings.bindings.spine_slot_get_applied_pose(_ptr);
    return SlotPose.fromPointer(result);
  }

  @override
  void resetConstrained() {
    SpineBindings.bindings.spine_slot_reset_constrained(_ptr);
  }

  @override
  void constrained() {
    SpineBindings.bindings.spine_slot_constrained(_ptr);
  }

  @override
  bool get isPoseEqualToApplied {
    final result = SpineBindings.bindings.spine_slot_is_pose_equal_to_applied(_ptr);
    return result;
  }
}
