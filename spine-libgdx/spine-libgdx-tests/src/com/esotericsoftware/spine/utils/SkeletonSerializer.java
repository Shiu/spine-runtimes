package com.esotericsoftware.spine.utils;

import com.esotericsoftware.spine.*;
import com.esotericsoftware.spine.Animation.*;
import com.esotericsoftware.spine.AnimationState.*;
import com.esotericsoftware.spine.BoneData.Inherit;
import com.esotericsoftware.spine.Skin.SkinEntry;
import com.esotericsoftware.spine.PathConstraintData.*;
import com.esotericsoftware.spine.TransformConstraintData.*;
import com.esotericsoftware.spine.attachments.*;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.utils.Array;
import com.badlogic.gdx.utils.IntArray;
import com.badlogic.gdx.utils.FloatArray;

import java.util.Locale;
import java.util.Set;
import java.util.HashSet;

public class SkeletonSerializer {
    private final Set<Object> visitedObjects = new HashSet<>();

    public String serializeSkeletonData(SkeletonData data) {
        visitedObjects.clear();
        JsonWriter json = new JsonWriter();
        writeSkeletonData(json, data);
        json.close();
        return json.getString();
    }

    public String serializeSkeleton(Skeleton skeleton) {
        visitedObjects.clear();
        JsonWriter json = new JsonWriter();
        writeSkeleton(json, skeleton);
        json.close();
        return json.getString();
    }

    public String serializeAnimationState(AnimationState state) {
        visitedObjects.clear();
        JsonWriter json = new JsonWriter();
        writeAnimationState(json, state);
        json.close();
        return json.getString();
    }

    private void writeAnimation(JsonWriter json, Animation obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Animation");

        json.writeName("timelines");
        json.writeArrayStart();
        for (Timeline item : obj.getTimelines()) {
            writeTimeline(json, item);
        }
        json.writeArrayEnd();

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeName("bones");
        json.writeArrayStart();
        for (int i = 0; i < obj.getBones().size; i++) {
            json.writeValue(obj.getBones().get(i));
        }
        json.writeArrayEnd();

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writeAlphaTimeline(JsonWriter json, Animation.AlphaTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("AlphaTimeline");

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeAttachmentTimeline(JsonWriter json, Animation.AttachmentTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("AttachmentTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("attachmentNames");
        json.writeArrayStart();
        for (String item : obj.getAttachmentNames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeDeformTimeline(JsonWriter json, Animation.DeformTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("DeformTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("attachment");
        writeVertexAttachment(json, obj.getAttachment());

        json.writeName("vertices");
        json.writeArrayStart();
        for (float[] nestedArray : obj.getVertices()) {
            if (nestedArray == null) {
                json.writeNull();
            } else {
                json.writeArrayStart();
                for (float elem : nestedArray) {
                    json.writeValue(elem);
                }
                json.writeArrayEnd();
            }
        }
        json.writeArrayEnd();

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeDrawOrderTimeline(JsonWriter json, Animation.DrawOrderTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("DrawOrderTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("drawOrders");
        json.writeArrayStart();
        for (int[] nestedArray : obj.getDrawOrders()) {
            if (nestedArray == null) {
                json.writeNull();
            } else {
                json.writeArrayStart();
                for (int elem : nestedArray) {
                    json.writeValue(elem);
                }
                json.writeArrayEnd();
            }
        }
        json.writeArrayEnd();

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeEventTimeline(JsonWriter json, Animation.EventTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("EventTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("events");
        json.writeArrayStart();
        for (Event item : obj.getEvents()) {
            writeEvent(json, item);
        }
        json.writeArrayEnd();

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeIkConstraintTimeline(JsonWriter json, Animation.IkConstraintTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("IkConstraintTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeInheritTimeline(JsonWriter json, Animation.InheritTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("InheritTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePathConstraintMixTimeline(JsonWriter json, Animation.PathConstraintMixTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PathConstraintMixTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePathConstraintPositionTimeline(JsonWriter json, Animation.PathConstraintPositionTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PathConstraintPositionTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePathConstraintSpacingTimeline(JsonWriter json, Animation.PathConstraintSpacingTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PathConstraintSpacingTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintDampingTimeline(JsonWriter json, Animation.PhysicsConstraintDampingTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintDampingTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintGravityTimeline(JsonWriter json, Animation.PhysicsConstraintGravityTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintGravityTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintInertiaTimeline(JsonWriter json, Animation.PhysicsConstraintInertiaTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintInertiaTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintMassTimeline(JsonWriter json, Animation.PhysicsConstraintMassTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintMassTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintMixTimeline(JsonWriter json, Animation.PhysicsConstraintMixTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintMixTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintResetTimeline(JsonWriter json, Animation.PhysicsConstraintResetTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintResetTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintStrengthTimeline(JsonWriter json, Animation.PhysicsConstraintStrengthTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintStrengthTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintWindTimeline(JsonWriter json, Animation.PhysicsConstraintWindTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintWindTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeRGB2Timeline(JsonWriter json, Animation.RGB2Timeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("RGB2Timeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeRGBA2Timeline(JsonWriter json, Animation.RGBA2Timeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("RGBA2Timeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeRGBATimeline(JsonWriter json, Animation.RGBATimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("RGBATimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeRGBTimeline(JsonWriter json, Animation.RGBTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("RGBTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeRotateTimeline(JsonWriter json, Animation.RotateTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("RotateTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeScaleTimeline(JsonWriter json, Animation.ScaleTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ScaleTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeScaleXTimeline(JsonWriter json, Animation.ScaleXTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ScaleXTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeScaleYTimeline(JsonWriter json, Animation.ScaleYTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ScaleYTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeSequenceTimeline(JsonWriter json, Animation.SequenceTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SequenceTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("attachment");
        writeAttachment(json, obj.getAttachment());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeShearTimeline(JsonWriter json, Animation.ShearTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ShearTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeShearXTimeline(JsonWriter json, Animation.ShearXTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ShearXTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeShearYTimeline(JsonWriter json, Animation.ShearYTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ShearYTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeSliderMixTimeline(JsonWriter json, Animation.SliderMixTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SliderMixTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeSliderTimeline(JsonWriter json, Animation.SliderTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SliderTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeTimeline(JsonWriter json, Animation.Timeline obj) {
        if (obj instanceof Animation.AlphaTimeline) {
            writeAlphaTimeline(json, (Animation.AlphaTimeline) obj);
        } else if (obj instanceof Animation.AttachmentTimeline) {
            writeAttachmentTimeline(json, (Animation.AttachmentTimeline) obj);
        } else if (obj instanceof Animation.DeformTimeline) {
            writeDeformTimeline(json, (Animation.DeformTimeline) obj);
        } else if (obj instanceof Animation.DrawOrderTimeline) {
            writeDrawOrderTimeline(json, (Animation.DrawOrderTimeline) obj);
        } else if (obj instanceof Animation.EventTimeline) {
            writeEventTimeline(json, (Animation.EventTimeline) obj);
        } else if (obj instanceof Animation.IkConstraintTimeline) {
            writeIkConstraintTimeline(json, (Animation.IkConstraintTimeline) obj);
        } else if (obj instanceof Animation.InheritTimeline) {
            writeInheritTimeline(json, (Animation.InheritTimeline) obj);
        } else if (obj instanceof Animation.PathConstraintMixTimeline) {
            writePathConstraintMixTimeline(json, (Animation.PathConstraintMixTimeline) obj);
        } else if (obj instanceof Animation.PathConstraintPositionTimeline) {
            writePathConstraintPositionTimeline(json, (Animation.PathConstraintPositionTimeline) obj);
        } else if (obj instanceof Animation.PathConstraintSpacingTimeline) {
            writePathConstraintSpacingTimeline(json, (Animation.PathConstraintSpacingTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintDampingTimeline) {
            writePhysicsConstraintDampingTimeline(json, (Animation.PhysicsConstraintDampingTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintGravityTimeline) {
            writePhysicsConstraintGravityTimeline(json, (Animation.PhysicsConstraintGravityTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintInertiaTimeline) {
            writePhysicsConstraintInertiaTimeline(json, (Animation.PhysicsConstraintInertiaTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintMassTimeline) {
            writePhysicsConstraintMassTimeline(json, (Animation.PhysicsConstraintMassTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintMixTimeline) {
            writePhysicsConstraintMixTimeline(json, (Animation.PhysicsConstraintMixTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintResetTimeline) {
            writePhysicsConstraintResetTimeline(json, (Animation.PhysicsConstraintResetTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintStrengthTimeline) {
            writePhysicsConstraintStrengthTimeline(json, (Animation.PhysicsConstraintStrengthTimeline) obj);
        } else if (obj instanceof Animation.PhysicsConstraintWindTimeline) {
            writePhysicsConstraintWindTimeline(json, (Animation.PhysicsConstraintWindTimeline) obj);
        } else if (obj instanceof Animation.RGB2Timeline) {
            writeRGB2Timeline(json, (Animation.RGB2Timeline) obj);
        } else if (obj instanceof Animation.RGBA2Timeline) {
            writeRGBA2Timeline(json, (Animation.RGBA2Timeline) obj);
        } else if (obj instanceof Animation.RGBATimeline) {
            writeRGBATimeline(json, (Animation.RGBATimeline) obj);
        } else if (obj instanceof Animation.RGBTimeline) {
            writeRGBTimeline(json, (Animation.RGBTimeline) obj);
        } else if (obj instanceof Animation.RotateTimeline) {
            writeRotateTimeline(json, (Animation.RotateTimeline) obj);
        } else if (obj instanceof Animation.ScaleTimeline) {
            writeScaleTimeline(json, (Animation.ScaleTimeline) obj);
        } else if (obj instanceof Animation.ScaleXTimeline) {
            writeScaleXTimeline(json, (Animation.ScaleXTimeline) obj);
        } else if (obj instanceof Animation.ScaleYTimeline) {
            writeScaleYTimeline(json, (Animation.ScaleYTimeline) obj);
        } else if (obj instanceof Animation.SequenceTimeline) {
            writeSequenceTimeline(json, (Animation.SequenceTimeline) obj);
        } else if (obj instanceof Animation.ShearTimeline) {
            writeShearTimeline(json, (Animation.ShearTimeline) obj);
        } else if (obj instanceof Animation.ShearXTimeline) {
            writeShearXTimeline(json, (Animation.ShearXTimeline) obj);
        } else if (obj instanceof Animation.ShearYTimeline) {
            writeShearYTimeline(json, (Animation.ShearYTimeline) obj);
        } else if (obj instanceof Animation.SliderMixTimeline) {
            writeSliderMixTimeline(json, (Animation.SliderMixTimeline) obj);
        } else if (obj instanceof Animation.SliderTimeline) {
            writeSliderTimeline(json, (Animation.SliderTimeline) obj);
        } else if (obj instanceof Animation.TransformConstraintTimeline) {
            writeTransformConstraintTimeline(json, (Animation.TransformConstraintTimeline) obj);
        } else if (obj instanceof Animation.TranslateTimeline) {
            writeTranslateTimeline(json, (Animation.TranslateTimeline) obj);
        } else if (obj instanceof Animation.TranslateXTimeline) {
            writeTranslateXTimeline(json, (Animation.TranslateXTimeline) obj);
        } else if (obj instanceof Animation.TranslateYTimeline) {
            writeTranslateYTimeline(json, (Animation.TranslateYTimeline) obj);
        } else {
            throw new RuntimeException("Unknown Timeline type: " + obj.getClass().getName());
        }
    }

    private void writeTransformConstraintTimeline(JsonWriter json, Animation.TransformConstraintTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TransformConstraintTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("constraintIndex");
        json.writeValue(obj.getConstraintIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeTranslateTimeline(JsonWriter json, Animation.TranslateTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TranslateTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeTranslateXTimeline(JsonWriter json, Animation.TranslateXTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TranslateXTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeTranslateYTimeline(JsonWriter json, Animation.TranslateYTimeline obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TranslateYTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (String item : obj.getPropertyIds()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (float item : obj.getFrames()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private void writeAnimationState(JsonWriter json, AnimationState obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("AnimationState");

        json.writeName("timeScale");
        json.writeValue(obj.getTimeScale());

        json.writeName("data");
        writeAnimationStateData(json, obj.getData());

        json.writeName("tracks");
        json.writeArrayStart();
        for (TrackEntry item : obj.getTracks()) {
            writeTrackEntry(json, item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeTrackEntry(JsonWriter json, AnimationState.TrackEntry obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TrackEntry");

        json.writeName("trackIndex");
        json.writeValue(obj.getTrackIndex());

        json.writeName("animation");
        writeAnimation(json, obj.getAnimation());

        json.writeName("loop");
        json.writeValue(obj.getLoop());

        json.writeName("delay");
        json.writeValue(obj.getDelay());

        json.writeName("trackTime");
        json.writeValue(obj.getTrackTime());

        json.writeName("trackEnd");
        json.writeValue(obj.getTrackEnd());

        json.writeName("trackComplete");
        json.writeValue(obj.getTrackComplete());

        json.writeName("animationStart");
        json.writeValue(obj.getAnimationStart());

        json.writeName("animationEnd");
        json.writeValue(obj.getAnimationEnd());

        json.writeName("animationLast");
        json.writeValue(obj.getAnimationLast());

        json.writeName("animationTime");
        json.writeValue(obj.getAnimationTime());

        json.writeName("timeScale");
        json.writeValue(obj.getTimeScale());
        // Skipping excluded property: getListener()

        json.writeName("alpha");
        json.writeValue(obj.getAlpha());

        json.writeName("eventThreshold");
        json.writeValue(obj.getEventThreshold());

        json.writeName("alphaAttachmentThreshold");
        json.writeValue(obj.getAlphaAttachmentThreshold());

        json.writeName("mixAttachmentThreshold");
        json.writeValue(obj.getMixAttachmentThreshold());

        json.writeName("mixDrawOrderThreshold");
        json.writeValue(obj.getMixDrawOrderThreshold());

        json.writeName("next");
        if (obj.getNext() == null) {
            json.writeNull();
        } else {
            writeTrackEntry(json, obj.getNext());
        }

        json.writeName("previous");
        if (obj.getPrevious() == null) {
            json.writeNull();
        } else {
            writeTrackEntry(json, obj.getPrevious());
        }

        json.writeName("mixTime");
        json.writeValue(obj.getMixTime());

        json.writeName("mixDuration");
        json.writeValue(obj.getMixDuration());

        json.writeName("mixBlend");
        json.writeValue(obj.getMixBlend().name());

        json.writeName("mixingFrom");
        if (obj.getMixingFrom() == null) {
            json.writeNull();
        } else {
            writeTrackEntry(json, obj.getMixingFrom());
        }

        json.writeName("mixingTo");
        if (obj.getMixingTo() == null) {
            json.writeNull();
        } else {
            writeTrackEntry(json, obj.getMixingTo());
        }

        json.writeName("holdPrevious");
        json.writeValue(obj.getHoldPrevious());

        json.writeName("shortestRotation");
        json.writeValue(obj.getShortestRotation());

        json.writeName("reverse");
        json.writeValue(obj.getReverse());

        json.writeObjectEnd();
    }

    private void writeAnimationStateData(JsonWriter json, AnimationStateData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("AnimationStateData");

        json.writeName("skeletonData");
        writeSkeletonData(json, obj.getSkeletonData());

        json.writeName("defaultMix");
        json.writeValue(obj.getDefaultMix());

        json.writeObjectEnd();
    }

    private void writeAttachment(JsonWriter json, Attachment obj) {
        if (obj instanceof BoundingBoxAttachment) {
            writeBoundingBoxAttachment(json, (BoundingBoxAttachment) obj);
        } else if (obj instanceof ClippingAttachment) {
            writeClippingAttachment(json, (ClippingAttachment) obj);
        } else if (obj instanceof MeshAttachment) {
            writeMeshAttachment(json, (MeshAttachment) obj);
        } else if (obj instanceof PathAttachment) {
            writePathAttachment(json, (PathAttachment) obj);
        } else if (obj instanceof PointAttachment) {
            writePointAttachment(json, (PointAttachment) obj);
        } else if (obj instanceof RegionAttachment) {
            writeRegionAttachment(json, (RegionAttachment) obj);
        } else {
            throw new RuntimeException("Unknown Attachment type: " + obj.getClass().getName());
        }
    }

    private void writeBone(JsonWriter json, Bone obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Bone");

        json.writeName("parent");
        if (obj.getParent() == null) {
            json.writeNull();
        } else {
            writeBone(json, obj.getParent());
        }

        json.writeName("children");
        json.writeArrayStart();
        for (Bone item : obj.getChildren()) {
            writeBone(json, item);
        }
        json.writeArrayEnd();

        json.writeName("data");
        writeBoneData(json, obj.getData());

        json.writeName("pose");
        writeBoneLocal(json, obj.getPose());

        json.writeName("appliedPose");
        writeBonePose(json, obj.getAppliedPose());

        json.writeObjectEnd();
    }

    private void writeBoneData(JsonWriter json, BoneData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("BoneData");

        json.writeName("index");
        json.writeValue(obj.getIndex());

        json.writeName("parent");
        if (obj.getParent() == null) {
            json.writeNull();
        } else {
            writeBoneData(json, obj.getParent());
        }

        json.writeName("length");
        json.writeValue(obj.getLength());

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("icon");
        json.writeValue(obj.getIcon());

        json.writeName("visible");
        json.writeValue(obj.getVisible());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("setupPose");
        writeBoneLocal(json, obj.getSetupPose());

        json.writeName("skinRequired");
        json.writeValue(obj.getSkinRequired());

        json.writeObjectEnd();
    }

    private void writeBoneLocal(JsonWriter json, BoneLocal obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("BoneLocal");

        json.writeName("x");
        json.writeValue(obj.getX());

        json.writeName("y");
        json.writeValue(obj.getY());

        json.writeName("rotation");
        json.writeValue(obj.getRotation());

        json.writeName("scaleX");
        json.writeValue(obj.getScaleX());

        json.writeName("scaleY");
        json.writeValue(obj.getScaleY());

        json.writeName("shearX");
        json.writeValue(obj.getShearX());

        json.writeName("shearY");
        json.writeValue(obj.getShearY());

        json.writeName("inherit");
        json.writeValue(obj.getInherit().name());

        json.writeObjectEnd();
    }

    private void writeBonePose(JsonWriter json, BonePose obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("BonePose");

        json.writeName("a");
        json.writeValue(obj.getA());

        json.writeName("b");
        json.writeValue(obj.getB());

        json.writeName("c");
        json.writeValue(obj.getC());

        json.writeName("d");
        json.writeValue(obj.getD());

        json.writeName("worldX");
        json.writeValue(obj.getWorldX());

        json.writeName("worldY");
        json.writeValue(obj.getWorldY());

        json.writeName("worldRotationX");
        json.writeValue(obj.getWorldRotationX());

        json.writeName("worldRotationY");
        json.writeValue(obj.getWorldRotationY());

        json.writeName("worldScaleX");
        json.writeValue(obj.getWorldScaleX());

        json.writeName("worldScaleY");
        json.writeValue(obj.getWorldScaleY());

        json.writeName("x");
        json.writeValue(obj.getX());

        json.writeName("y");
        json.writeValue(obj.getY());

        json.writeName("rotation");
        json.writeValue(obj.getRotation());

        json.writeName("scaleX");
        json.writeValue(obj.getScaleX());

        json.writeName("scaleY");
        json.writeValue(obj.getScaleY());

        json.writeName("shearX");
        json.writeValue(obj.getShearX());

        json.writeName("shearY");
        json.writeValue(obj.getShearY());

        json.writeName("inherit");
        json.writeValue(obj.getInherit().name());

        json.writeObjectEnd();
    }

    private void writeBoundingBoxAttachment(JsonWriter json, BoundingBoxAttachment obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("BoundingBoxAttachment");

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("bones");
        if (obj.getBones() == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (int item : obj.getBones()) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (float item : obj.getVertices()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.getWorldVerticesLength());

        json.writeName("timelineAttachment");
        if (obj.getTimelineAttachment() == null) {
            json.writeNull();
        } else {
            writeAttachment(json, obj.getTimelineAttachment());
        }

        json.writeName("id");
        json.writeValue(obj.getId());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writeClippingAttachment(JsonWriter json, ClippingAttachment obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ClippingAttachment");

        json.writeName("endSlot");
        if (obj.getEndSlot() == null) {
            json.writeNull();
        } else {
            writeSlotData(json, obj.getEndSlot());
        }

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("bones");
        if (obj.getBones() == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (int item : obj.getBones()) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (float item : obj.getVertices()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.getWorldVerticesLength());

        json.writeName("timelineAttachment");
        if (obj.getTimelineAttachment() == null) {
            json.writeNull();
        } else {
            writeAttachment(json, obj.getTimelineAttachment());
        }

        json.writeName("id");
        json.writeValue(obj.getId());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writeConstraint(JsonWriter json, Constraint obj) {
        if (obj instanceof IkConstraint) {
            writeIkConstraint(json, (IkConstraint) obj);
        } else if (obj instanceof PathConstraint) {
            writePathConstraint(json, (PathConstraint) obj);
        } else if (obj instanceof PhysicsConstraint) {
            writePhysicsConstraint(json, (PhysicsConstraint) obj);
        } else if (obj instanceof Slider) {
            writeSlider(json, (Slider) obj);
        } else if (obj instanceof TransformConstraint) {
            writeTransformConstraint(json, (TransformConstraint) obj);
        } else {
            throw new RuntimeException("Unknown Constraint type: " + obj.getClass().getName());
        }
    }

    private void writeConstraintData(JsonWriter json, ConstraintData obj) {
        if (obj instanceof IkConstraintData) {
            writeIkConstraintData(json, (IkConstraintData) obj);
        } else if (obj instanceof PathConstraintData) {
            writePathConstraintData(json, (PathConstraintData) obj);
        } else if (obj instanceof PhysicsConstraintData) {
            writePhysicsConstraintData(json, (PhysicsConstraintData) obj);
        } else if (obj instanceof SliderData) {
            writeSliderData(json, (SliderData) obj);
        } else if (obj instanceof TransformConstraintData) {
            writeTransformConstraintData(json, (TransformConstraintData) obj);
        } else {
            throw new RuntimeException("Unknown ConstraintData type: " + obj.getClass().getName());
        }
    }

    private void writeEvent(JsonWriter json, Event obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Event");

        json.writeName("int");
        json.writeValue(obj.getInt());

        json.writeName("float");
        json.writeValue(obj.getFloat());

        json.writeName("string");
        json.writeValue(obj.getString());

        json.writeName("volume");
        json.writeValue(obj.getVolume());

        json.writeName("balance");
        json.writeValue(obj.getBalance());

        json.writeName("time");
        json.writeValue(obj.getTime());

        json.writeName("data");
        writeEventData(json, obj.getData());

        json.writeObjectEnd();
    }

    private void writeEventData(JsonWriter json, EventData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("EventData");

        json.writeName("int");
        json.writeValue(obj.getInt());

        json.writeName("float");
        json.writeValue(obj.getFloat());

        json.writeName("string");
        json.writeValue(obj.getString());

        json.writeName("audioPath");
        json.writeValue(obj.getAudioPath());

        json.writeName("volume");
        json.writeValue(obj.getVolume());

        json.writeName("balance");
        json.writeValue(obj.getBalance());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writeIkConstraint(JsonWriter json, IkConstraint obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("IkConstraint");

        json.writeName("bones");
        json.writeArrayStart();
        for (BonePose item : obj.getBones()) {
            writeBonePose(json, item);
        }
        json.writeArrayEnd();

        json.writeName("target");
        writeBone(json, obj.getTarget());

        json.writeName("data");
        writeIkConstraintData(json, obj.getData());

        json.writeName("pose");
        writeIkConstraintPose(json, obj.getPose());

        json.writeName("appliedPose");
        writeIkConstraintPose(json, obj.getAppliedPose());

        json.writeObjectEnd();
    }

    private void writeIkConstraintData(JsonWriter json, IkConstraintData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("IkConstraintData");

        json.writeName("bones");
        json.writeArrayStart();
        for (BoneData item : obj.getBones()) {
            writeBoneData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("target");
        writeBoneData(json, obj.getTarget());

        json.writeName("uniform");
        json.writeValue(obj.getUniform());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("setupPose");
        writeIkConstraintPose(json, obj.getSetupPose());

        json.writeName("skinRequired");
        json.writeValue(obj.getSkinRequired());

        json.writeObjectEnd();
    }

    private void writeIkConstraintPose(JsonWriter json, IkConstraintPose obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("IkConstraintPose");

        json.writeName("mix");
        json.writeValue(obj.getMix());

        json.writeName("softness");
        json.writeValue(obj.getSoftness());

        json.writeName("bendDirection");
        json.writeValue(obj.getBendDirection());

        json.writeName("compress");
        json.writeValue(obj.getCompress());

        json.writeName("stretch");
        json.writeValue(obj.getStretch());

        json.writeObjectEnd();
    }

    private void writeMeshAttachment(JsonWriter json, MeshAttachment obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("MeshAttachment");

        json.writeName("region");
        writeTextureRegion(json, obj.getRegion());

        json.writeName("triangles");
        json.writeArrayStart();
        for (short item : obj.getTriangles()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("regionUVs");
        json.writeArrayStart();
        for (float item : obj.getRegionUVs()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("uVs");
        json.writeArrayStart();
        for (float item : obj.getUVs()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("path");
        json.writeValue(obj.getPath());

        json.writeName("hullLength");
        json.writeValue(obj.getHullLength());

        json.writeName("edges");
        if (obj.getEdges() == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (short item : obj.getEdges()) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("width");
        json.writeValue(obj.getWidth());

        json.writeName("height");
        json.writeValue(obj.getHeight());

        json.writeName("sequence");
        if (obj.getSequence() == null) {
            json.writeNull();
        } else {
            writeSequence(json, obj.getSequence());
        }

        json.writeName("parentMesh");
        if (obj.getParentMesh() == null) {
            json.writeNull();
        } else {
            writeMeshAttachment(json, obj.getParentMesh());
        }

        json.writeName("bones");
        if (obj.getBones() == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (int item : obj.getBones()) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (float item : obj.getVertices()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.getWorldVerticesLength());

        json.writeName("timelineAttachment");
        if (obj.getTimelineAttachment() == null) {
            json.writeNull();
        } else {
            writeAttachment(json, obj.getTimelineAttachment());
        }

        json.writeName("id");
        json.writeValue(obj.getId());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writePathAttachment(JsonWriter json, PathAttachment obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PathAttachment");

        json.writeName("closed");
        json.writeValue(obj.getClosed());

        json.writeName("constantSpeed");
        json.writeValue(obj.getConstantSpeed());

        json.writeName("lengths");
        json.writeArrayStart();
        for (float item : obj.getLengths()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("bones");
        if (obj.getBones() == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (int item : obj.getBones()) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (float item : obj.getVertices()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.getWorldVerticesLength());

        json.writeName("timelineAttachment");
        if (obj.getTimelineAttachment() == null) {
            json.writeNull();
        } else {
            writeAttachment(json, obj.getTimelineAttachment());
        }

        json.writeName("id");
        json.writeValue(obj.getId());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writePathConstraint(JsonWriter json, PathConstraint obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PathConstraint");

        json.writeName("bones");
        json.writeArrayStart();
        for (BonePose item : obj.getBones()) {
            writeBonePose(json, item);
        }
        json.writeArrayEnd();

        json.writeName("slot");
        writeSlot(json, obj.getSlot());

        json.writeName("data");
        writePathConstraintData(json, obj.getData());

        json.writeName("pose");
        writePathConstraintPose(json, obj.getPose());

        json.writeName("appliedPose");
        writePathConstraintPose(json, obj.getAppliedPose());

        json.writeObjectEnd();
    }

    private void writePathConstraintData(JsonWriter json, PathConstraintData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PathConstraintData");

        json.writeName("bones");
        json.writeArrayStart();
        for (BoneData item : obj.getBones()) {
            writeBoneData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("slot");
        writeSlotData(json, obj.getSlot());

        json.writeName("positionMode");
        json.writeValue(obj.getPositionMode().name());

        json.writeName("spacingMode");
        json.writeValue(obj.getSpacingMode().name());

        json.writeName("rotateMode");
        json.writeValue(obj.getRotateMode().name());

        json.writeName("offsetRotation");
        json.writeValue(obj.getOffsetRotation());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("setupPose");
        writePathConstraintPose(json, obj.getSetupPose());

        json.writeName("skinRequired");
        json.writeValue(obj.getSkinRequired());

        json.writeObjectEnd();
    }

    private void writePathConstraintPose(JsonWriter json, PathConstraintPose obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PathConstraintPose");

        json.writeName("position");
        json.writeValue(obj.getPosition());

        json.writeName("spacing");
        json.writeValue(obj.getSpacing());

        json.writeName("mixRotate");
        json.writeValue(obj.getMixRotate());

        json.writeName("mixX");
        json.writeValue(obj.getMixX());

        json.writeName("mixY");
        json.writeValue(obj.getMixY());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraint(JsonWriter json, PhysicsConstraint obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraint");

        json.writeName("bone");
        writeBonePose(json, obj.getBone());

        json.writeName("data");
        writePhysicsConstraintData(json, obj.getData());

        json.writeName("pose");
        writePhysicsConstraintPose(json, obj.getPose());

        json.writeName("appliedPose");
        writePhysicsConstraintPose(json, obj.getAppliedPose());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintData(JsonWriter json, PhysicsConstraintData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintData");

        json.writeName("bone");
        writeBoneData(json, obj.getBone());

        json.writeName("step");
        json.writeValue(obj.getStep());

        json.writeName("x");
        json.writeValue(obj.getX());

        json.writeName("y");
        json.writeValue(obj.getY());

        json.writeName("rotate");
        json.writeValue(obj.getRotate());

        json.writeName("scaleX");
        json.writeValue(obj.getScaleX());

        json.writeName("shearX");
        json.writeValue(obj.getShearX());

        json.writeName("limit");
        json.writeValue(obj.getLimit());

        json.writeName("inertiaGlobal");
        json.writeValue(obj.getInertiaGlobal());

        json.writeName("strengthGlobal");
        json.writeValue(obj.getStrengthGlobal());

        json.writeName("dampingGlobal");
        json.writeValue(obj.getDampingGlobal());

        json.writeName("massGlobal");
        json.writeValue(obj.getMassGlobal());

        json.writeName("windGlobal");
        json.writeValue(obj.getWindGlobal());

        json.writeName("gravityGlobal");
        json.writeValue(obj.getGravityGlobal());

        json.writeName("mixGlobal");
        json.writeValue(obj.getMixGlobal());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("setupPose");
        writePhysicsConstraintPose(json, obj.getSetupPose());

        json.writeName("skinRequired");
        json.writeValue(obj.getSkinRequired());

        json.writeObjectEnd();
    }

    private void writePhysicsConstraintPose(JsonWriter json, PhysicsConstraintPose obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PhysicsConstraintPose");

        json.writeName("inertia");
        json.writeValue(obj.getInertia());

        json.writeName("strength");
        json.writeValue(obj.getStrength());

        json.writeName("damping");
        json.writeValue(obj.getDamping());

        json.writeName("massInverse");
        json.writeValue(obj.getMassInverse());

        json.writeName("wind");
        json.writeValue(obj.getWind());

        json.writeName("gravity");
        json.writeValue(obj.getGravity());

        json.writeName("mix");
        json.writeValue(obj.getMix());

        json.writeObjectEnd();
    }

    private void writePointAttachment(JsonWriter json, PointAttachment obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("PointAttachment");

        json.writeName("x");
        json.writeValue(obj.getX());

        json.writeName("y");
        json.writeValue(obj.getY());

        json.writeName("rotation");
        json.writeValue(obj.getRotation());

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writeRegionAttachment(JsonWriter json, RegionAttachment obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("RegionAttachment");

        json.writeName("region");
        writeTextureRegion(json, obj.getRegion());

        json.writeName("offset");
        json.writeArrayStart();
        for (float item : obj.getOffset()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("uVs");
        json.writeArrayStart();
        for (float item : obj.getUVs()) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("x");
        json.writeValue(obj.getX());

        json.writeName("y");
        json.writeValue(obj.getY());

        json.writeName("scaleX");
        json.writeValue(obj.getScaleX());

        json.writeName("scaleY");
        json.writeValue(obj.getScaleY());

        json.writeName("rotation");
        json.writeValue(obj.getRotation());

        json.writeName("width");
        json.writeValue(obj.getWidth());

        json.writeName("height");
        json.writeValue(obj.getHeight());

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("path");
        json.writeValue(obj.getPath());

        json.writeName("sequence");
        if (obj.getSequence() == null) {
            json.writeNull();
        } else {
            writeSequence(json, obj.getSequence());
        }

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeObjectEnd();
    }

    private void writeSequence(JsonWriter json, Sequence obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Sequence");

        json.writeName("start");
        json.writeValue(obj.getStart());

        json.writeName("digits");
        json.writeValue(obj.getDigits());

        json.writeName("setupIndex");
        json.writeValue(obj.getSetupIndex());

        json.writeName("regions");
        json.writeArrayStart();
        for (TextureRegion item : obj.getRegions()) {
            writeTextureRegion(json, item);
        }
        json.writeArrayEnd();

        json.writeName("id");
        json.writeValue(obj.getId());

        json.writeObjectEnd();
    }

    private void writeSkeleton(JsonWriter json, Skeleton obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Skeleton");

        json.writeName("data");
        writeSkeletonData(json, obj.getData());

        json.writeName("bones");
        json.writeArrayStart();
        for (Bone item : obj.getBones()) {
            writeBone(json, item);
        }
        json.writeArrayEnd();

        json.writeName("updateCache");
        json.writeArrayStart();
        for (Update item : obj.getUpdateCache()) {
            writeUpdate(json, item);
        }
        json.writeArrayEnd();

        json.writeName("rootBone");
        writeBone(json, obj.getRootBone());

        json.writeName("slots");
        json.writeArrayStart();
        for (Slot item : obj.getSlots()) {
            writeSlot(json, item);
        }
        json.writeArrayEnd();

        json.writeName("drawOrder");
        json.writeArrayStart();
        for (Slot item : obj.getDrawOrder()) {
            writeSlot(json, item);
        }
        json.writeArrayEnd();

        json.writeName("skin");
        if (obj.getSkin() == null) {
            json.writeNull();
        } else {
            writeSkin(json, obj.getSkin());
        }

        json.writeName("constraints");
        json.writeArrayStart();
        for (Constraint item : obj.getConstraints()) {
            writeConstraint(json, item);
        }
        json.writeArrayEnd();

        json.writeName("physicsConstraints");
        json.writeArrayStart();
        for (PhysicsConstraint item : obj.getPhysicsConstraints()) {
            writePhysicsConstraint(json, item);
        }
        json.writeArrayEnd();

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("scaleX");
        json.writeValue(obj.getScaleX());

        json.writeName("scaleY");
        json.writeValue(obj.getScaleY());

        json.writeName("x");
        json.writeValue(obj.getX());

        json.writeName("y");
        json.writeValue(obj.getY());

        json.writeName("windX");
        json.writeValue(obj.getWindX());

        json.writeName("windY");
        json.writeValue(obj.getWindY());

        json.writeName("gravityX");
        json.writeValue(obj.getGravityX());

        json.writeName("gravityY");
        json.writeValue(obj.getGravityY());

        json.writeName("time");
        json.writeValue(obj.getTime());

        json.writeObjectEnd();
    }

    private void writeSkeletonData(JsonWriter json, SkeletonData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SkeletonData");

        json.writeName("bones");
        json.writeArrayStart();
        for (BoneData item : obj.getBones()) {
            writeBoneData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("slots");
        json.writeArrayStart();
        for (SlotData item : obj.getSlots()) {
            writeSlotData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("defaultSkin");
        if (obj.getDefaultSkin() == null) {
            json.writeNull();
        } else {
            writeSkin(json, obj.getDefaultSkin());
        }

        json.writeName("skins");
        json.writeArrayStart();
        for (Skin item : obj.getSkins()) {
            writeSkin(json, item);
        }
        json.writeArrayEnd();

        json.writeName("events");
        json.writeArrayStart();
        for (EventData item : obj.getEvents()) {
            writeEventData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("animations");
        json.writeArrayStart();
        for (Animation item : obj.getAnimations()) {
            writeAnimation(json, item);
        }
        json.writeArrayEnd();

        json.writeName("constraints");
        json.writeArrayStart();
        for (ConstraintData item : obj.getConstraints()) {
            writeConstraintData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("x");
        json.writeValue(obj.getX());

        json.writeName("y");
        json.writeValue(obj.getY());

        json.writeName("width");
        json.writeValue(obj.getWidth());

        json.writeName("height");
        json.writeValue(obj.getHeight());

        json.writeName("referenceScale");
        json.writeValue(obj.getReferenceScale());

        json.writeName("version");
        json.writeValue(obj.getVersion());

        json.writeName("hash");
        json.writeValue(obj.getHash());

        json.writeName("imagesPath");
        json.writeValue(obj.getImagesPath());

        json.writeName("audioPath");
        json.writeValue(obj.getAudioPath());

        json.writeName("fps");
        json.writeValue(obj.getFps());

        json.writeObjectEnd();
    }

    private void writeSkin(JsonWriter json, Skin obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Skin");

        json.writeName("attachments");
        json.writeArrayStart();
        for (SkinEntry item : obj.getAttachments()) {
            writeSkinEntry(json, item);
        }
        json.writeArrayEnd();

        json.writeName("bones");
        json.writeArrayStart();
        for (BoneData item : obj.getBones()) {
            writeBoneData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("constraints");
        json.writeArrayStart();
        for (ConstraintData item : obj.getConstraints()) {
            writeConstraintData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeObjectEnd();
    }

    private void writeSkinEntry(JsonWriter json, Skin.SkinEntry obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SkinEntry");

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("attachment");
        writeAttachment(json, obj.getAttachment());

        json.writeObjectEnd();
    }

    private void writeSlider(JsonWriter json, Slider obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Slider");

        json.writeName("bone");
        writeBone(json, obj.getBone());

        json.writeName("data");
        writeSliderData(json, obj.getData());

        json.writeName("pose");
        writeSliderPose(json, obj.getPose());

        json.writeName("appliedPose");
        writeSliderPose(json, obj.getAppliedPose());

        json.writeObjectEnd();
    }

    private void writeSliderData(JsonWriter json, SliderData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SliderData");

        json.writeName("animation");
        writeAnimation(json, obj.getAnimation());

        json.writeName("additive");
        json.writeValue(obj.getAdditive());

        json.writeName("loop");
        json.writeValue(obj.getLoop());

        json.writeName("bone");
        if (obj.getBone() == null) {
            json.writeNull();
        } else {
            writeBoneData(json, obj.getBone());
        }

        json.writeName("property");
        if (obj.getProperty() == null) {
            json.writeNull();
        } else {
            writeFromProperty(json, obj.getProperty());
        }

        json.writeName("offset");
        json.writeValue(obj.getOffset());

        json.writeName("scale");
        json.writeValue(obj.getScale());

        json.writeName("local");
        json.writeValue(obj.getLocal());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("setupPose");
        writeSliderPose(json, obj.getSetupPose());

        json.writeName("skinRequired");
        json.writeValue(obj.getSkinRequired());

        json.writeObjectEnd();
    }

    private void writeSliderPose(JsonWriter json, SliderPose obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SliderPose");

        json.writeName("time");
        json.writeValue(obj.getTime());

        json.writeName("mix");
        json.writeValue(obj.getMix());

        json.writeObjectEnd();
    }

    private void writeSlot(JsonWriter json, Slot obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("Slot");

        json.writeName("bone");
        writeBone(json, obj.getBone());

        json.writeName("data");
        writeSlotData(json, obj.getData());

        json.writeName("pose");
        writeSlotPose(json, obj.getPose());

        json.writeName("appliedPose");
        writeSlotPose(json, obj.getAppliedPose());

        json.writeObjectEnd();
    }

    private void writeSlotData(JsonWriter json, SlotData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SlotData");

        json.writeName("index");
        json.writeValue(obj.getIndex());

        json.writeName("boneData");
        writeBoneData(json, obj.getBoneData());

        json.writeName("attachmentName");
        json.writeValue(obj.getAttachmentName());

        json.writeName("blendMode");
        json.writeValue(obj.getBlendMode().name());

        json.writeName("visible");
        json.writeValue(obj.getVisible());

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("setupPose");
        writeSlotPose(json, obj.getSetupPose());

        json.writeName("skinRequired");
        json.writeValue(obj.getSkinRequired());

        json.writeObjectEnd();
    }

    private void writeSlotPose(JsonWriter json, SlotPose obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("SlotPose");

        json.writeName("color");
        writeColor(json, obj.getColor());

        json.writeName("darkColor");
        writeColor(json, obj.getDarkColor());

        json.writeName("attachment");
        if (obj.getAttachment() == null) {
            json.writeNull();
        } else {
            writeAttachment(json, obj.getAttachment());
        }

        json.writeName("sequenceIndex");
        json.writeValue(obj.getSequenceIndex());

        json.writeName("deform");
        json.writeArrayStart();
        for (int i = 0; i < obj.getDeform().size; i++) {
            json.writeValue(obj.getDeform().get(i));
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeTransformConstraint(JsonWriter json, TransformConstraint obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TransformConstraint");

        json.writeName("bones");
        json.writeArrayStart();
        for (BonePose item : obj.getBones()) {
            writeBonePose(json, item);
        }
        json.writeArrayEnd();

        json.writeName("source");
        writeBone(json, obj.getSource());

        json.writeName("data");
        writeTransformConstraintData(json, obj.getData());

        json.writeName("pose");
        writeTransformConstraintPose(json, obj.getPose());

        json.writeName("appliedPose");
        writeTransformConstraintPose(json, obj.getAppliedPose());

        json.writeObjectEnd();
    }

    private void writeTransformConstraintData(JsonWriter json, TransformConstraintData obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TransformConstraintData");

        json.writeName("bones");
        json.writeArrayStart();
        for (BoneData item : obj.getBones()) {
            writeBoneData(json, item);
        }
        json.writeArrayEnd();

        json.writeName("source");
        writeBoneData(json, obj.getSource());

        json.writeName("offsetRotation");
        json.writeValue(obj.getOffsetRotation());

        json.writeName("offsetX");
        json.writeValue(obj.getOffsetX());

        json.writeName("offsetY");
        json.writeValue(obj.getOffsetY());

        json.writeName("offsetScaleX");
        json.writeValue(obj.getOffsetScaleX());

        json.writeName("offsetScaleY");
        json.writeValue(obj.getOffsetScaleY());

        json.writeName("offsetShearY");
        json.writeValue(obj.getOffsetShearY());

        json.writeName("localSource");
        json.writeValue(obj.getLocalSource());

        json.writeName("localTarget");
        json.writeValue(obj.getLocalTarget());

        json.writeName("additive");
        json.writeValue(obj.getAdditive());

        json.writeName("clamp");
        json.writeValue(obj.getClamp());

        json.writeName("properties");
        json.writeArrayStart();
        for (FromProperty item : obj.getProperties()) {
            writeFromProperty(json, item);
        }
        json.writeArrayEnd();

        json.writeName("name");
        json.writeValue(obj.getName());

        json.writeName("setupPose");
        writeTransformConstraintPose(json, obj.getSetupPose());

        json.writeName("skinRequired");
        json.writeValue(obj.getSkinRequired());

        json.writeObjectEnd();
    }

    private void writeFromProperty(JsonWriter json, TransformConstraintData.FromProperty obj) {
        if (obj instanceof TransformConstraintData.FromRotate) {
            writeFromRotate(json, (TransformConstraintData.FromRotate) obj);
        } else if (obj instanceof TransformConstraintData.FromScaleX) {
            writeFromScaleX(json, (TransformConstraintData.FromScaleX) obj);
        } else if (obj instanceof TransformConstraintData.FromScaleY) {
            writeFromScaleY(json, (TransformConstraintData.FromScaleY) obj);
        } else if (obj instanceof TransformConstraintData.FromShearY) {
            writeFromShearY(json, (TransformConstraintData.FromShearY) obj);
        } else if (obj instanceof TransformConstraintData.FromX) {
            writeFromX(json, (TransformConstraintData.FromX) obj);
        } else if (obj instanceof TransformConstraintData.FromY) {
            writeFromY(json, (TransformConstraintData.FromY) obj);
        } else {
            throw new RuntimeException("Unknown FromProperty type: " + obj.getClass().getName());
        }
    }

    private void writeFromRotate(JsonWriter json, TransformConstraintData.FromRotate obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("FromRotate");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (ToProperty item : obj.to) {
            writeToProperty(json, item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeFromScaleX(JsonWriter json, TransformConstraintData.FromScaleX obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("FromScaleX");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (ToProperty item : obj.to) {
            writeToProperty(json, item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeFromScaleY(JsonWriter json, TransformConstraintData.FromScaleY obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("FromScaleY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (ToProperty item : obj.to) {
            writeToProperty(json, item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeFromShearY(JsonWriter json, TransformConstraintData.FromShearY obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("FromShearY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (ToProperty item : obj.to) {
            writeToProperty(json, item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeFromX(JsonWriter json, TransformConstraintData.FromX obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("FromX");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (ToProperty item : obj.to) {
            writeToProperty(json, item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeFromY(JsonWriter json, TransformConstraintData.FromY obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("FromY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (ToProperty item : obj.to) {
            writeToProperty(json, item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private void writeToProperty(JsonWriter json, TransformConstraintData.ToProperty obj) {
        if (obj instanceof TransformConstraintData.ToRotate) {
            writeToRotate(json, (TransformConstraintData.ToRotate) obj);
        } else if (obj instanceof TransformConstraintData.ToScaleX) {
            writeToScaleX(json, (TransformConstraintData.ToScaleX) obj);
        } else if (obj instanceof TransformConstraintData.ToScaleY) {
            writeToScaleY(json, (TransformConstraintData.ToScaleY) obj);
        } else if (obj instanceof TransformConstraintData.ToShearY) {
            writeToShearY(json, (TransformConstraintData.ToShearY) obj);
        } else if (obj instanceof TransformConstraintData.ToX) {
            writeToX(json, (TransformConstraintData.ToX) obj);
        } else if (obj instanceof TransformConstraintData.ToY) {
            writeToY(json, (TransformConstraintData.ToY) obj);
        } else {
            throw new RuntimeException("Unknown ToProperty type: " + obj.getClass().getName());
        }
    }

    private void writeToRotate(JsonWriter json, TransformConstraintData.ToRotate obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ToRotate");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("max");
        json.writeValue(obj.max);

        json.writeName("scale");
        json.writeValue(obj.scale);

        json.writeObjectEnd();
    }

    private void writeToScaleX(JsonWriter json, TransformConstraintData.ToScaleX obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ToScaleX");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("max");
        json.writeValue(obj.max);

        json.writeName("scale");
        json.writeValue(obj.scale);

        json.writeObjectEnd();
    }

    private void writeToScaleY(JsonWriter json, TransformConstraintData.ToScaleY obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ToScaleY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("max");
        json.writeValue(obj.max);

        json.writeName("scale");
        json.writeValue(obj.scale);

        json.writeObjectEnd();
    }

    private void writeToShearY(JsonWriter json, TransformConstraintData.ToShearY obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ToShearY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("max");
        json.writeValue(obj.max);

        json.writeName("scale");
        json.writeValue(obj.scale);

        json.writeObjectEnd();
    }

    private void writeToX(JsonWriter json, TransformConstraintData.ToX obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ToX");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("max");
        json.writeValue(obj.max);

        json.writeName("scale");
        json.writeValue(obj.scale);

        json.writeObjectEnd();
    }

    private void writeToY(JsonWriter json, TransformConstraintData.ToY obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("ToY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("max");
        json.writeValue(obj.max);

        json.writeName("scale");
        json.writeValue(obj.scale);

        json.writeObjectEnd();
    }

    private void writeTransformConstraintPose(JsonWriter json, TransformConstraintPose obj) {
        if (visitedObjects.contains(obj)) {
            json.writeValue("<circular>");
            return;
        }
        visitedObjects.add(obj);

        json.writeObjectStart();
        json.writeName("type");
        json.writeValue("TransformConstraintPose");

        json.writeName("mixRotate");
        json.writeValue(obj.getMixRotate());

        json.writeName("mixX");
        json.writeValue(obj.getMixX());

        json.writeName("mixY");
        json.writeValue(obj.getMixY());

        json.writeName("mixScaleX");
        json.writeValue(obj.getMixScaleX());

        json.writeName("mixScaleY");
        json.writeValue(obj.getMixScaleY());

        json.writeName("mixShearY");
        json.writeValue(obj.getMixShearY());

        json.writeObjectEnd();
    }

    private void writeUpdate(JsonWriter json, Update obj) {
        if (obj instanceof BonePose) {
            writeBonePose(json, (BonePose) obj);
        } else if (obj instanceof IkConstraint) {
            writeIkConstraint(json, (IkConstraint) obj);
        } else if (obj instanceof PathConstraint) {
            writePathConstraint(json, (PathConstraint) obj);
        } else if (obj instanceof PhysicsConstraint) {
            writePhysicsConstraint(json, (PhysicsConstraint) obj);
        } else if (obj instanceof Slider) {
            writeSlider(json, (Slider) obj);
        } else if (obj instanceof TransformConstraint) {
            writeTransformConstraint(json, (TransformConstraint) obj);
        } else {
            throw new RuntimeException("Unknown Update type: " + obj.getClass().getName());
        }
    }

    private void writeVertexAttachment(JsonWriter json, VertexAttachment obj) {
        if (obj instanceof BoundingBoxAttachment) {
            writeBoundingBoxAttachment(json, (BoundingBoxAttachment) obj);
        } else if (obj instanceof ClippingAttachment) {
            writeClippingAttachment(json, (ClippingAttachment) obj);
        } else if (obj instanceof MeshAttachment) {
            writeMeshAttachment(json, (MeshAttachment) obj);
        } else if (obj instanceof PathAttachment) {
            writePathAttachment(json, (PathAttachment) obj);
        } else {
            throw new RuntimeException("Unknown VertexAttachment type: " + obj.getClass().getName());
        }
    }

    private void writeColor(JsonWriter json, Color color) {
        if (color == null) {
            json.writeNull();
        } else {
            json.writeObjectStart();
            json.writeName("r");
            json.writeValue(color.r);
            json.writeName("g");
            json.writeValue(color.g);
            json.writeName("b");
            json.writeValue(color.b);
            json.writeName("a");
            json.writeValue(color.a);
            json.writeObjectEnd();
        }
    }

    private void writeTextureRegion(JsonWriter json, TextureRegion region) {
        if (region == null) {
            json.writeNull();
        } else {
            json.writeObjectStart();
            json.writeName("u");
            json.writeValue(region.getU());
            json.writeName("v");
            json.writeValue(region.getV());
            json.writeName("u2");
            json.writeValue(region.getU2());
            json.writeName("v2");
            json.writeValue(region.getV2());
            json.writeName("width");
            json.writeValue(region.getRegionWidth());
            json.writeName("height");
            json.writeValue(region.getRegionHeight());
            json.writeObjectEnd();
        }
    }
}