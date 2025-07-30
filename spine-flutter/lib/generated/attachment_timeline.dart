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

import 'package:universal_ffi/ffi.dart';
import 'package:universal_ffi/ffi_utils.dart';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'slot_timeline.dart';
import 'timeline.dart';

/// AttachmentTimeline wrapper
class AttachmentTimeline extends Timeline implements SlotTimeline {
  final Pointer<spine_attachment_timeline_wrapper> _ptr;

  AttachmentTimeline.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());

  /// Get the native pointer for FFI calls
  @override
  Pointer get nativePtr => _ptr;

  factory AttachmentTimeline(int frameCount, int slotIndex) {
    final ptr = SpineBindings.bindings.spine_attachment_timeline_create(frameCount, slotIndex);
    return AttachmentTimeline.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_attachment_timeline_dispose(_ptr);
  }

  void setFrame(int frame, double time, String attachmentName) {
    SpineBindings.bindings
        .spine_attachment_timeline_set_frame(_ptr, frame, time, attachmentName.toNativeUtf8().cast<Char>());
  }

  @override
  int get slotIndex {
    final result = SpineBindings.bindings.spine_attachment_timeline_get_slot_index(_ptr);
    return result;
  }

  @override
  set slotIndex(int value) {
    SpineBindings.bindings.spine_attachment_timeline_set_slot_index(_ptr, value);
  }
}
