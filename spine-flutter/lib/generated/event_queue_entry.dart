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
import 'event_type.dart';
import 'track_entry.dart';
import 'event.dart';

/// EventQueueEntry wrapper
class EventQueueEntry implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_event_queue_entry_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  EventQueueEntry.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory EventQueueEntry(EventType eventType, TrackEntry trackEntry, Event event) {
    final ptr = _bindings.spine_event_queue_entry_create(eventType.value, trackEntry.nativePtr.cast(), event.nativePtr.cast());
    return EventQueueEntry.fromPointer(ptr);
  }

  EventType get type {
    final result = _bindings.spine_event_queue_entry_get__type(_ptr);
    return EventType.fromValue(result);
  }

  set type(EventType value) {
    _bindings.spine_event_queue_entry_set__type(_ptr, value.value);
  }

  TrackEntry get entry {
    final result = _bindings.spine_event_queue_entry_get__entry(_ptr);
    return TrackEntry.fromPointer(result);
  }

  set entry(TrackEntry value) {
    _bindings.spine_event_queue_entry_set__entry(_ptr, value.nativePtr.cast());
  }

  Event get event {
    final result = _bindings.spine_event_queue_entry_get__event(_ptr);
    return Event.fromPointer(result);
  }

  set event(Event value) {
    _bindings.spine_event_queue_entry_set__event(_ptr, value.nativePtr.cast());
  }

  void dispose() {
    _bindings.spine_event_queue_entry_dispose(_ptr);
  }
}