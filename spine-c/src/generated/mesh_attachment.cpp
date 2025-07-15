#include "mesh_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_mesh_attachment spine_mesh_attachment_create(const char * name) {
    return (spine_mesh_attachment) new (__FILE__, __LINE__) MeshAttachment(String(name));
}

void spine_mesh_attachment_dispose(spine_mesh_attachment self) {
    delete (MeshAttachment*)self;
}

spine_rtti spine_mesh_attachment_get_rtti(spine_mesh_attachment self) {
    return (spine_rtti)&((MeshAttachment*)self)->getRTTI();
}

void spine_mesh_attachment_compute_world_vertices_1(spine_mesh_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride) {
    ((MeshAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, worldVertices, offset, stride);
}

void spine_mesh_attachment_compute_world_vertices_2(spine_mesh_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride) {
    ((VertexAttachment*)(MeshAttachment*)self)->computeWorldVertices(*((Skeleton*)skeleton), *((Slot*)slot), start, count, *((Array<float>*)worldVertices), offset, stride);
}

void spine_mesh_attachment_update_region(spine_mesh_attachment self) {
    ((MeshAttachment*)self)->updateRegion();
}

int spine_mesh_attachment_get_hull_length(spine_mesh_attachment self) {
    return ((MeshAttachment*)self)->getHullLength();
}

void spine_mesh_attachment_set_hull_length(spine_mesh_attachment self, int inValue) {
    ((MeshAttachment*)self)->setHullLength(inValue);
}

spine_array_float spine_mesh_attachment_get_region_u_vs(spine_mesh_attachment self) {
    return (spine_array_float)&((MeshAttachment*)self)->getRegionUVs();
}

void spine_mesh_attachment_set_region_u_vs(spine_mesh_attachment self, spine_array_float inValue) {
    ((MeshAttachment*)self)->setRegionUVs(*((Array<float>*)inValue));
}

spine_array_float spine_mesh_attachment_get_u_vs(spine_mesh_attachment self) {
    return (spine_array_float)&((MeshAttachment*)self)->getUVs();
}

spine_array_unsigned_short spine_mesh_attachment_get_triangles(spine_mesh_attachment self) {
    return (spine_array_unsigned_short)&((MeshAttachment*)self)->getTriangles();
}

void spine_mesh_attachment_set_triangles(spine_mesh_attachment self, spine_array_unsigned_short inValue) {
    ((MeshAttachment*)self)->setTriangles(*((Array<unsigned short>*)inValue));
}

spine_color spine_mesh_attachment_get_color(spine_mesh_attachment self) {
    return (spine_color)&((MeshAttachment*)self)->getColor();
}

const char * spine_mesh_attachment_get_path(spine_mesh_attachment self) {
    return ((MeshAttachment*)self)->getPath().buffer();
}

void spine_mesh_attachment_set_path(spine_mesh_attachment self, const char * inValue) {
    ((MeshAttachment*)self)->setPath(String(inValue));
}

spine_texture_region spine_mesh_attachment_get_region(spine_mesh_attachment self) {
    return (spine_texture_region)((MeshAttachment*)self)->getRegion();
}

void spine_mesh_attachment_set_region(spine_mesh_attachment self, spine_texture_region region) {
    ((MeshAttachment*)self)->setRegion((TextureRegion *)region);
}

spine_sequence spine_mesh_attachment_get_sequence(spine_mesh_attachment self) {
    return (spine_sequence)((MeshAttachment*)self)->getSequence();
}

void spine_mesh_attachment_set_sequence(spine_mesh_attachment self, spine_sequence sequence) {
    ((MeshAttachment*)self)->setSequence((Sequence *)sequence);
}

spine_mesh_attachment spine_mesh_attachment_get_parent_mesh(spine_mesh_attachment self) {
    return (spine_mesh_attachment)((MeshAttachment*)self)->getParentMesh();
}

void spine_mesh_attachment_set_parent_mesh(spine_mesh_attachment self, spine_mesh_attachment inValue) {
    ((MeshAttachment*)self)->setParentMesh((MeshAttachment *)inValue);
}

spine_array_unsigned_short spine_mesh_attachment_get_edges(spine_mesh_attachment self) {
    return (spine_array_unsigned_short)&((MeshAttachment*)self)->getEdges();
}

void spine_mesh_attachment_set_edges(spine_mesh_attachment self, spine_array_unsigned_short inValue) {
    ((MeshAttachment*)self)->setEdges(*((Array<unsigned short>*)inValue));
}

float spine_mesh_attachment_get_width(spine_mesh_attachment self) {
    return ((MeshAttachment*)self)->getWidth();
}

void spine_mesh_attachment_set_width(spine_mesh_attachment self, float inValue) {
    ((MeshAttachment*)self)->setWidth(inValue);
}

float spine_mesh_attachment_get_height(spine_mesh_attachment self) {
    return ((MeshAttachment*)self)->getHeight();
}

void spine_mesh_attachment_set_height(spine_mesh_attachment self, float inValue) {
    ((MeshAttachment*)self)->setHeight(inValue);
}

spine_attachment spine_mesh_attachment_copy(spine_mesh_attachment self) {
    return (spine_attachment)((MeshAttachment*)self)->copy();
}

spine_mesh_attachment spine_mesh_attachment_new_linked_mesh(spine_mesh_attachment self) {
    return (spine_mesh_attachment)((MeshAttachment*)self)->newLinkedMesh();
}

int spine_mesh_attachment_get_id(spine_mesh_attachment self) {
    return ((VertexAttachment*)(MeshAttachment*)self)->getId();
}

spine_array_int spine_mesh_attachment_get_bones(spine_mesh_attachment self) {
    return (spine_array_int)&((VertexAttachment*)(MeshAttachment*)self)->getBones();
}

void spine_mesh_attachment_set_bones(spine_mesh_attachment self, spine_array_int bones) {
    ((VertexAttachment*)(MeshAttachment*)self)->setBones(*((Array<int>*)bones));
}

spine_array_float spine_mesh_attachment_get_vertices(spine_mesh_attachment self) {
    return (spine_array_float)&((VertexAttachment*)(MeshAttachment*)self)->getVertices();
}

void spine_mesh_attachment_set_vertices(spine_mesh_attachment self, spine_array_float vertices) {
    ((VertexAttachment*)(MeshAttachment*)self)->setVertices(*((Array<float>*)vertices));
}

size_t spine_mesh_attachment_get_world_vertices_length(spine_mesh_attachment self) {
    return ((VertexAttachment*)(MeshAttachment*)self)->getWorldVerticesLength();
}

void spine_mesh_attachment_set_world_vertices_length(spine_mesh_attachment self, size_t inValue) {
    ((VertexAttachment*)(MeshAttachment*)self)->setWorldVerticesLength(inValue);
}

spine_attachment spine_mesh_attachment_get_timeline_attachment(spine_mesh_attachment self) {
    return (spine_attachment)((VertexAttachment*)(MeshAttachment*)self)->getTimelineAttachment();
}

void spine_mesh_attachment_set_timeline_attachment(spine_mesh_attachment self, spine_attachment attachment) {
    ((VertexAttachment*)(MeshAttachment*)self)->setTimelineAttachment((Attachment *)attachment);
}

void spine_mesh_attachment_copy_to(spine_mesh_attachment self, spine_vertex_attachment other) {
    ((VertexAttachment*)(MeshAttachment*)self)->copyTo((VertexAttachment *)other);
}

const char * spine_mesh_attachment_get_name(spine_mesh_attachment self) {
    return ((VertexAttachment*)(MeshAttachment*)self)->getName().buffer();
}

int spine_mesh_attachment_get_ref_count(spine_mesh_attachment self) {
    return ((VertexAttachment*)(MeshAttachment*)self)->getRefCount();
}

void spine_mesh_attachment_reference(spine_mesh_attachment self) {
    ((VertexAttachment*)(MeshAttachment*)self)->reference();
}

void spine_mesh_attachment_dereference(spine_mesh_attachment self) {
    ((VertexAttachment*)(MeshAttachment*)self)->dereference();
}

spine_rtti spine_mesh_attachment_rtti(void) {
    return (spine_rtti)&MeshAttachment::rtti;
}
