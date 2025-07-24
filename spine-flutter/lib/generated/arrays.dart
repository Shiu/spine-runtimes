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
import 'package:ffi/ffi.dart';
import 'spine_flutter_bindings_generated.dart';
import '../spine_bindings.dart';
import '../native_array.dart';
import 'alpha_timeline.dart';
import 'animation.dart';
import 'atlas_page.dart';
import 'atlas_region.dart';
import 'attachment.dart';
import 'attachment_timeline.dart';
import 'bone.dart';
import 'bone_data.dart';
import 'bone_pose.dart';
import 'bounding_box_attachment.dart';
import 'clipping_attachment.dart';
import 'constraint.dart';
import 'constraint_data.dart';
import 'deform_timeline.dart';
import 'draw_order_timeline.dart';
import 'event.dart';
import 'event_data.dart';
import 'event_timeline.dart';
import 'from_property.dart';
import 'from_rotate.dart';
import 'from_scale_x.dart';
import 'from_scale_y.dart';
import 'from_shear_y.dart';
import 'from_x.dart';
import 'from_y.dart';
import 'ik_constraint_timeline.dart';
import 'inherit_timeline.dart';
import 'mesh_attachment.dart';
import 'path_attachment.dart';
import 'path_constraint_mix_timeline.dart';
import 'path_constraint_position_timeline.dart';
import 'path_constraint_spacing_timeline.dart';
import 'physics_constraint.dart';
import 'physics_constraint_damping_timeline.dart';
import 'physics_constraint_gravity_timeline.dart';
import 'physics_constraint_inertia_timeline.dart';
import 'physics_constraint_mass_timeline.dart';
import 'physics_constraint_mix_timeline.dart';
import 'physics_constraint_reset_timeline.dart';
import 'physics_constraint_strength_timeline.dart';
import 'physics_constraint_wind_timeline.dart';
import 'point_attachment.dart';
import 'polygon.dart';
import 'region_attachment.dart';
import 'rgb2_timeline.dart';
import 'rgb_timeline.dart';
import 'rgba2_timeline.dart';
import 'rgba_timeline.dart';
import 'rotate_timeline.dart';
import 'scale_timeline.dart';
import 'scale_x_timeline.dart';
import 'scale_y_timeline.dart';
import 'sequence_timeline.dart';
import 'shear_timeline.dart';
import 'shear_x_timeline.dart';
import 'shear_y_timeline.dart';
import 'skin.dart';
import 'slider_mix_timeline.dart';
import 'slider_timeline.dart';
import 'slot.dart';
import 'slot_data.dart';
import 'texture_region.dart';
import 'timeline.dart';
import 'to_property.dart';
import 'to_rotate.dart';
import 'to_scale_x.dart';
import 'to_scale_y.dart';
import 'to_shear_y.dart';
import 'to_x.dart';
import 'to_y.dart';
import 'track_entry.dart';
import 'transform_constraint_timeline.dart';
import 'translate_timeline.dart';
import 'translate_x_timeline.dart';
import 'translate_y_timeline.dart';
import 'update.dart';

/// Array of float elements
class ArrayFloat extends NativeArray<double> {
  ArrayFloat.fromPointer(Pointer<spine_array_float_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_float_size(nativePtr.cast());
  }

  @override
  double operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_float_buffer(nativePtr.cast());
    return buffer.cast<Float>()[index];
  }

}

/// Array of int elements
class ArrayInt extends NativeArray<int> {
  ArrayInt.fromPointer(Pointer<spine_array_int_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_int_size(nativePtr.cast());
  }

  @override
  int operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_int_buffer(nativePtr.cast());
    return buffer.cast<Int32>()[index];
  }

}

/// Array of unsigned_short elements
class ArrayUnsignedShort extends NativeArray<int> {
  ArrayUnsignedShort.fromPointer(Pointer<spine_array_unsigned_short_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_unsigned_short_size(nativePtr.cast());
  }

  @override
  int operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_unsigned_short_buffer(nativePtr.cast());
    return buffer.cast<Uint16>()[index];
  }

}

/// Array of property_id elements
class ArrayPropertyId extends NativeArray<int> {
  ArrayPropertyId.fromPointer(Pointer<spine_array_property_id_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_property_id_size(nativePtr.cast());
  }

  @override
  int operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_property_id_buffer(nativePtr.cast());
    // NOTE: This will not compile due to C API bug - buffer() returns int instead of Pointer
    return buffer.cast<Int64>()[index];
  }

}

/// Array of Animation elements
class ArrayAnimation extends NativeArray<Animation> {
  ArrayAnimation.fromPointer(Pointer<spine_array_animation_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_animation_size(nativePtr.cast());
  }

  @override
  Animation operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_animation_buffer(nativePtr.cast());
    return Animation.fromPointer(buffer[index]);
  }

}

/// Array of AtlasPage elements
class ArrayAtlasPage extends NativeArray<AtlasPage> {
  ArrayAtlasPage.fromPointer(Pointer<spine_array_atlas_page_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_atlas_page_size(nativePtr.cast());
  }

  @override
  AtlasPage operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_atlas_page_buffer(nativePtr.cast());
    return AtlasPage.fromPointer(buffer[index]);
  }

}

/// Array of AtlasRegion elements
class ArrayAtlasRegion extends NativeArray<AtlasRegion> {
  ArrayAtlasRegion.fromPointer(Pointer<spine_array_atlas_region_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_atlas_region_size(nativePtr.cast());
  }

  @override
  AtlasRegion operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_atlas_region_buffer(nativePtr.cast());
    return AtlasRegion.fromPointer(buffer[index]);
  }

}

/// Array of Attachment elements
class ArrayAttachment extends NativeArray<Attachment> {
  ArrayAttachment.fromPointer(Pointer<spine_array_attachment_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_attachment_size(nativePtr.cast());
  }

  @override
  Attachment operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_attachment_buffer(nativePtr.cast());
    final rtti = SpineBindings.bindings.spine_attachment_get_rtti(buffer[index]);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_point_attachment':
        return PointAttachment.fromPointer(buffer[index].cast());
      case 'spine_region_attachment':
        return RegionAttachment.fromPointer(buffer[index].cast());
      case 'spine_bounding_box_attachment':
        return BoundingBoxAttachment.fromPointer(buffer[index].cast());
      case 'spine_clipping_attachment':
        return ClippingAttachment.fromPointer(buffer[index].cast());
      case 'spine_mesh_attachment':
        return MeshAttachment.fromPointer(buffer[index].cast());
      case 'spine_path_attachment':
        return PathAttachment.fromPointer(buffer[index].cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class Attachment');
    }
  }

}

/// Array of Bone elements
class ArrayBone extends NativeArray<Bone> {
  ArrayBone.fromPointer(Pointer<spine_array_bone_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_bone_size(nativePtr.cast());
  }

  @override
  Bone operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_bone_buffer(nativePtr.cast());
    return Bone.fromPointer(buffer[index]);
  }

}

/// Array of BoneData elements
class ArrayBoneData extends NativeArray<BoneData> {
  ArrayBoneData.fromPointer(Pointer<spine_array_bone_data_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_bone_data_size(nativePtr.cast());
  }

  @override
  BoneData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_bone_data_buffer(nativePtr.cast());
    return BoneData.fromPointer(buffer[index]);
  }

}

/// Array of BonePose elements
class ArrayBonePose extends NativeArray<BonePose> {
  ArrayBonePose.fromPointer(Pointer<spine_array_bone_pose_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_bone_pose_size(nativePtr.cast());
  }

  @override
  BonePose operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_bone_pose_buffer(nativePtr.cast());
    return BonePose.fromPointer(buffer[index]);
  }

}

/// Array of BoundingBoxAttachment elements
class ArrayBoundingBoxAttachment extends NativeArray<BoundingBoxAttachment> {
  ArrayBoundingBoxAttachment.fromPointer(Pointer<spine_array_bounding_box_attachment_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_bounding_box_attachment_size(nativePtr.cast());
  }

  @override
  BoundingBoxAttachment operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_bounding_box_attachment_buffer(nativePtr.cast());
    return BoundingBoxAttachment.fromPointer(buffer[index]);
  }

}

/// Array of Constraint elements
class ArrayConstraint extends NativeArray<Constraint> {
  ArrayConstraint.fromPointer(Pointer<spine_array_constraint_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_constraint_size(nativePtr.cast());
  }

  @override
  Constraint operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_constraint_buffer(nativePtr.cast());
    throw UnsupportedError('Cannot instantiate abstract class Constraint from pointer - no concrete subclasses found');
  }

}

/// Array of ConstraintData elements
class ArrayConstraintData extends NativeArray<ConstraintData> {
  ArrayConstraintData.fromPointer(Pointer<spine_array_constraint_data_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_constraint_data_size(nativePtr.cast());
  }

  @override
  ConstraintData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_constraint_data_buffer(nativePtr.cast());
    throw UnsupportedError('Cannot instantiate abstract class ConstraintData from pointer - no concrete subclasses found');
  }

}

/// Array of Event elements
class ArrayEvent extends NativeArray<Event> {
  ArrayEvent.fromPointer(Pointer<spine_array_event_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_event_size(nativePtr.cast());
  }

  @override
  Event operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_event_buffer(nativePtr.cast());
    return Event.fromPointer(buffer[index]);
  }

}

/// Array of EventData elements
class ArrayEventData extends NativeArray<EventData> {
  ArrayEventData.fromPointer(Pointer<spine_array_event_data_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_event_data_size(nativePtr.cast());
  }

  @override
  EventData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_event_data_buffer(nativePtr.cast());
    return EventData.fromPointer(buffer[index]);
  }

}

/// Array of FromProperty elements
class ArrayFromProperty extends NativeArray<FromProperty> {
  ArrayFromProperty.fromPointer(Pointer<spine_array_from_property_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_from_property_size(nativePtr.cast());
  }

  @override
  FromProperty operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_from_property_buffer(nativePtr.cast());
    final rtti = SpineBindings.bindings.spine_from_property_get_rtti(buffer[index]);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_from_rotate':
        return FromRotate.fromPointer(buffer[index].cast());
      case 'spine_from_scale_x':
        return FromScaleX.fromPointer(buffer[index].cast());
      case 'spine_from_scale_y':
        return FromScaleY.fromPointer(buffer[index].cast());
      case 'spine_from_shear_y':
        return FromShearY.fromPointer(buffer[index].cast());
      case 'spine_from_x':
        return FromX.fromPointer(buffer[index].cast());
      case 'spine_from_y':
        return FromY.fromPointer(buffer[index].cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class FromProperty');
    }
  }

}

/// Array of PhysicsConstraint elements
class ArrayPhysicsConstraint extends NativeArray<PhysicsConstraint> {
  ArrayPhysicsConstraint.fromPointer(Pointer<spine_array_physics_constraint_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_physics_constraint_size(nativePtr.cast());
  }

  @override
  PhysicsConstraint operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_physics_constraint_buffer(nativePtr.cast());
    return PhysicsConstraint.fromPointer(buffer[index]);
  }

}

/// Array of Polygon elements
class ArrayPolygon extends NativeArray<Polygon> {
  ArrayPolygon.fromPointer(Pointer<spine_array_polygon_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_polygon_size(nativePtr.cast());
  }

  @override
  Polygon operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_polygon_buffer(nativePtr.cast());
    return Polygon.fromPointer(buffer[index]);
  }

}

/// Array of Skin elements
class ArraySkin extends NativeArray<Skin> {
  ArraySkin.fromPointer(Pointer<spine_array_skin_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_skin_size(nativePtr.cast());
  }

  @override
  Skin operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_skin_buffer(nativePtr.cast());
    return Skin.fromPointer(buffer[index]);
  }

}

/// Array of Slot elements
class ArraySlot extends NativeArray<Slot> {
  ArraySlot.fromPointer(Pointer<spine_array_slot_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_slot_size(nativePtr.cast());
  }

  @override
  Slot operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_slot_buffer(nativePtr.cast());
    return Slot.fromPointer(buffer[index]);
  }

}

/// Array of SlotData elements
class ArraySlotData extends NativeArray<SlotData> {
  ArraySlotData.fromPointer(Pointer<spine_array_slot_data_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_slot_data_size(nativePtr.cast());
  }

  @override
  SlotData operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_slot_data_buffer(nativePtr.cast());
    return SlotData.fromPointer(buffer[index]);
  }

}

/// Array of TextureRegion elements
class ArrayTextureRegion extends NativeArray<TextureRegion> {
  ArrayTextureRegion.fromPointer(Pointer<spine_array_texture_region_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_texture_region_size(nativePtr.cast());
  }

  @override
  TextureRegion operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_texture_region_buffer(nativePtr.cast());
    return TextureRegion.fromPointer(buffer[index]);
  }

}

/// Array of Timeline elements
class ArrayTimeline extends NativeArray<Timeline> {
  ArrayTimeline.fromPointer(Pointer<spine_array_timeline_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_timeline_size(nativePtr.cast());
  }

  @override
  Timeline operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_timeline_buffer(nativePtr.cast());
    final rtti = SpineBindings.bindings.spine_timeline_get_rtti(buffer[index]);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_attachment_timeline':
        return AttachmentTimeline.fromPointer(buffer[index].cast());
      case 'spine_alpha_timeline':
        return AlphaTimeline.fromPointer(buffer[index].cast());
      case 'spine_rotate_timeline':
        return RotateTimeline.fromPointer(buffer[index].cast());
      case 'spine_scale_x_timeline':
        return ScaleXTimeline.fromPointer(buffer[index].cast());
      case 'spine_scale_y_timeline':
        return ScaleYTimeline.fromPointer(buffer[index].cast());
      case 'spine_shear_x_timeline':
        return ShearXTimeline.fromPointer(buffer[index].cast());
      case 'spine_shear_y_timeline':
        return ShearYTimeline.fromPointer(buffer[index].cast());
      case 'spine_translate_x_timeline':
        return TranslateXTimeline.fromPointer(buffer[index].cast());
      case 'spine_translate_y_timeline':
        return TranslateYTimeline.fromPointer(buffer[index].cast());
      case 'spine_path_constraint_position_timeline':
        return PathConstraintPositionTimeline.fromPointer(buffer[index].cast());
      case 'spine_path_constraint_spacing_timeline':
        return PathConstraintSpacingTimeline.fromPointer(buffer[index].cast());
      case 'spine_slider_mix_timeline':
        return SliderMixTimeline.fromPointer(buffer[index].cast());
      case 'spine_slider_timeline':
        return SliderTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_damping_timeline':
        return PhysicsConstraintDampingTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_gravity_timeline':
        return PhysicsConstraintGravityTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_inertia_timeline':
        return PhysicsConstraintInertiaTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_mass_timeline':
        return PhysicsConstraintMassTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_mix_timeline':
        return PhysicsConstraintMixTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_strength_timeline':
        return PhysicsConstraintStrengthTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_wind_timeline':
        return PhysicsConstraintWindTimeline.fromPointer(buffer[index].cast());
      case 'spine_scale_timeline':
        return ScaleTimeline.fromPointer(buffer[index].cast());
      case 'spine_shear_timeline':
        return ShearTimeline.fromPointer(buffer[index].cast());
      case 'spine_translate_timeline':
        return TranslateTimeline.fromPointer(buffer[index].cast());
      case 'spine_ik_constraint_timeline':
        return IkConstraintTimeline.fromPointer(buffer[index].cast());
      case 'spine_path_constraint_mix_timeline':
        return PathConstraintMixTimeline.fromPointer(buffer[index].cast());
      case 'spine_deform_timeline':
        return DeformTimeline.fromPointer(buffer[index].cast());
      case 'spine_rgb2_timeline':
        return Rgb2Timeline.fromPointer(buffer[index].cast());
      case 'spine_rgba2_timeline':
        return Rgba2Timeline.fromPointer(buffer[index].cast());
      case 'spine_rgba_timeline':
        return RgbaTimeline.fromPointer(buffer[index].cast());
      case 'spine_rgb_timeline':
        return RgbTimeline.fromPointer(buffer[index].cast());
      case 'spine_transform_constraint_timeline':
        return TransformConstraintTimeline.fromPointer(buffer[index].cast());
      case 'spine_draw_order_timeline':
        return DrawOrderTimeline.fromPointer(buffer[index].cast());
      case 'spine_event_timeline':
        return EventTimeline.fromPointer(buffer[index].cast());
      case 'spine_inherit_timeline':
        return InheritTimeline.fromPointer(buffer[index].cast());
      case 'spine_physics_constraint_reset_timeline':
        return PhysicsConstraintResetTimeline.fromPointer(buffer[index].cast());
      case 'spine_sequence_timeline':
        return SequenceTimeline.fromPointer(buffer[index].cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class Timeline');
    }
  }

}

/// Array of ToProperty elements
class ArrayToProperty extends NativeArray<ToProperty> {
  ArrayToProperty.fromPointer(Pointer<spine_array_to_property_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_to_property_size(nativePtr.cast());
  }

  @override
  ToProperty operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_to_property_buffer(nativePtr.cast());
    final rtti = SpineBindings.bindings.spine_to_property_get_rtti(buffer[index]);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_to_rotate':
        return ToRotate.fromPointer(buffer[index].cast());
      case 'spine_to_scale_x':
        return ToScaleX.fromPointer(buffer[index].cast());
      case 'spine_to_scale_y':
        return ToScaleY.fromPointer(buffer[index].cast());
      case 'spine_to_shear_y':
        return ToShearY.fromPointer(buffer[index].cast());
      case 'spine_to_x':
        return ToX.fromPointer(buffer[index].cast());
      case 'spine_to_y':
        return ToY.fromPointer(buffer[index].cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class ToProperty');
    }
  }

}

/// Array of TrackEntry elements
class ArrayTrackEntry extends NativeArray<TrackEntry> {
  ArrayTrackEntry.fromPointer(Pointer<spine_array_track_entry_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_track_entry_size(nativePtr.cast());
  }

  @override
  TrackEntry operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_track_entry_buffer(nativePtr.cast());
    return TrackEntry.fromPointer(buffer[index]);
  }

}

/// Array of Update elements
class ArrayUpdate extends NativeArray<Update> {
  ArrayUpdate.fromPointer(Pointer<spine_array_update_wrapper> super.ptr);

  @override
  int get length {
    return SpineBindings.bindings.spine_array_update_size(nativePtr.cast());
  }

  @override
  Update operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this, 'index');
    }
    final buffer = SpineBindings.bindings.spine_array_update_buffer(nativePtr.cast());
    throw UnsupportedError('Cannot instantiate abstract class Update from pointer - no concrete subclasses found');
  }

}