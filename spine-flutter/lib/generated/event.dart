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
import 'package:ffi/ffi.dart';
import 'spine_flutter_bindings_generated.dart';
import 'event_data.dart';

/// Event wrapper
class Event implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_event_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  Event.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Event(double time, EventData data) {
    final ptr = _bindings.spine_event_create(time, data.nativePtr.cast());
    return Event.fromPointer(ptr);
  }

  EventData get data {
    final result = _bindings.spine_event_get_data(_ptr);
    return EventData.fromPointer(result);
  }

  double get time {
    final result = _bindings.spine_event_get_time(_ptr);
    return result;
  }

  int get intValue {
    final result = _bindings.spine_event_get_int(_ptr);
    return result;
  }

  set intValue(int value) {
    _bindings.spine_event_set_int(_ptr, value);
  }

  double get floatValue {
    final result = _bindings.spine_event_get_float(_ptr);
    return result;
  }

  set floatValue(double value) {
    _bindings.spine_event_set_float(_ptr, value);
  }

  String get stringValue {
    final result = _bindings.spine_event_get_string(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set stringValue(String value) {
    _bindings.spine_event_set_string(_ptr, value.toNativeUtf8().cast<Char>());
  }

  double get volume {
    final result = _bindings.spine_event_get_volume(_ptr);
    return result;
  }

  set volume(double value) {
    _bindings.spine_event_set_volume(_ptr, value);
  }

  double get balance {
    final result = _bindings.spine_event_get_balance(_ptr);
    return result;
  }

  set balance(double value) {
    _bindings.spine_event_set_balance(_ptr, value);
  }

  void dispose() {
    _bindings.spine_event_dispose(_ptr);
  }
}