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
import '../native_array.dart';
import 'animation.dart';
import 'atlas_page.dart';
import 'atlas_region.dart';
import 'attachment.dart';
import 'bone.dart';
import 'bone_data.dart';
import 'bone_pose.dart';
import 'bounding_box_attachment.dart';
import 'constraint.dart';
import 'constraint_data.dart';
import 'event.dart';
import 'event_data.dart';
import 'from_property.dart';
import 'physics_constraint.dart';
import 'polygon.dart';
import 'skin.dart';
import 'slot.dart';
import 'slot_data.dart';
import 'texture_region.dart';
import 'timeline.dart';
import 'to_property.dart';
import 'track_entry.dart';
import 'update.dart';

/// Array of float elements
class ArrayFloat extends NativeArray<double> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayFloat.fromPointer(Pointer<spine_array_float_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_float_size(nativePtr.cast());
  }

  @override
  double operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_float_buffer(nativePtr.cast());
    return buffer.cast<Float>()[index];
  }

}

/// Array of int elements
class ArrayInt extends NativeArray<int> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayInt.fromPointer(Pointer<spine_array_int_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_int_size(nativePtr.cast());
  }

  @override
  int operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_int_buffer(nativePtr.cast());
    return buffer.cast<Int32>()[index];
  }

}

/// Array of unsigned_short elements
class ArrayUnsignedShort extends NativeArray<int> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayUnsignedShort.fromPointer(Pointer<spine_array_unsigned_short_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_unsigned_short_size(nativePtr.cast());
  }

  @override
  int operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_unsigned_short_buffer(nativePtr.cast());
    return buffer.cast<Uint16>()[index];
  }

}

/// Array of property_id elements
class ArrayPropertyId extends NativeArray<int> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayPropertyId.fromPointer(Pointer<spine_array_property_id_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_property_id_size(nativePtr.cast());
  }

  @override
  int operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_property_id_buffer(nativePtr.cast());
    // NOTE: This will not compile due to C API bug - buffer() returns int instead of Pointer
    return buffer.cast<Int64>()[index];
  }

}

/// Array of Animation elements
class ArrayAnimation extends NativeArray<Animation> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayAnimation.fromPointer(Pointer<spine_array_animation_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_animation_size(nativePtr.cast());
  }

  @override
  Animation operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_animation_buffer(nativePtr.cast());
    return Animation.fromPointer(buffer[index]);
  }

}

/// Array of AtlasPage elements
class ArrayAtlasPage extends NativeArray<AtlasPage> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayAtlasPage.fromPointer(Pointer<spine_array_atlas_page_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_atlas_page_size(nativePtr.cast());
  }

  @override
  AtlasPage operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_atlas_page_buffer(nativePtr.cast());
    return AtlasPage.fromPointer(buffer[index]);
  }

}

/// Array of AtlasRegion elements
class ArrayAtlasRegion extends NativeArray<AtlasRegion> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayAtlasRegion.fromPointer(Pointer<spine_array_atlas_region_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_atlas_region_size(nativePtr.cast());
  }

  @override
  AtlasRegion operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_atlas_region_buffer(nativePtr.cast());
    return AtlasRegion.fromPointer(buffer[index]);
  }

}

/// Array of Attachment elements
class ArrayAttachment extends NativeArray<Attachment> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayAttachment.fromPointer(Pointer<spine_array_attachment_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_attachment_size(nativePtr.cast());
  }

  @override
  Attachment operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_attachment_buffer(nativePtr.cast());
    return Attachment.fromPointer(buffer[index]);
  }

}

/// Array of Bone elements
class ArrayBone extends NativeArray<Bone> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayBone.fromPointer(Pointer<spine_array_bone_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_bone_size(nativePtr.cast());
  }

  @override
  Bone operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_bone_buffer(nativePtr.cast());
    return Bone.fromPointer(buffer[index]);
  }

}

/// Array of BoneData elements
class ArrayBoneData extends NativeArray<BoneData> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayBoneData.fromPointer(Pointer<spine_array_bone_data_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_bone_data_size(nativePtr.cast());
  }

  @override
  BoneData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_bone_data_buffer(nativePtr.cast());
    return BoneData.fromPointer(buffer[index]);
  }

}

/// Array of BonePose elements
class ArrayBonePose extends NativeArray<BonePose> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayBonePose.fromPointer(Pointer<spine_array_bone_pose_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_bone_pose_size(nativePtr.cast());
  }

  @override
  BonePose operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_bone_pose_buffer(nativePtr.cast());
    return BonePose.fromPointer(buffer[index]);
  }

}

/// Array of BoundingBoxAttachment elements
class ArrayBoundingBoxAttachment extends NativeArray<BoundingBoxAttachment> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayBoundingBoxAttachment.fromPointer(Pointer<spine_array_bounding_box_attachment_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_bounding_box_attachment_size(nativePtr.cast());
  }

  @override
  BoundingBoxAttachment operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_bounding_box_attachment_buffer(nativePtr.cast());
    return BoundingBoxAttachment.fromPointer(buffer[index]);
  }

}

/// Array of Constraint elements
class ArrayConstraint extends NativeArray<Constraint> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayConstraint.fromPointer(Pointer<spine_array_constraint_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_constraint_size(nativePtr.cast());
  }

  @override
  Constraint operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_constraint_buffer(nativePtr.cast());
    return Constraint.fromPointer(buffer[index]);
  }

}

/// Array of ConstraintData elements
class ArrayConstraintData extends NativeArray<ConstraintData> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayConstraintData.fromPointer(Pointer<spine_array_constraint_data_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_constraint_data_size(nativePtr.cast());
  }

  @override
  ConstraintData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_constraint_data_buffer(nativePtr.cast());
    return ConstraintData.fromPointer(buffer[index]);
  }

}

/// Array of Event elements
class ArrayEvent extends NativeArray<Event> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayEvent.fromPointer(Pointer<spine_array_event_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_event_size(nativePtr.cast());
  }

  @override
  Event operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_event_buffer(nativePtr.cast());
    return Event.fromPointer(buffer[index]);
  }

}

/// Array of EventData elements
class ArrayEventData extends NativeArray<EventData> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayEventData.fromPointer(Pointer<spine_array_event_data_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_event_data_size(nativePtr.cast());
  }

  @override
  EventData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_event_data_buffer(nativePtr.cast());
    return EventData.fromPointer(buffer[index]);
  }

}

/// Array of FromProperty elements
class ArrayFromProperty extends NativeArray<FromProperty> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayFromProperty.fromPointer(Pointer<spine_array_from_property_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_from_property_size(nativePtr.cast());
  }

  @override
  FromProperty operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_from_property_buffer(nativePtr.cast());
    return FromProperty.fromPointer(buffer[index]);
  }

}

/// Array of PhysicsConstraint elements
class ArrayPhysicsConstraint extends NativeArray<PhysicsConstraint> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayPhysicsConstraint.fromPointer(Pointer<spine_array_physics_constraint_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_physics_constraint_size(nativePtr.cast());
  }

  @override
  PhysicsConstraint operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_physics_constraint_buffer(nativePtr.cast());
    return PhysicsConstraint.fromPointer(buffer[index]);
  }

}

/// Array of Polygon elements
class ArrayPolygon extends NativeArray<Polygon> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayPolygon.fromPointer(Pointer<spine_array_polygon_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_polygon_size(nativePtr.cast());
  }

  @override
  Polygon operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_polygon_buffer(nativePtr.cast());
    return Polygon.fromPointer(buffer[index]);
  }

}

/// Array of Skin elements
class ArraySkin extends NativeArray<Skin> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArraySkin.fromPointer(Pointer<spine_array_skin_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_skin_size(nativePtr.cast());
  }

  @override
  Skin operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_skin_buffer(nativePtr.cast());
    return Skin.fromPointer(buffer[index]);
  }

}

/// Array of Slot elements
class ArraySlot extends NativeArray<Slot> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArraySlot.fromPointer(Pointer<spine_array_slot_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_slot_size(nativePtr.cast());
  }

  @override
  Slot operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_slot_buffer(nativePtr.cast());
    return Slot.fromPointer(buffer[index]);
  }

}

/// Array of SlotData elements
class ArraySlotData extends NativeArray<SlotData> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArraySlotData.fromPointer(Pointer<spine_array_slot_data_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_slot_data_size(nativePtr.cast());
  }

  @override
  SlotData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_slot_data_buffer(nativePtr.cast());
    return SlotData.fromPointer(buffer[index]);
  }

}

/// Array of TextureRegion elements
class ArrayTextureRegion extends NativeArray<TextureRegion> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayTextureRegion.fromPointer(Pointer<spine_array_texture_region_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_texture_region_size(nativePtr.cast());
  }

  @override
  TextureRegion operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_texture_region_buffer(nativePtr.cast());
    return TextureRegion.fromPointer(buffer[index]);
  }

}

/// Array of Timeline elements
class ArrayTimeline extends NativeArray<Timeline> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayTimeline.fromPointer(Pointer<spine_array_timeline_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_timeline_size(nativePtr.cast());
  }

  @override
  Timeline operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_timeline_buffer(nativePtr.cast());
    return Timeline.fromPointer(buffer[index]);
  }

}

/// Array of ToProperty elements
class ArrayToProperty extends NativeArray<ToProperty> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayToProperty.fromPointer(Pointer<spine_array_to_property_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_to_property_size(nativePtr.cast());
  }

  @override
  ToProperty operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_to_property_buffer(nativePtr.cast());
    return ToProperty.fromPointer(buffer[index]);
  }

}

/// Array of TrackEntry elements
class ArrayTrackEntry extends NativeArray<TrackEntry> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayTrackEntry.fromPointer(Pointer<spine_array_track_entry_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_track_entry_size(nativePtr.cast());
  }

  @override
  TrackEntry operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_track_entry_buffer(nativePtr.cast());
    return TrackEntry.fromPointer(buffer[index]);
  }

}

/// Array of Update elements
class ArrayUpdate extends NativeArray<Update> {
  static late SpineFlutterBindings _bindings;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  ArrayUpdate.fromPointer(Pointer<spine_array_update_wrapper> super.ptr);

  @override
  int get length {
    return _bindings.spine_array_update_size(nativePtr.cast());
  }

  @override
  Update operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = _bindings.spine_array_update_buffer(nativePtr.cast());
    return Update.fromPointer(buffer[index]);
  }

}