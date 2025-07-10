#include "clipping_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_clipping_attachment spine_clipping_attachment_create(const char* name) {
    return (spine_clipping_attachment) new (__FILE__, __LINE__) ClippingAttachment(*((const String*)name));
}

void spine_clipping_attachment_dispose(spine_clipping_attachment self) {
    delete (ClippingAttachment*)self;
}

spine_rtti spine_clipping_attachment_get_rtti(spine_clipping_attachment self) {
    return (spine_rtti)&((ClippingAttachment*)self)->getRTTI();
}

spine_slot_data spine_clipping_attachment_get_end_slot(spine_clipping_attachment self) {
    return (spine_slot_data)((ClippingAttachment*)self)->getEndSlot();
}

void spine_clipping_attachment_set_end_slot(spine_clipping_attachment self, spine_slot_data inValue) {
    ((ClippingAttachment*)self)->setEndSlot((SlotData *)inValue);
}

spine_color spine_clipping_attachment_get_color(spine_clipping_attachment self) {
    return (spine_color)&((ClippingAttachment*)self)->getColor();
}

spine_attachment spine_clipping_attachment_copy(spine_clipping_attachment self) {
    return (spine_attachment)((ClippingAttachment*)self)->copy();
}

void spine_clipping_attachment_compute_world_vertices_1(spine_clipping_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride) {
    ((VertexAttachment*)(ClippingAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, worldVertices, offset, stride);
}

void spine_clipping_attachment_compute_world_vertices_2(spine_clipping_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride) {
    ((VertexAttachment*)(ClippingAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, *((Array<float>*)worldVertices), offset, stride);
}

int spine_clipping_attachment_get_id(spine_clipping_attachment self) {
    return ((VertexAttachment*)(ClippingAttachment*)self)->getId();
}

spine_array_int spine_clipping_attachment_get_bones(spine_clipping_attachment self) {
    return (spine_array_int)&((VertexAttachment*)(ClippingAttachment*)self)->getBones();
}

void spine_clipping_attachment_set_bones(spine_clipping_attachment self, spine_array_int bones) {
    ((VertexAttachment*)(ClippingAttachment*)self)->setBones(*((Array<int>*)bones));
}

spine_array_float spine_clipping_attachment_get_vertices(spine_clipping_attachment self) {
    return (spine_array_float)&((VertexAttachment*)(ClippingAttachment*)self)->getVertices();
}

void spine_clipping_attachment_set_vertices(spine_clipping_attachment self, spine_array_float vertices) {
    ((VertexAttachment*)(ClippingAttachment*)self)->setVertices(*((Array<float>*)vertices));
}

size_t spine_clipping_attachment_get_world_vertices_length(spine_clipping_attachment self) {
    return ((VertexAttachment*)(ClippingAttachment*)self)->getWorldVerticesLength();
}

void spine_clipping_attachment_set_world_vertices_length(spine_clipping_attachment self, size_t inValue) {
    ((VertexAttachment*)(ClippingAttachment*)self)->setWorldVerticesLength(inValue);
}

spine_attachment spine_clipping_attachment_get_timeline_attachment(spine_clipping_attachment self) {
    return (spine_attachment)((VertexAttachment*)(ClippingAttachment*)self)->getTimelineAttachment();
}

void spine_clipping_attachment_set_timeline_attachment(spine_clipping_attachment self, spine_attachment attachment) {
    ((VertexAttachment*)(ClippingAttachment*)self)->setTimelineAttachment((Attachment *)attachment);
}

void spine_clipping_attachment_copy_to(spine_clipping_attachment self, spine_vertex_attachment other) {
    ((VertexAttachment*)(ClippingAttachment*)self)->copyTo((VertexAttachment *)other);
}

const char* spine_clipping_attachment_get_name(spine_clipping_attachment self) {
    return (const char*)&((VertexAttachment*)(ClippingAttachment*)self)->getName();
}

int spine_clipping_attachment_get_ref_count(spine_clipping_attachment self) {
    return ((VertexAttachment*)(ClippingAttachment*)self)->getRefCount();
}

void spine_clipping_attachment_reference(spine_clipping_attachment self) {
    ((VertexAttachment*)(ClippingAttachment*)self)->reference();
}

void spine_clipping_attachment_dereference(spine_clipping_attachment self) {
    ((VertexAttachment*)(ClippingAttachment*)self)->dereference();
}

spine_rtti spine_clipping_attachment_rtti(void) {
    return (spine_rtti)&ClippingAttachment::rtti;
}
