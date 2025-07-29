package spine.utils;

import haxe.ds.ObjectMap;
import spine.*;
import spine.animation.*;
import spine.attachments.*;

class SkeletonSerializer {
    private var visitedObjects:ObjectMap<Dynamic, String> = new ObjectMap();
    private var nextId:Int = 1;
    private var json:JsonWriter;

    public function new() {}

    public function serializeSkeletonData(data:SkeletonData):String {
        visitedObjects = new ObjectMap();
        nextId = 1;
        json = new JsonWriter();
        writeSkeletonData(data);
        return json.getString();
    }

    public function serializeSkeleton(skeleton:Skeleton):String {
        visitedObjects = new ObjectMap();
        nextId = 1;
        json = new JsonWriter();
        writeSkeleton(skeleton);
        return json.getString();
    }

    public function serializeAnimationState(state:AnimationState):String {
        visitedObjects = new ObjectMap();
        nextId = 1;
        json = new JsonWriter();
        writeAnimationState(state);
        return json.getString();
    }

    private function writeAnimation(obj:Animation):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<Animation-" + obj.name + ">" : "<Animation-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Animation");

        json.writeName("timelines");
        json.writeArrayStart();
        for (item in obj.timelines) {
            writeTimeline(item);
        }
        json.writeArrayEnd();

        json.writeName("duration");
        json.writeValue(obj.duration);

        json.writeName("bones");
        writeIntArray(obj.bones);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writeAlphaTimeline(obj:AlphaTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<AlphaTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("AlphaTimeline");

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeAttachmentTimeline(obj:AttachmentTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<AttachmentTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("AttachmentTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("attachmentNames");
        json.writeArrayStart();
        for (item in obj.attachmentNames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeDeformTimeline(obj:DeformTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<DeformTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("DeformTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("attachment");
        writeVertexAttachment(obj.attachment);

        json.writeName("vertices");
        json.writeArrayStart();
        for (nestedArray in obj.vertices) {
            if (nestedArray == null) {
                json.writeNull();
            } else {
                json.writeArrayStart();
                for (elem in nestedArray) {
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
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeDrawOrderTimeline(obj:DrawOrderTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<DrawOrderTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("DrawOrderTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("drawOrders");
        json.writeArrayStart();
        for (nestedArray in obj.drawOrders) {
            if (nestedArray == null) {
                json.writeNull();
            } else {
                json.writeArrayStart();
                for (elem in nestedArray) {
                    json.writeValue(elem);
                }
                json.writeArrayEnd();
            }
        }
        json.writeArrayEnd();

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeEventTimeline(obj:EventTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<EventTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("EventTimeline");

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("events");
        json.writeArrayStart();
        for (item in obj.events) {
            writeEvent(item);
        }
        json.writeArrayEnd();

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeIkConstraintTimeline(obj:IkConstraintTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<IkConstraintTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("IkConstraintTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeInheritTimeline(obj:InheritTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<InheritTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("InheritTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePathConstraintMixTimeline(obj:PathConstraintMixTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PathConstraintMixTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PathConstraintMixTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePathConstraintPositionTimeline(obj:PathConstraintPositionTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PathConstraintPositionTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PathConstraintPositionTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePathConstraintSpacingTimeline(obj:PathConstraintSpacingTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PathConstraintSpacingTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PathConstraintSpacingTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintDampingTimeline(obj:PhysicsConstraintDampingTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintDampingTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintDampingTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintGravityTimeline(obj:PhysicsConstraintGravityTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintGravityTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintGravityTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintInertiaTimeline(obj:PhysicsConstraintInertiaTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintInertiaTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintInertiaTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintMassTimeline(obj:PhysicsConstraintMassTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintMassTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintMassTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintMixTimeline(obj:PhysicsConstraintMixTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintMixTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintMixTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintResetTimeline(obj:PhysicsConstraintResetTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintResetTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintResetTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintStrengthTimeline(obj:PhysicsConstraintStrengthTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintStrengthTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintStrengthTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintWindTimeline(obj:PhysicsConstraintWindTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintWindTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintWindTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeRGB2Timeline(obj:RGB2Timeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<RGB2Timeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("RGB2Timeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeRGBA2Timeline(obj:RGBA2Timeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<RGBA2Timeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("RGBA2Timeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeRGBATimeline(obj:RGBATimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<RGBATimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("RGBATimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeRGBTimeline(obj:RGBTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<RGBTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("RGBTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeRotateTimeline(obj:RotateTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<RotateTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("RotateTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeScaleTimeline(obj:ScaleTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ScaleTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("ScaleTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeScaleXTimeline(obj:ScaleXTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ScaleXTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("ScaleXTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeScaleYTimeline(obj:ScaleYTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ScaleYTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("ScaleYTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeSequenceTimeline(obj:SequenceTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<SequenceTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SequenceTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("slotIndex");
        json.writeValue(obj.getSlotIndex());

        json.writeName("attachment");
        writeAttachment(obj.attachment);

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeShearTimeline(obj:ShearTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ShearTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("ShearTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeShearXTimeline(obj:ShearXTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ShearXTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("ShearXTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeShearYTimeline(obj:ShearYTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ShearYTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("ShearYTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeSliderMixTimeline(obj:SliderMixTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<SliderMixTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SliderMixTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeSliderTimeline(obj:SliderTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<SliderTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SliderTimeline");

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeTimeline(obj:Timeline):Void {
        if (Std.isOfType(obj, AlphaTimeline)) {
            writeAlphaTimeline(cast(obj, AlphaTimeline));
        } else if (Std.isOfType(obj, AttachmentTimeline)) {
            writeAttachmentTimeline(cast(obj, AttachmentTimeline));
        } else if (Std.isOfType(obj, DeformTimeline)) {
            writeDeformTimeline(cast(obj, DeformTimeline));
        } else if (Std.isOfType(obj, DrawOrderTimeline)) {
            writeDrawOrderTimeline(cast(obj, DrawOrderTimeline));
        } else if (Std.isOfType(obj, EventTimeline)) {
            writeEventTimeline(cast(obj, EventTimeline));
        } else if (Std.isOfType(obj, IkConstraintTimeline)) {
            writeIkConstraintTimeline(cast(obj, IkConstraintTimeline));
        } else if (Std.isOfType(obj, InheritTimeline)) {
            writeInheritTimeline(cast(obj, InheritTimeline));
        } else if (Std.isOfType(obj, PathConstraintMixTimeline)) {
            writePathConstraintMixTimeline(cast(obj, PathConstraintMixTimeline));
        } else if (Std.isOfType(obj, PathConstraintPositionTimeline)) {
            writePathConstraintPositionTimeline(cast(obj, PathConstraintPositionTimeline));
        } else if (Std.isOfType(obj, PathConstraintSpacingTimeline)) {
            writePathConstraintSpacingTimeline(cast(obj, PathConstraintSpacingTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintDampingTimeline)) {
            writePhysicsConstraintDampingTimeline(cast(obj, PhysicsConstraintDampingTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintGravityTimeline)) {
            writePhysicsConstraintGravityTimeline(cast(obj, PhysicsConstraintGravityTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintInertiaTimeline)) {
            writePhysicsConstraintInertiaTimeline(cast(obj, PhysicsConstraintInertiaTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintMassTimeline)) {
            writePhysicsConstraintMassTimeline(cast(obj, PhysicsConstraintMassTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintMixTimeline)) {
            writePhysicsConstraintMixTimeline(cast(obj, PhysicsConstraintMixTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintResetTimeline)) {
            writePhysicsConstraintResetTimeline(cast(obj, PhysicsConstraintResetTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintStrengthTimeline)) {
            writePhysicsConstraintStrengthTimeline(cast(obj, PhysicsConstraintStrengthTimeline));
        } else if (Std.isOfType(obj, PhysicsConstraintWindTimeline)) {
            writePhysicsConstraintWindTimeline(cast(obj, PhysicsConstraintWindTimeline));
        } else if (Std.isOfType(obj, RGB2Timeline)) {
            writeRGB2Timeline(cast(obj, RGB2Timeline));
        } else if (Std.isOfType(obj, RGBA2Timeline)) {
            writeRGBA2Timeline(cast(obj, RGBA2Timeline));
        } else if (Std.isOfType(obj, RGBATimeline)) {
            writeRGBATimeline(cast(obj, RGBATimeline));
        } else if (Std.isOfType(obj, RGBTimeline)) {
            writeRGBTimeline(cast(obj, RGBTimeline));
        } else if (Std.isOfType(obj, RotateTimeline)) {
            writeRotateTimeline(cast(obj, RotateTimeline));
        } else if (Std.isOfType(obj, ScaleTimeline)) {
            writeScaleTimeline(cast(obj, ScaleTimeline));
        } else if (Std.isOfType(obj, ScaleXTimeline)) {
            writeScaleXTimeline(cast(obj, ScaleXTimeline));
        } else if (Std.isOfType(obj, ScaleYTimeline)) {
            writeScaleYTimeline(cast(obj, ScaleYTimeline));
        } else if (Std.isOfType(obj, SequenceTimeline)) {
            writeSequenceTimeline(cast(obj, SequenceTimeline));
        } else if (Std.isOfType(obj, ShearTimeline)) {
            writeShearTimeline(cast(obj, ShearTimeline));
        } else if (Std.isOfType(obj, ShearXTimeline)) {
            writeShearXTimeline(cast(obj, ShearXTimeline));
        } else if (Std.isOfType(obj, ShearYTimeline)) {
            writeShearYTimeline(cast(obj, ShearYTimeline));
        } else if (Std.isOfType(obj, SliderMixTimeline)) {
            writeSliderMixTimeline(cast(obj, SliderMixTimeline));
        } else if (Std.isOfType(obj, SliderTimeline)) {
            writeSliderTimeline(cast(obj, SliderTimeline));
        } else if (Std.isOfType(obj, TransformConstraintTimeline)) {
            writeTransformConstraintTimeline(cast(obj, TransformConstraintTimeline));
        } else if (Std.isOfType(obj, TranslateTimeline)) {
            writeTranslateTimeline(cast(obj, TranslateTimeline));
        } else if (Std.isOfType(obj, TranslateXTimeline)) {
            writeTranslateXTimeline(cast(obj, TranslateXTimeline));
        } else if (Std.isOfType(obj, TranslateYTimeline)) {
            writeTranslateYTimeline(cast(obj, TranslateYTimeline));
        } else {
            throw new spine.SpineException("Unknown Timeline type");
        }
    }

    private function writeTransformConstraintTimeline(obj:TransformConstraintTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<TransformConstraintTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TransformConstraintTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("constraintIndex");
        json.writeValue(obj.constraintIndex);

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeTranslateTimeline(obj:TranslateTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<TranslateTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TranslateTimeline");

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeTranslateXTimeline(obj:TranslateXTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<TranslateXTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TranslateXTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeTranslateYTimeline(obj:TranslateYTimeline):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<TranslateYTimeline-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TranslateYTimeline");

        json.writeName("boneIndex");
        json.writeValue(obj.getBoneIndex());

        json.writeName("frameEntries");
        json.writeValue(obj.getFrameEntries());

        json.writeName("propertyIds");
        json.writeArrayStart();
        for (item in obj.propertyIds) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frames");
        json.writeArrayStart();
        for (item in obj.frames) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("frameCount");
        json.writeValue(obj.getFrameCount());

        json.writeName("duration");
        json.writeValue(obj.getDuration());

        json.writeObjectEnd();
    }

    private function writeAnimationState(obj:AnimationState):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<AnimationState-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("AnimationState");

        json.writeName("timeScale");
        json.writeValue(obj.timeScale);

        json.writeName("data");
        writeAnimationStateData(obj.data);

        json.writeName("tracks");
        json.writeArrayStart();
        for (item in obj.tracks) {
            writeTrackEntry(item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private function writeTrackEntry(obj:TrackEntry):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<TrackEntry-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TrackEntry");

        json.writeName("trackIndex");
        json.writeValue(obj.trackIndex);

        json.writeName("animation");
        writeAnimation(obj.animation);

        json.writeName("loop");
        json.writeValue(obj.loop);

        json.writeName("delay");
        json.writeValue(obj.delay);

        json.writeName("trackTime");
        json.writeValue(obj.trackTime);

        json.writeName("trackEnd");
        json.writeValue(obj.trackEnd);

        json.writeName("trackComplete");
        json.writeValue(obj.getTrackComplete());

        json.writeName("animationStart");
        json.writeValue(obj.animationStart);

        json.writeName("animationEnd");
        json.writeValue(obj.animationEnd);

        json.writeName("animationLast");
        json.writeValue(obj.animationLast);

        json.writeName("animationTime");
        json.writeValue(obj.getAnimationTime());

        json.writeName("timeScale");
        json.writeValue(obj.timeScale);

        json.writeName("alpha");
        json.writeValue(obj.alpha);

        json.writeName("eventThreshold");
        json.writeValue(obj.eventThreshold);

        json.writeName("alphaAttachmentThreshold");
        json.writeValue(obj.alphaAttachmentThreshold);

        json.writeName("mixAttachmentThreshold");
        json.writeValue(obj.mixAttachmentThreshold);

        json.writeName("mixDrawOrderThreshold");
        json.writeValue(obj.mixDrawOrderThreshold);

        json.writeName("next");
        if (obj.next == null) {
            json.writeNull();
        } else {
            writeTrackEntry(obj.next);
        }

        json.writeName("previous");
        if (obj.previous == null) {
            json.writeNull();
        } else {
            writeTrackEntry(obj.previous);
        }

        json.writeName("mixTime");
        json.writeValue(obj.mixTime);

        json.writeName("mixDuration");
        json.writeValue(obj.mixDuration);

        json.writeName("mixBlend");
        switch (obj.mixBlend) {
            case MixBlend.setup: json.writeValue("setup");
            case MixBlend.first: json.writeValue("first");
            case MixBlend.replace: json.writeValue("replace");
            case MixBlend.add: json.writeValue("add");
            default: json.writeValue("unknown");
        }

        json.writeName("mixingFrom");
        if (obj.mixingFrom == null) {
            json.writeNull();
        } else {
            writeTrackEntry(obj.mixingFrom);
        }

        json.writeName("mixingTo");
        if (obj.mixingTo == null) {
            json.writeNull();
        } else {
            writeTrackEntry(obj.mixingTo);
        }

        json.writeName("holdPrevious");
        json.writeValue(obj.holdPrevious);

        json.writeName("shortestRotation");
        json.writeValue(obj.shortestRotation);

        json.writeName("reverse");
        json.writeValue(obj.reverse);

        json.writeObjectEnd();
    }

    private function writeAnimationStateData(obj:AnimationStateData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<AnimationStateData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("AnimationStateData");

        json.writeName("skeletonData");
        writeSkeletonData(obj.skeletonData);

        json.writeName("defaultMix");
        json.writeValue(obj.defaultMix);

        json.writeObjectEnd();
    }

    private function writeAttachment(obj:Attachment):Void {
        if (Std.isOfType(obj, BoundingBoxAttachment)) {
            writeBoundingBoxAttachment(cast(obj, BoundingBoxAttachment));
        } else if (Std.isOfType(obj, ClippingAttachment)) {
            writeClippingAttachment(cast(obj, ClippingAttachment));
        } else if (Std.isOfType(obj, MeshAttachment)) {
            writeMeshAttachment(cast(obj, MeshAttachment));
        } else if (Std.isOfType(obj, PathAttachment)) {
            writePathAttachment(cast(obj, PathAttachment));
        } else if (Std.isOfType(obj, PointAttachment)) {
            writePointAttachment(cast(obj, PointAttachment));
        } else if (Std.isOfType(obj, RegionAttachment)) {
            writeRegionAttachment(cast(obj, RegionAttachment));
        } else {
            throw new spine.SpineException("Unknown Attachment type");
        }
    }

    private function writeBone(obj:Bone):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<Bone-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Bone");

        json.writeName("parent");
        if (obj.parent == null) {
            json.writeNull();
        } else {
            writeBone(obj.parent);
        }

        json.writeName("children");
        json.writeArrayStart();
        for (item in obj.children) {
            writeBone(item);
        }
        json.writeArrayEnd();

        json.writeName("data");
        writeBoneData(obj.data);

        json.writeName("pose");
        writeBoneLocal(obj.pose);

        json.writeName("appliedPose");
        writeBonePose(obj.applied);

        json.writeObjectEnd();
    }

    private function writeBoneData(obj:BoneData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<BoneData-" + obj.name + ">" : "<BoneData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("BoneData");

        json.writeName("index");
        json.writeValue(obj.index);

        json.writeName("parent");
        if (obj.parent == null) {
            json.writeNull();
        } else {
            writeBoneData(obj.parent);
        }

        json.writeName("length");
        json.writeValue(obj.length);

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("icon");
        json.writeValue(obj.icon);

        json.writeName("visible");
        json.writeValue(obj.visible);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("setupPose");
        writeBoneLocal(obj.setup);

        json.writeName("skinRequired");
        json.writeValue(obj.skinRequired);

        json.writeObjectEnd();
    }

    private function writeBoneLocal(obj:BoneLocal):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<BoneLocal-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("BoneLocal");

        json.writeName("x");
        json.writeValue(obj.x);

        json.writeName("y");
        json.writeValue(obj.y);

        json.writeName("rotation");
        json.writeValue(obj.rotation);

        json.writeName("scaleX");
        json.writeValue(obj.scaleX);

        json.writeName("scaleY");
        json.writeValue(obj.scaleY);

        json.writeName("shearX");
        json.writeValue(obj.shearX);

        json.writeName("shearY");
        json.writeValue(obj.shearY);

        json.writeName("inherit");
        switch (obj.inherit) {
            case Inherit.normal: json.writeValue("normal");
            case Inherit.onlyTranslation: json.writeValue("onlyTranslation");
            case Inherit.noRotationOrReflection: json.writeValue("noRotationOrReflection");
            case Inherit.noScale: json.writeValue("noScale");
            case Inherit.noScaleOrReflection: json.writeValue("noScaleOrReflection");
            default: json.writeValue("unknown");
        }

        json.writeObjectEnd();
    }

    private function writeBonePose(obj:BonePose):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<BonePose-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("BonePose");

        json.writeName("a");
        json.writeValue(obj.a);

        json.writeName("b");
        json.writeValue(obj.b);

        json.writeName("c");
        json.writeValue(obj.c);

        json.writeName("d");
        json.writeValue(obj.d);

        json.writeName("worldX");
        json.writeValue(obj.worldX);

        json.writeName("worldY");
        json.writeValue(obj.worldY);

        json.writeName("worldRotationX");
        json.writeValue(obj.worldRotationX);

        json.writeName("worldRotationY");
        json.writeValue(obj.worldRotationY);

        json.writeName("worldScaleX");
        json.writeValue(obj.worldScaleX);

        json.writeName("worldScaleY");
        json.writeValue(obj.worldScaleY);

        json.writeName("x");
        json.writeValue(obj.x);

        json.writeName("y");
        json.writeValue(obj.y);

        json.writeName("rotation");
        json.writeValue(obj.rotation);

        json.writeName("scaleX");
        json.writeValue(obj.scaleX);

        json.writeName("scaleY");
        json.writeValue(obj.scaleY);

        json.writeName("shearX");
        json.writeValue(obj.shearX);

        json.writeName("shearY");
        json.writeValue(obj.shearY);

        json.writeName("inherit");
        switch (obj.inherit) {
            case Inherit.normal: json.writeValue("normal");
            case Inherit.onlyTranslation: json.writeValue("onlyTranslation");
            case Inherit.noRotationOrReflection: json.writeValue("noRotationOrReflection");
            case Inherit.noScale: json.writeValue("noScale");
            case Inherit.noScaleOrReflection: json.writeValue("noScaleOrReflection");
            default: json.writeValue("unknown");
        }

        json.writeObjectEnd();
    }

    private function writeBoundingBoxAttachment(obj:BoundingBoxAttachment):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<BoundingBoxAttachment-" + obj.name + ">" : "<BoundingBoxAttachment-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("BoundingBoxAttachment");

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("bones");
        if (obj.bones == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (item in obj.bones) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (item in obj.vertices) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.worldVerticesLength);

        json.writeName("timelineAttachment");
        if (obj.timelineAttachment == null) {
            json.writeNull();
        } else {
            writeAttachment(obj.timelineAttachment);
        }

        json.writeName("id");
        json.writeValue(obj.id);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writeClippingAttachment(obj:ClippingAttachment):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<ClippingAttachment-" + obj.name + ">" : "<ClippingAttachment-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("ClippingAttachment");

        json.writeName("endSlot");
        if (obj.endSlot == null) {
            json.writeNull();
        } else {
            writeSlotData(obj.endSlot);
        }

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("bones");
        if (obj.bones == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (item in obj.bones) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (item in obj.vertices) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.worldVerticesLength);

        json.writeName("timelineAttachment");
        if (obj.timelineAttachment == null) {
            json.writeNull();
        } else {
            writeAttachment(obj.timelineAttachment);
        }

        json.writeName("id");
        json.writeValue(obj.id);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writeConstraint(obj:Constraint<Dynamic, Dynamic, Dynamic>):Void {
        if (Std.isOfType(obj, IkConstraint)) {
            writeIkConstraint(cast(obj, IkConstraint));
        } else if (Std.isOfType(obj, PathConstraint)) {
            writePathConstraint(cast(obj, PathConstraint));
        } else if (Std.isOfType(obj, PhysicsConstraint)) {
            writePhysicsConstraint(cast(obj, PhysicsConstraint));
        } else if (Std.isOfType(obj, Slider)) {
            writeSlider(cast(obj, Slider));
        } else if (Std.isOfType(obj, TransformConstraint)) {
            writeTransformConstraint(cast(obj, TransformConstraint));
        } else {
            throw new spine.SpineException("Unknown Constraint type");
        }
    }

    private function writeConstraintData(obj:ConstraintData<Dynamic, Dynamic>):Void {
        if (Std.isOfType(obj, IkConstraintData)) {
            writeIkConstraintData(cast(obj, IkConstraintData));
        } else if (Std.isOfType(obj, PathConstraintData)) {
            writePathConstraintData(cast(obj, PathConstraintData));
        } else if (Std.isOfType(obj, PhysicsConstraintData)) {
            writePhysicsConstraintData(cast(obj, PhysicsConstraintData));
        } else if (Std.isOfType(obj, SliderData)) {
            writeSliderData(cast(obj, SliderData));
        } else if (Std.isOfType(obj, TransformConstraintData)) {
            writeTransformConstraintData(cast(obj, TransformConstraintData));
        } else {
            throw new spine.SpineException("Unknown ConstraintData type");
        }
    }

    private function writeEvent(obj:Event):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<Event-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Event");

        json.writeName("int");
        json.writeValue(obj.intValue);

        json.writeName("float");
        json.writeValue(obj.floatValue);

        json.writeName("string");
        json.writeValue(obj.stringValue);

        json.writeName("volume");
        json.writeValue(obj.volume);

        json.writeName("balance");
        json.writeValue(obj.balance);

        json.writeName("time");
        json.writeValue(obj.time);

        json.writeName("data");
        writeEventData(obj.data);

        json.writeObjectEnd();
    }

    private function writeEventData(obj:EventData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<EventData-" + obj.name + ">" : "<EventData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("EventData");

        json.writeName("int");
        json.writeValue(obj.intValue);

        json.writeName("float");
        json.writeValue(obj.floatValue);

        json.writeName("string");
        json.writeValue(obj.stringValue);

        json.writeName("audioPath");
        json.writeValue(obj.audioPath);

        json.writeName("volume");
        json.writeValue(obj.volume);

        json.writeName("balance");
        json.writeValue(obj.balance);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writeIkConstraint(obj:IkConstraint):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<IkConstraint-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("IkConstraint");

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBonePose(item);
        }
        json.writeArrayEnd();

        json.writeName("target");
        writeBone(obj.target);

        json.writeName("data");
        writeIkConstraintData(obj.data);

        json.writeName("pose");
        writeIkConstraintPose(obj.pose);

        json.writeName("appliedPose");
        writeIkConstraintPose(obj.applied);

        json.writeObjectEnd();
    }

    private function writeIkConstraintData(obj:IkConstraintData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<IkConstraintData-" + obj.name + ">" : "<IkConstraintData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("IkConstraintData");

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBoneData(item);
        }
        json.writeArrayEnd();

        json.writeName("target");
        writeBoneData(obj.target);

        json.writeName("uniform");
        json.writeValue(obj.uniform);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("setupPose");
        writeIkConstraintPose(obj.setup);

        json.writeName("skinRequired");
        json.writeValue(obj.skinRequired);

        json.writeObjectEnd();
    }

    private function writeIkConstraintPose(obj:IkConstraintPose):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<IkConstraintPose-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("IkConstraintPose");

        json.writeName("mix");
        json.writeValue(obj.mix);

        json.writeName("softness");
        json.writeValue(obj.softness);

        json.writeName("bendDirection");
        json.writeValue(obj.bendDirection);

        json.writeName("compress");
        json.writeValue(obj.compress);

        json.writeName("stretch");
        json.writeValue(obj.stretch);

        json.writeObjectEnd();
    }

    private function writeMeshAttachment(obj:MeshAttachment):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<MeshAttachment-" + obj.name + ">" : "<MeshAttachment-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("MeshAttachment");

        json.writeName("region");
        if (obj.region == null) {
            json.writeNull();
        } else {
            writeTextureRegion(obj.region);
        }

        json.writeName("triangles");
        json.writeArrayStart();
        for (item in obj.triangles) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("regionUVs");
        json.writeArrayStart();
        for (item in obj.regionUVs) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("uVs");
        json.writeArrayStart();
        for (item in obj.uvs) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("path");
        json.writeValue(obj.path);

        json.writeName("hullLength");
        json.writeValue(obj.hullLength);

        json.writeName("edges");
        if (obj.edges == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (item in obj.edges) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("width");
        json.writeValue(obj.width);

        json.writeName("height");
        json.writeValue(obj.height);

        json.writeName("sequence");
        if (obj.sequence == null) {
            json.writeNull();
        } else {
            writeSequence(obj.sequence);
        }

        json.writeName("parentMesh");
        if (obj.parentMesh == null) {
            json.writeNull();
        } else {
            writeMeshAttachment(obj.parentMesh);
        }

        json.writeName("bones");
        if (obj.bones == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (item in obj.bones) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (item in obj.vertices) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.worldVerticesLength);

        json.writeName("timelineAttachment");
        if (obj.timelineAttachment == null) {
            json.writeNull();
        } else {
            writeAttachment(obj.timelineAttachment);
        }

        json.writeName("id");
        json.writeValue(obj.id);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writePathAttachment(obj:PathAttachment):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<PathAttachment-" + obj.name + ">" : "<PathAttachment-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PathAttachment");

        json.writeName("closed");
        json.writeValue(obj.closed);

        json.writeName("constantSpeed");
        json.writeValue(obj.constantSpeed);

        json.writeName("lengths");
        json.writeArrayStart();
        for (item in obj.lengths) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("bones");
        if (obj.bones == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (item in obj.bones) {
                json.writeValue(item);
            }
            json.writeArrayEnd();
        }

        json.writeName("vertices");
        json.writeArrayStart();
        for (item in obj.vertices) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("worldVerticesLength");
        json.writeValue(obj.worldVerticesLength);

        json.writeName("timelineAttachment");
        if (obj.timelineAttachment == null) {
            json.writeNull();
        } else {
            writeAttachment(obj.timelineAttachment);
        }

        json.writeName("id");
        json.writeValue(obj.id);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writePathConstraint(obj:PathConstraint):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PathConstraint-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PathConstraint");

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBonePose(item);
        }
        json.writeArrayEnd();

        json.writeName("slot");
        writeSlot(obj.slot);

        json.writeName("data");
        writePathConstraintData(obj.data);

        json.writeName("pose");
        writePathConstraintPose(obj.pose);

        json.writeName("appliedPose");
        writePathConstraintPose(obj.applied);

        json.writeObjectEnd();
    }

    private function writePathConstraintData(obj:PathConstraintData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<PathConstraintData-" + obj.name + ">" : "<PathConstraintData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PathConstraintData");

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBoneData(item);
        }
        json.writeArrayEnd();

        json.writeName("slot");
        writeSlotData(obj.slot);

        json.writeName("positionMode");
        switch (obj.positionMode) {
            case PositionMode.fixed: json.writeValue("fixed");
            case PositionMode.percent: json.writeValue("percent");
            default: json.writeValue("unknown");
        }

        json.writeName("spacingMode");
        switch (obj.spacingMode) {
            case SpacingMode.length: json.writeValue("length");
            case SpacingMode.fixed: json.writeValue("fixed");
            case SpacingMode.percent: json.writeValue("percent");
            case SpacingMode.proportional: json.writeValue("proportional");
            default: json.writeValue("unknown");
        }

        json.writeName("rotateMode");
        switch (obj.rotateMode) {
            case RotateMode.tangent: json.writeValue("tangent");
            case RotateMode.chain: json.writeValue("chain");
            case RotateMode.chainScale: json.writeValue("chainScale");
            default: json.writeValue("unknown");
        }

        json.writeName("offsetRotation");
        json.writeValue(obj.offsetRotation);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("setupPose");
        writePathConstraintPose(obj.setup);

        json.writeName("skinRequired");
        json.writeValue(obj.skinRequired);

        json.writeObjectEnd();
    }

    private function writePathConstraintPose(obj:PathConstraintPose):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PathConstraintPose-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PathConstraintPose");

        json.writeName("position");
        json.writeValue(obj.position);

        json.writeName("spacing");
        json.writeValue(obj.spacing);

        json.writeName("mixRotate");
        json.writeValue(obj.mixRotate);

        json.writeName("mixX");
        json.writeValue(obj.mixX);

        json.writeName("mixY");
        json.writeValue(obj.mixY);

        json.writeObjectEnd();
    }

    private function writePhysicsConstraint(obj:PhysicsConstraint):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraint-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraint");

        json.writeName("bone");
        writeBonePose(obj.bone);

        json.writeName("data");
        writePhysicsConstraintData(obj.data);

        json.writeName("pose");
        writePhysicsConstraintPose(obj.pose);

        json.writeName("appliedPose");
        writePhysicsConstraintPose(obj.applied);

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintData(obj:PhysicsConstraintData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<PhysicsConstraintData-" + obj.name + ">" : "<PhysicsConstraintData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintData");

        json.writeName("bone");
        writeBoneData(obj.bone);

        json.writeName("step");
        json.writeValue(obj.step);

        json.writeName("x");
        json.writeValue(obj.x);

        json.writeName("y");
        json.writeValue(obj.y);

        json.writeName("rotate");
        json.writeValue(obj.rotate);

        json.writeName("scaleX");
        json.writeValue(obj.scaleX);

        json.writeName("shearX");
        json.writeValue(obj.shearX);

        json.writeName("limit");
        json.writeValue(obj.limit);

        json.writeName("inertiaGlobal");
        json.writeValue(obj.inertiaGlobal);

        json.writeName("strengthGlobal");
        json.writeValue(obj.strengthGlobal);

        json.writeName("dampingGlobal");
        json.writeValue(obj.dampingGlobal);

        json.writeName("massGlobal");
        json.writeValue(obj.massGlobal);

        json.writeName("windGlobal");
        json.writeValue(obj.windGlobal);

        json.writeName("gravityGlobal");
        json.writeValue(obj.gravityGlobal);

        json.writeName("mixGlobal");
        json.writeValue(obj.mixGlobal);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("setupPose");
        writePhysicsConstraintPose(obj.setup);

        json.writeName("skinRequired");
        json.writeValue(obj.skinRequired);

        json.writeObjectEnd();
    }

    private function writePhysicsConstraintPose(obj:PhysicsConstraintPose):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<PhysicsConstraintPose-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PhysicsConstraintPose");

        json.writeName("inertia");
        json.writeValue(obj.inertia);

        json.writeName("strength");
        json.writeValue(obj.strength);

        json.writeName("damping");
        json.writeValue(obj.damping);

        json.writeName("massInverse");
        json.writeValue(obj.massInverse);

        json.writeName("wind");
        json.writeValue(obj.wind);

        json.writeName("gravity");
        json.writeValue(obj.gravity);

        json.writeName("mix");
        json.writeValue(obj.mix);

        json.writeObjectEnd();
    }

    private function writePointAttachment(obj:PointAttachment):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<PointAttachment-" + obj.name + ">" : "<PointAttachment-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("PointAttachment");

        json.writeName("x");
        json.writeValue(obj.x);

        json.writeName("y");
        json.writeValue(obj.y);

        json.writeName("rotation");
        json.writeValue(obj.rotation);

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writeRegionAttachment(obj:RegionAttachment):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<RegionAttachment-" + obj.name + ">" : "<RegionAttachment-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("RegionAttachment");

        json.writeName("region");
        if (obj.region == null) {
            json.writeNull();
        } else {
            writeTextureRegion(obj.region);
        }

        json.writeName("uVs");
        json.writeArrayStart();
        for (item in obj.uvs) {
            json.writeValue(item);
        }
        json.writeArrayEnd();

        json.writeName("x");
        json.writeValue(obj.x);

        json.writeName("y");
        json.writeValue(obj.y);

        json.writeName("scaleX");
        json.writeValue(obj.scaleX);

        json.writeName("scaleY");
        json.writeValue(obj.scaleY);

        json.writeName("rotation");
        json.writeValue(obj.rotation);

        json.writeName("width");
        json.writeValue(obj.width);

        json.writeName("height");
        json.writeValue(obj.height);

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("path");
        json.writeValue(obj.path);

        json.writeName("sequence");
        if (obj.sequence == null) {
            json.writeNull();
        } else {
            writeSequence(obj.sequence);
        }

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeObjectEnd();
    }

    private function writeSequence(obj:Sequence):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<Sequence-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Sequence");

        json.writeName("start");
        json.writeValue(obj.start);

        json.writeName("digits");
        json.writeValue(obj.digits);

        json.writeName("setupIndex");
        json.writeValue(obj.setupIndex);

        json.writeName("regions");
        json.writeArrayStart();
        for (item in obj.regions) {
            writeTextureRegion(item);
        }
        json.writeArrayEnd();

        json.writeName("id");
        json.writeValue(obj.id);

        json.writeObjectEnd();
    }

    private function writeSkeleton(obj:Skeleton):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<Skeleton-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Skeleton");

        json.writeName("data");
        writeSkeletonData(obj.data);

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBone(item);
        }
        json.writeArrayEnd();

        json.writeName("updateCache");
        json.writeArrayStart();
        for (item in obj.updateCache) {
            writeUpdate(item);
        }
        json.writeArrayEnd();

        json.writeName("rootBone");
        writeBone(obj.rootBone);

        json.writeName("slots");
        json.writeArrayStart();
        for (item in obj.slots) {
            writeSlot(item);
        }
        json.writeArrayEnd();

        json.writeName("drawOrder");
        json.writeArrayStart();
        for (item in obj.drawOrder) {
            writeSlot(item);
        }
        json.writeArrayEnd();

        json.writeName("skin");
        if (obj.skin == null) {
            json.writeNull();
        } else {
            writeSkin(obj.skin);
        }

        json.writeName("constraints");
        json.writeArrayStart();
        for (item in obj.constraints) {
            writeConstraint(item);
        }
        json.writeArrayEnd();

        json.writeName("physicsConstraints");
        json.writeArrayStart();
        for (item in obj.physics) {
            writePhysicsConstraint(item);
        }
        json.writeArrayEnd();

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("scaleX");
        json.writeValue(obj.scaleX);

        json.writeName("scaleY");
        json.writeValue(obj.scaleY);

        json.writeName("x");
        json.writeValue(obj.x);

        json.writeName("y");
        json.writeValue(obj.y);

        json.writeName("windX");
        json.writeValue(obj.windX);

        json.writeName("windY");
        json.writeValue(obj.windY);

        json.writeName("gravityX");
        json.writeValue(obj.gravityX);

        json.writeName("gravityY");
        json.writeValue(obj.gravityY);

        json.writeName("time");
        json.writeValue(obj.time);

        json.writeObjectEnd();
    }

    private function writeSkeletonData(obj:SkeletonData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<SkeletonData-" + obj.name + ">" : "<SkeletonData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SkeletonData");

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBoneData(item);
        }
        json.writeArrayEnd();

        json.writeName("slots");
        json.writeArrayStart();
        for (item in obj.slots) {
            writeSlotData(item);
        }
        json.writeArrayEnd();

        json.writeName("defaultSkin");
        if (obj.defaultSkin == null) {
            json.writeNull();
        } else {
            writeSkin(obj.defaultSkin);
        }

        json.writeName("skins");
        json.writeArrayStart();
        for (item in obj.skins) {
            writeSkin(item);
        }
        json.writeArrayEnd();

        json.writeName("events");
        json.writeArrayStart();
        for (item in obj.events) {
            writeEventData(item);
        }
        json.writeArrayEnd();

        json.writeName("animations");
        json.writeArrayStart();
        for (item in obj.animations) {
            writeAnimation(item);
        }
        json.writeArrayEnd();

        json.writeName("constraints");
        json.writeArrayStart();
        for (item in obj.constraints) {
            writeConstraintData(item);
        }
        json.writeArrayEnd();

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("x");
        json.writeValue(obj.x);

        json.writeName("y");
        json.writeValue(obj.y);

        json.writeName("width");
        json.writeValue(obj.width);

        json.writeName("height");
        json.writeValue(obj.height);

        json.writeName("referenceScale");
        json.writeValue(obj.referenceScale);

        json.writeName("version");
        json.writeValue(obj.version);

        json.writeName("hash");
        json.writeValue(obj.hash);

        json.writeName("imagesPath");
        json.writeValue(obj.imagesPath);

        json.writeName("audioPath");
        json.writeValue(obj.audioPath);

        json.writeName("fps");
        json.writeValue(obj.fps);

        json.writeObjectEnd();
    }

    private function writeSkin(obj:Skin):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<Skin-" + obj.name + ">" : "<Skin-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Skin");

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("attachments");
        json.writeArrayStart();
        var skinEntries = obj.getAttachments();
        for (entry in skinEntries) {
            writeSkinEntry(entry);
        }
        json.writeArrayEnd();

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBoneData(item);
        }
        json.writeArrayEnd();

        json.writeName("constraints");
        json.writeArrayStart();
        for (item in obj.constraints) {
            writeConstraintData(item);
        }
        json.writeArrayEnd();

        json.writeName("color");
        writeColor(obj.color);

        json.writeObjectEnd();
    }

    private function writeSkinEntry(obj:SkinEntry):Void {
        json.writeObjectStart();
        var refString = "<SkinEntry-" + (nextId++) + ">";
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SkinEntry");
        json.writeName("slotIndex");
        json.writeValue(obj.slotIndex);
        json.writeName("name");
        json.writeValue(obj.name);
        json.writeName("attachment");
        if (obj.attachment == null) {
            json.writeNull();
        } else {
            writeAttachment(obj.attachment);
        }
        json.writeObjectEnd();
    }

    private function writeSlider(obj:Slider):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<Slider-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Slider");

        json.writeName("bone");
        writeBone(obj.bone);

        json.writeName("data");
        writeSliderData(obj.data);

        json.writeName("pose");
        writeSliderPose(obj.pose);

        json.writeName("appliedPose");
        writeSliderPose(obj.applied);

        json.writeObjectEnd();
    }

    private function writeSliderData(obj:SliderData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<SliderData-" + obj.name + ">" : "<SliderData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SliderData");

        json.writeName("animation");
        writeAnimation(obj.animation);

        json.writeName("additive");
        json.writeValue(obj.additive);

        json.writeName("loop");
        json.writeValue(obj.loop);

        json.writeName("bone");
        if (obj.bone == null) {
            json.writeNull();
        } else {
            writeBoneData(obj.bone);
        }

        json.writeName("property");
        if (obj.property == null) {
            json.writeNull();
        } else {
            writeFromProperty(obj.property);
        }

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("scale");
        json.writeValue(obj.scale);

        json.writeName("local");
        json.writeValue(obj.local);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("setupPose");
        writeSliderPose(obj.setup);

        json.writeName("skinRequired");
        json.writeValue(obj.skinRequired);

        json.writeObjectEnd();
    }

    private function writeSliderPose(obj:SliderPose):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<SliderPose-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SliderPose");

        json.writeName("time");
        json.writeValue(obj.time);

        json.writeName("mix");
        json.writeValue(obj.mix);

        json.writeObjectEnd();
    }

    private function writeSlot(obj:Slot):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<Slot-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("Slot");

        json.writeName("bone");
        writeBone(obj.bone);

        json.writeName("data");
        writeSlotData(obj.data);

        json.writeName("pose");
        writeSlotPose(obj.pose);

        json.writeName("appliedPose");
        writeSlotPose(obj.applied);

        json.writeObjectEnd();
    }

    private function writeSlotData(obj:SlotData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<SlotData-" + obj.name + ">" : "<SlotData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SlotData");

        json.writeName("index");
        json.writeValue(obj.index);

        json.writeName("boneData");
        writeBoneData(obj.boneData);

        json.writeName("attachmentName");
        json.writeValue(obj.attachmentName);

        json.writeName("blendMode");
        switch (obj.blendMode) {
            case BlendMode.normal: json.writeValue("normal");
            case BlendMode.additive: json.writeValue("additive");
            case BlendMode.multiply: json.writeValue("multiply");
            case BlendMode.screen: json.writeValue("screen");
            default: json.writeValue("unknown");
        }

        json.writeName("visible");
        json.writeValue(obj.visible);

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("setupPose");
        writeSlotPose(obj.setup);

        json.writeName("skinRequired");
        json.writeValue(obj.skinRequired);

        json.writeObjectEnd();
    }

    private function writeSlotPose(obj:SlotPose):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<SlotPose-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("SlotPose");

        json.writeName("color");
        writeColor(obj.color);

        json.writeName("darkColor");
        if (obj.darkColor == null) {
            json.writeNull();
        } else {
            writeColor(obj.darkColor);
        }

        json.writeName("attachment");
        if (obj.attachment == null) {
            json.writeNull();
        } else {
            writeAttachment(obj.attachment);
        }

        json.writeName("sequenceIndex");
        json.writeValue(obj.sequenceIndex);

        json.writeName("deform");
        writeFloatArray(obj.deform);

        json.writeObjectEnd();
    }

    private function writeTransformConstraint(obj:TransformConstraint):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<TransformConstraint-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TransformConstraint");

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBonePose(item);
        }
        json.writeArrayEnd();

        json.writeName("source");
        writeBone(obj.source);

        json.writeName("data");
        writeTransformConstraintData(obj.data);

        json.writeName("pose");
        writeTransformConstraintPose(obj.pose);

        json.writeName("appliedPose");
        writeTransformConstraintPose(obj.applied);

        json.writeObjectEnd();
    }

    private function writeTransformConstraintData(obj:TransformConstraintData):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = obj.name != null ? "<TransformConstraintData-" + obj.name + ">" : "<TransformConstraintData-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TransformConstraintData");

        json.writeName("bones");
        json.writeArrayStart();
        for (item in obj.bones) {
            writeBoneData(item);
        }
        json.writeArrayEnd();

        json.writeName("source");
        writeBoneData(obj.source);

        json.writeName("offsetRotation");
        json.writeValue(obj.offsetRotation);

        json.writeName("offsetX");
        json.writeValue(obj.offsetX);

        json.writeName("offsetY");
        json.writeValue(obj.offsetY);

        json.writeName("offsetScaleX");
        json.writeValue(obj.offsetScaleX);

        json.writeName("offsetScaleY");
        json.writeValue(obj.offsetScaleY);

        json.writeName("offsetShearY");
        json.writeValue(obj.offsetShearY);

        json.writeName("localSource");
        json.writeValue(obj.localSource);

        json.writeName("localTarget");
        json.writeValue(obj.localTarget);

        json.writeName("additive");
        json.writeValue(obj.additive);

        json.writeName("clamp");
        json.writeValue(obj.clamp);

        json.writeName("properties");
        json.writeArrayStart();
        for (item in obj.properties) {
            writeFromProperty(item);
        }
        json.writeArrayEnd();

        json.writeName("name");
        json.writeValue(obj.name);

        json.writeName("setupPose");
        writeTransformConstraintPose(obj.setup);

        json.writeName("skinRequired");
        json.writeValue(obj.skinRequired);

        json.writeObjectEnd();
    }

    private function writeFromProperty(obj:TransformConstraintData.FromProperty):Void {
        if (Std.isOfType(obj, TransformConstraintData.FromRotate)) {
            writeFromRotate(cast(obj, TransformConstraintData.FromRotate));
        } else if (Std.isOfType(obj, TransformConstraintData.FromScaleX)) {
            writeFromScaleX(cast(obj, TransformConstraintData.FromScaleX));
        } else if (Std.isOfType(obj, TransformConstraintData.FromScaleY)) {
            writeFromScaleY(cast(obj, TransformConstraintData.FromScaleY));
        } else if (Std.isOfType(obj, TransformConstraintData.FromShearY)) {
            writeFromShearY(cast(obj, TransformConstraintData.FromShearY));
        } else if (Std.isOfType(obj, TransformConstraintData.FromX)) {
            writeFromX(cast(obj, TransformConstraintData.FromX));
        } else if (Std.isOfType(obj, TransformConstraintData.FromY)) {
            writeFromY(cast(obj, TransformConstraintData.FromY));
        } else {
            throw new spine.SpineException("Unknown FromProperty type");
        }
    }

    private function writeFromRotate(obj:TransformConstraintData.FromRotate):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<FromRotate-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("FromRotate");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (item in obj.to) {
            writeToProperty(item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private function writeFromScaleX(obj:TransformConstraintData.FromScaleX):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<FromScaleX-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("FromScaleX");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (item in obj.to) {
            writeToProperty(item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private function writeFromScaleY(obj:TransformConstraintData.FromScaleY):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<FromScaleY-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("FromScaleY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (item in obj.to) {
            writeToProperty(item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private function writeFromShearY(obj:TransformConstraintData.FromShearY):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<FromShearY-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("FromShearY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (item in obj.to) {
            writeToProperty(item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private function writeFromX(obj:TransformConstraintData.FromX):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<FromX-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("FromX");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (item in obj.to) {
            writeToProperty(item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private function writeFromY(obj:TransformConstraintData.FromY):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<FromY-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("FromY");

        json.writeName("offset");
        json.writeValue(obj.offset);

        json.writeName("to");
        json.writeArrayStart();
        for (item in obj.to) {
            writeToProperty(item);
        }
        json.writeArrayEnd();

        json.writeObjectEnd();
    }

    private function writeToProperty(obj:TransformConstraintData.ToProperty):Void {
        if (Std.isOfType(obj, TransformConstraintData.ToRotate)) {
            writeToRotate(cast(obj, TransformConstraintData.ToRotate));
        } else if (Std.isOfType(obj, TransformConstraintData.ToScaleX)) {
            writeToScaleX(cast(obj, TransformConstraintData.ToScaleX));
        } else if (Std.isOfType(obj, TransformConstraintData.ToScaleY)) {
            writeToScaleY(cast(obj, TransformConstraintData.ToScaleY));
        } else if (Std.isOfType(obj, TransformConstraintData.ToShearY)) {
            writeToShearY(cast(obj, TransformConstraintData.ToShearY));
        } else if (Std.isOfType(obj, TransformConstraintData.ToX)) {
            writeToX(cast(obj, TransformConstraintData.ToX));
        } else if (Std.isOfType(obj, TransformConstraintData.ToY)) {
            writeToY(cast(obj, TransformConstraintData.ToY));
        } else {
            throw new spine.SpineException("Unknown ToProperty type");
        }
    }

    private function writeToRotate(obj:TransformConstraintData.ToRotate):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ToRotate-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
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

    private function writeToScaleX(obj:TransformConstraintData.ToScaleX):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ToScaleX-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
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

    private function writeToScaleY(obj:TransformConstraintData.ToScaleY):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ToScaleY-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
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

    private function writeToShearY(obj:TransformConstraintData.ToShearY):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ToShearY-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
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

    private function writeToX(obj:TransformConstraintData.ToX):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ToX-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
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

    private function writeToY(obj:TransformConstraintData.ToY):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<ToY-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
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

    private function writeTransformConstraintPose(obj:TransformConstraintPose):Void {
        if (visitedObjects.exists(obj)) {
            json.writeValue(visitedObjects.get(obj));
            return;
        }
        var refString = "<TransformConstraintPose-" + (nextId++) + ">";
        visitedObjects.set(obj, refString);

        json.writeObjectStart();
        json.writeName("refString");
        json.writeValue(refString);
        json.writeName("type");
        json.writeValue("TransformConstraintPose");

        json.writeName("mixRotate");
        json.writeValue(obj.mixRotate);

        json.writeName("mixX");
        json.writeValue(obj.mixX);

        json.writeName("mixY");
        json.writeValue(obj.mixY);

        json.writeName("mixScaleX");
        json.writeValue(obj.mixScaleX);

        json.writeName("mixScaleY");
        json.writeValue(obj.mixScaleY);

        json.writeName("mixShearY");
        json.writeValue(obj.mixShearY);

        json.writeObjectEnd();
    }

    private function writeUpdate(obj:Update):Void {
        if (Std.isOfType(obj, BonePose)) {
            writeBonePose(cast(obj, BonePose));
        } else if (Std.isOfType(obj, IkConstraint)) {
            writeIkConstraint(cast(obj, IkConstraint));
        } else if (Std.isOfType(obj, PathConstraint)) {
            writePathConstraint(cast(obj, PathConstraint));
        } else if (Std.isOfType(obj, PhysicsConstraint)) {
            writePhysicsConstraint(cast(obj, PhysicsConstraint));
        } else if (Std.isOfType(obj, Slider)) {
            writeSlider(cast(obj, Slider));
        } else if (Std.isOfType(obj, TransformConstraint)) {
            writeTransformConstraint(cast(obj, TransformConstraint));
        } else {
            throw new spine.SpineException("Unknown Update type");
        }
    }

    private function writeVertexAttachment(obj:VertexAttachment):Void {
        if (Std.isOfType(obj, BoundingBoxAttachment)) {
            writeBoundingBoxAttachment(cast(obj, BoundingBoxAttachment));
        } else if (Std.isOfType(obj, ClippingAttachment)) {
            writeClippingAttachment(cast(obj, ClippingAttachment));
        } else if (Std.isOfType(obj, MeshAttachment)) {
            writeMeshAttachment(cast(obj, MeshAttachment));
        } else if (Std.isOfType(obj, PathAttachment)) {
            writePathAttachment(cast(obj, PathAttachment));
        } else {
            throw new spine.SpineException("Unknown VertexAttachment type");
        }
    }

    // Helper methods for special types
    private function writeColor(obj:spine.Color):Void {
        if (obj == null) {
            json.writeNull();
        } else {
            json.writeObjectStart();
            json.writeName("r");
            json.writeValue(obj.r);
            json.writeName("g");
            json.writeValue(obj.g);
            json.writeName("b");
            json.writeValue(obj.b);
            json.writeName("a");
            json.writeValue(obj.a);
            json.writeObjectEnd();
        }
    }

    private function writeTextureRegion(obj:Dynamic):Void {
        // TextureRegion serialization not implemented
        json.writeValue("<TextureRegion>");
    }

    private function writeFloatArray(arr:Array<Float>):Void {
        if (arr == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (val in arr) {
                json.writeValue(val);
            }
            json.writeArrayEnd();
        }
    }

    private function writeIntArray(arr:Array<Int>):Void {
        if (arr == null) {
            json.writeNull();
        } else {
            json.writeArrayStart();
            for (val in arr) {
                json.writeValue(val);
            }
            json.writeArrayEnd();
        }
    }

}