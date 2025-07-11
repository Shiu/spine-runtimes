#include "bounding_box_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_bounding_box_attachment spine_bounding_box_attachment_create(const char* name) {
    return (spine_bounding_box_attachment) new (__FILE__, __LINE__) BoundingBoxAttachment(String(name));
}

void spine_bounding_box_attachment_dispose(spine_bounding_box_attachment self) {
    delete (BoundingBoxAttachment*)self;
}

spine_rtti spine_bounding_box_attachment_get_rtti(spine_bounding_box_attachment self) {
    return (spine_rtti)&((BoundingBoxAttachment*)self)->getRTTI();
}

spine_color spine_bounding_box_attachment_get_color(spine_bounding_box_attachment self) {
    return (spine_color)&((BoundingBoxAttachment*)self)->getColor();
}

spine_attachment spine_bounding_box_attachment_copy(spine_bounding_box_attachment self) {
    return (spine_attachment)((BoundingBoxAttachment*)self)->copy();
}

void spine_bounding_box_attachment_compute_world_vertices_1(spine_bounding_box_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, worldVertices, offset, stride);
}

void spine_bounding_box_attachment_compute_world_vertices_2(spine_bounding_box_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, *((Array<float>*)worldVertices), offset, stride);
}

int spine_bounding_box_attachment_get_id(spine_bounding_box_attachment self) {
    return ((VertexAttachment*)(BoundingBoxAttachment*)self)->getId();
}

spine_array_int spine_bounding_box_attachment_get_bones(spine_bounding_box_attachment self) {
    return (spine_array_int)&((VertexAttachment*)(BoundingBoxAttachment*)self)->getBones();
}

void spine_bounding_box_attachment_set_bones(spine_bounding_box_attachment self, spine_array_int bones) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->setBones(*((Array<int>*)bones));
}

spine_array_float spine_bounding_box_attachment_get_vertices(spine_bounding_box_attachment self) {
    return (spine_array_float)&((VertexAttachment*)(BoundingBoxAttachment*)self)->getVertices();
}

void spine_bounding_box_attachment_set_vertices(spine_bounding_box_attachment self, spine_array_float vertices) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->setVertices(*((Array<float>*)vertices));
}

size_t spine_bounding_box_attachment_get_world_vertices_length(spine_bounding_box_attachment self) {
    return ((VertexAttachment*)(BoundingBoxAttachment*)self)->getWorldVerticesLength();
}

void spine_bounding_box_attachment_set_world_vertices_length(spine_bounding_box_attachment self, size_t inValue) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->setWorldVerticesLength(inValue);
}

spine_attachment spine_bounding_box_attachment_get_timeline_attachment(spine_bounding_box_attachment self) {
    return (spine_attachment)((VertexAttachment*)(BoundingBoxAttachment*)self)->getTimelineAttachment();
}

void spine_bounding_box_attachment_set_timeline_attachment(spine_bounding_box_attachment self, spine_attachment attachment) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->setTimelineAttachment((Attachment *)attachment);
}

void spine_bounding_box_attachment_copy_to(spine_bounding_box_attachment self, spine_vertex_attachment other) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->copyTo((VertexAttachment *)other);
}

const char* spine_bounding_box_attachment_get_name(spine_bounding_box_attachment self) {
    return (const char*)&((VertexAttachment*)(BoundingBoxAttachment*)self)->getName();
}

int spine_bounding_box_attachment_get_ref_count(spine_bounding_box_attachment self) {
    return ((VertexAttachment*)(BoundingBoxAttachment*)self)->getRefCount();
}

void spine_bounding_box_attachment_reference(spine_bounding_box_attachment self) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->reference();
}

void spine_bounding_box_attachment_dereference(spine_bounding_box_attachment self) {
    ((VertexAttachment*)(BoundingBoxAttachment*)self)->dereference();
}

spine_rtti spine_bounding_box_attachment_rtti(void) {
    return (spine_rtti)&BoundingBoxAttachment::rtti;
}
