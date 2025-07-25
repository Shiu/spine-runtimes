#include "path_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_path_attachment spine_path_attachment_create(const char *name) {
	return (spine_path_attachment) new (__FILE__, __LINE__) PathAttachment(String(name));
}

void spine_path_attachment_dispose(spine_path_attachment self) {
	delete (PathAttachment *) self;
}

spine_rtti spine_path_attachment_get_rtti(spine_path_attachment self) {
	PathAttachment *_self = (PathAttachment *) self;
	return (spine_rtti) &_self->getRTTI();
}

spine_array_float spine_path_attachment_get_lengths(spine_path_attachment self) {
	PathAttachment *_self = (PathAttachment *) self;
	return (spine_array_float) &_self->getLengths();
}

void spine_path_attachment_set_lengths(spine_path_attachment self, spine_array_float inValue) {
	PathAttachment *_self = (PathAttachment *) self;
	_self->setLengths(*((Array<float> *) inValue));
}

bool spine_path_attachment_get_closed(spine_path_attachment self) {
	PathAttachment *_self = (PathAttachment *) self;
	return _self->getClosed();
}

void spine_path_attachment_set_closed(spine_path_attachment self, bool inValue) {
	PathAttachment *_self = (PathAttachment *) self;
	_self->setClosed(inValue);
}

bool spine_path_attachment_get_constant_speed(spine_path_attachment self) {
	PathAttachment *_self = (PathAttachment *) self;
	return _self->getConstantSpeed();
}

void spine_path_attachment_set_constant_speed(spine_path_attachment self, bool inValue) {
	PathAttachment *_self = (PathAttachment *) self;
	_self->setConstantSpeed(inValue);
}

spine_color spine_path_attachment_get_color(spine_path_attachment self) {
	PathAttachment *_self = (PathAttachment *) self;
	return (spine_color) &_self->getColor();
}

spine_attachment spine_path_attachment_copy(spine_path_attachment self) {
	PathAttachment *_self = (PathAttachment *) self;
	return (spine_attachment) &_self->copy();
}

void spine_path_attachment_compute_world_vertices_1(spine_path_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count,
													float *worldVertices, size_t offset, size_t stride) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->computeWorldVertices(*((Skeleton *) skeleton), *((Slot *) slot), start, count, worldVertices, offset, stride);
}

void spine_path_attachment_compute_world_vertices_2(spine_path_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count,
													spine_array_float worldVertices, size_t offset, size_t stride) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->computeWorldVertices(*((Skeleton *) skeleton), *((Slot *) slot), start, count, *((Array<float> *) worldVertices), offset, stride);
}

int spine_path_attachment_get_id(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	return _self->getId();
}

spine_array_int spine_path_attachment_get_bones(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	return (spine_array_int) &_self->getBones();
}

void spine_path_attachment_set_bones(spine_path_attachment self, spine_array_int bones) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->setBones(*((Array<int> *) bones));
}

spine_array_float spine_path_attachment_get_vertices(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	return (spine_array_float) &_self->getVertices();
}

void spine_path_attachment_set_vertices(spine_path_attachment self, spine_array_float vertices) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->setVertices(*((Array<float> *) vertices));
}

size_t spine_path_attachment_get_world_vertices_length(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	return _self->getWorldVerticesLength();
}

void spine_path_attachment_set_world_vertices_length(spine_path_attachment self, size_t inValue) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->setWorldVerticesLength(inValue);
}

spine_attachment spine_path_attachment_get_timeline_attachment(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	return (spine_attachment) _self->getTimelineAttachment();
}

void spine_path_attachment_set_timeline_attachment(spine_path_attachment self, spine_attachment attachment) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->setTimelineAttachment((Attachment *) attachment);
}

void spine_path_attachment_copy_to(spine_path_attachment self, spine_vertex_attachment other) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->copyTo(*((VertexAttachment *) other));
}

const char *spine_path_attachment_get_name(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	return _self->getName().buffer();
}

int spine_path_attachment_get_ref_count(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	return _self->getRefCount();
}

void spine_path_attachment_reference(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->reference();
}

void spine_path_attachment_dereference(spine_path_attachment self) {
	VertexAttachment *_self = (VertexAttachment *) (PathAttachment *) self;
	_self->dereference();
}

spine_rtti spine_path_attachment_rtti(void) {
	return (spine_rtti) &PathAttachment::rtti;
}
