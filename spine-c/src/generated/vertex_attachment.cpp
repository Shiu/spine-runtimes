#include "vertex_attachment.h"
#include <spine/spine.h>

using namespace spine;

void spine_vertex_attachment_dispose(spine_vertex_attachment self) {
    delete (VertexAttachment*)self;
}

spine_rtti spine_vertex_attachment_get_rtti(spine_vertex_attachment self) {
    return (spine_rtti)&((VertexAttachment*)self)->getRTTI();
}

void spine_vertex_attachment_compute_world_vertices_1(spine_vertex_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride) {
    ((VertexAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, worldVertices, offset, stride);
}

void spine_vertex_attachment_compute_world_vertices_2(spine_vertex_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride) {
    ((VertexAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, *((Array<float>*)worldVertices), offset, stride);
}

int spine_vertex_attachment_get_id(spine_vertex_attachment self) {
    return ((VertexAttachment*)self)->getId();
}

spine_array_int spine_vertex_attachment_get_bones(spine_vertex_attachment self) {
    return (spine_array_int)&((VertexAttachment*)self)->getBones();
}

void spine_vertex_attachment_set_bones(spine_vertex_attachment self, spine_array_int bones) {
    ((VertexAttachment*)self)->setBones(*((Array<int>*)bones));
}

spine_array_float spine_vertex_attachment_get_vertices(spine_vertex_attachment self) {
    return (spine_array_float)&((VertexAttachment*)self)->getVertices();
}

void spine_vertex_attachment_set_vertices(spine_vertex_attachment self, spine_array_float vertices) {
    ((VertexAttachment*)self)->setVertices(*((Array<float>*)vertices));
}

size_t spine_vertex_attachment_get_world_vertices_length(spine_vertex_attachment self) {
    return ((VertexAttachment*)self)->getWorldVerticesLength();
}

void spine_vertex_attachment_set_world_vertices_length(spine_vertex_attachment self, size_t inValue) {
    ((VertexAttachment*)self)->setWorldVerticesLength(inValue);
}

spine_attachment spine_vertex_attachment_get_timeline_attachment(spine_vertex_attachment self) {
    return (spine_attachment)((VertexAttachment*)self)->getTimelineAttachment();
}

void spine_vertex_attachment_set_timeline_attachment(spine_vertex_attachment self, spine_attachment attachment) {
    ((VertexAttachment*)self)->setTimelineAttachment((Attachment *)attachment);
}

void spine_vertex_attachment_copy_to(spine_vertex_attachment self, spine_vertex_attachment other) {
    ((VertexAttachment*)self)->copyTo((VertexAttachment *)other);
}

const char * spine_vertex_attachment_get_name(spine_vertex_attachment self) {
    return ((Attachment*)(VertexAttachment*)self)->getName().buffer();
}

spine_attachment spine_vertex_attachment_copy(spine_vertex_attachment self) {
    return (spine_attachment)((Attachment*)(VertexAttachment*)self)->copy();
}

int spine_vertex_attachment_get_ref_count(spine_vertex_attachment self) {
    return ((Attachment*)(VertexAttachment*)self)->getRefCount();
}

void spine_vertex_attachment_reference(spine_vertex_attachment self) {
    ((Attachment*)(VertexAttachment*)self)->reference();
}

void spine_vertex_attachment_dereference(spine_vertex_attachment self) {
    ((Attachment*)(VertexAttachment*)self)->dereference();
}

spine_rtti spine_vertex_attachment_rtti(void) {
    return (spine_rtti)&VertexAttachment::rtti;
}
