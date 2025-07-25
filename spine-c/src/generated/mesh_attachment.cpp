#include "mesh_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_mesh_attachment spine_mesh_attachment_create(const char *name) {
	return (spine_mesh_attachment) new (__FILE__, __LINE__) MeshAttachment(String(name));
}

void spine_mesh_attachment_dispose(spine_mesh_attachment self) {
	delete (MeshAttachment *) self;
}

spine_rtti spine_mesh_attachment_get_rtti(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_rtti) &_self->getRTTI();
}

void spine_mesh_attachment_compute_world_vertices_1(spine_mesh_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count,
													float *worldVertices, size_t offset, size_t stride) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->computeWorldVertices(*((Skeleton *) skeleton), *((Slot *) slot), start, count, worldVertices, offset, stride);
}

void spine_mesh_attachment_compute_world_vertices_2(spine_mesh_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count,
													spine_array_float worldVertices, size_t offset, size_t stride) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->computeWorldVertices(*((Skeleton *) skeleton), *((Slot *) slot), start, count, *((Array<float> *) worldVertices), offset, stride);
}

void spine_mesh_attachment_update_region(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->updateRegion();
}

int spine_mesh_attachment_get_hull_length(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return _self->getHullLength();
}

void spine_mesh_attachment_set_hull_length(spine_mesh_attachment self, int inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setHullLength(inValue);
}

spine_array_float spine_mesh_attachment_get_region_u_vs(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_array_float) &_self->getRegionUVs();
}

void spine_mesh_attachment_set_region_u_vs(spine_mesh_attachment self, spine_array_float inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setRegionUVs(*((Array<float> *) inValue));
}

spine_array_float spine_mesh_attachment_get_u_vs(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_array_float) &_self->getUVs();
}

spine_array_unsigned_short spine_mesh_attachment_get_triangles(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_array_unsigned_short) &_self->getTriangles();
}

void spine_mesh_attachment_set_triangles(spine_mesh_attachment self, spine_array_unsigned_short inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setTriangles(*((Array<unsigned short> *) inValue));
}

spine_color spine_mesh_attachment_get_color(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_color) &_self->getColor();
}

const char *spine_mesh_attachment_get_path(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return _self->getPath().buffer();
}

void spine_mesh_attachment_set_path(spine_mesh_attachment self, const char *inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setPath(String(inValue));
}

spine_texture_region spine_mesh_attachment_get_region(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_texture_region) _self->getRegion();
}

void spine_mesh_attachment_set_region(spine_mesh_attachment self, spine_texture_region region) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setRegion(*((TextureRegion *) region));
}

spine_sequence spine_mesh_attachment_get_sequence(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_sequence) _self->getSequence();
}

void spine_mesh_attachment_set_sequence(spine_mesh_attachment self, spine_sequence sequence) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setSequence((Sequence *) sequence);
}

spine_mesh_attachment spine_mesh_attachment_get_parent_mesh(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_mesh_attachment) _self->getParentMesh();
}

void spine_mesh_attachment_set_parent_mesh(spine_mesh_attachment self, spine_mesh_attachment inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setParentMesh((MeshAttachment *) inValue);
}

spine_array_unsigned_short spine_mesh_attachment_get_edges(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_array_unsigned_short) &_self->getEdges();
}

void spine_mesh_attachment_set_edges(spine_mesh_attachment self, spine_array_unsigned_short inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setEdges(*((Array<unsigned short> *) inValue));
}

float spine_mesh_attachment_get_width(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return _self->getWidth();
}

void spine_mesh_attachment_set_width(spine_mesh_attachment self, float inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setWidth(inValue);
}

float spine_mesh_attachment_get_height(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return _self->getHeight();
}

void spine_mesh_attachment_set_height(spine_mesh_attachment self, float inValue) {
	MeshAttachment *_self = (MeshAttachment *) self;
	_self->setHeight(inValue);
}

spine_attachment spine_mesh_attachment_copy(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_attachment) &_self->copy();
}

spine_mesh_attachment spine_mesh_attachment_new_linked_mesh(spine_mesh_attachment self) {
	MeshAttachment *_self = (MeshAttachment *) self;
	return (spine_mesh_attachment) &_self->newLinkedMesh();
}

int spine_mesh_attachment_get_id(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	return _self->getId();
}

spine_array_int spine_mesh_attachment_get_bones(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	return (spine_array_int) &_self->getBones();
}

void spine_mesh_attachment_set_bones(spine_mesh_attachment self, spine_array_int bones) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->setBones(*((Array<int> *) bones));
}

spine_array_float spine_mesh_attachment_get_vertices(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	return (spine_array_float) &_self->getVertices();
}

void spine_mesh_attachment_set_vertices(spine_mesh_attachment self, spine_array_float vertices) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->setVertices(*((Array<float> *) vertices));
}

size_t spine_mesh_attachment_get_world_vertices_length(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	return _self->getWorldVerticesLength();
}

void spine_mesh_attachment_set_world_vertices_length(spine_mesh_attachment self, size_t inValue) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->setWorldVerticesLength(inValue);
}

spine_attachment spine_mesh_attachment_get_timeline_attachment(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	return (spine_attachment) _self->getTimelineAttachment();
}

void spine_mesh_attachment_set_timeline_attachment(spine_mesh_attachment self, spine_attachment attachment) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->setTimelineAttachment((Attachment *) attachment);
}

void spine_mesh_attachment_copy_to(spine_mesh_attachment self, spine_vertex_attachment other) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->copyTo(*((VertexAttachment *) other));
}

const char *spine_mesh_attachment_get_name(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	return _self->getName().buffer();
}

int spine_mesh_attachment_get_ref_count(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	return _self->getRefCount();
}

void spine_mesh_attachment_reference(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->reference();
}

void spine_mesh_attachment_dereference(spine_mesh_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (MeshAttachment *) self;
	_self->dereference();
}

spine_rtti spine_mesh_attachment_rtti(void) {
	return (spine_rtti) &MeshAttachment::rtti;
}
