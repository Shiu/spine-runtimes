#include "region_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_region_attachment spine_region_attachment_create(const char* name) {
    return (spine_region_attachment) new (__FILE__, __LINE__) RegionAttachment(String(name));
}

void spine_region_attachment_dispose(spine_region_attachment self) {
    delete (RegionAttachment*)self;
}

spine_rtti spine_region_attachment_get_rtti(spine_region_attachment self) {
    return (spine_rtti)&((RegionAttachment*)self)->getRTTI();
}

void spine_region_attachment_update_region(spine_region_attachment self) {
    ((RegionAttachment*)self)->updateRegion();
}

void spine_region_attachment_compute_world_vertices_1(spine_region_attachment self, spine_slot slot, float * worldVertices, size_t offset, size_t stride) {
    ((RegionAttachment*)self)->computeWorldVertices(*((Slot*)slot), worldVertices, offset, stride);
}

void spine_region_attachment_compute_world_vertices_2(spine_region_attachment self, spine_slot slot, spine_array_float worldVertices, size_t offset, size_t stride) {
    ((RegionAttachment*)self)->computeWorldVertices(*((Slot*)slot), *((Array<float>*)worldVertices), offset, stride);
}

float spine_region_attachment_get_x(spine_region_attachment self) {
    return ((RegionAttachment*)self)->getX();
}

void spine_region_attachment_set_x(spine_region_attachment self, float inValue) {
    ((RegionAttachment*)self)->setX(inValue);
}

float spine_region_attachment_get_y(spine_region_attachment self) {
    return ((RegionAttachment*)self)->getY();
}

void spine_region_attachment_set_y(spine_region_attachment self, float inValue) {
    ((RegionAttachment*)self)->setY(inValue);
}

float spine_region_attachment_get_rotation(spine_region_attachment self) {
    return ((RegionAttachment*)self)->getRotation();
}

void spine_region_attachment_set_rotation(spine_region_attachment self, float inValue) {
    ((RegionAttachment*)self)->setRotation(inValue);
}

float spine_region_attachment_get_scale_x(spine_region_attachment self) {
    return ((RegionAttachment*)self)->getScaleX();
}

void spine_region_attachment_set_scale_x(spine_region_attachment self, float inValue) {
    ((RegionAttachment*)self)->setScaleX(inValue);
}

float spine_region_attachment_get_scale_y(spine_region_attachment self) {
    return ((RegionAttachment*)self)->getScaleY();
}

void spine_region_attachment_set_scale_y(spine_region_attachment self, float inValue) {
    ((RegionAttachment*)self)->setScaleY(inValue);
}

float spine_region_attachment_get_width(spine_region_attachment self) {
    return ((RegionAttachment*)self)->getWidth();
}

void spine_region_attachment_set_width(spine_region_attachment self, float inValue) {
    ((RegionAttachment*)self)->setWidth(inValue);
}

float spine_region_attachment_get_height(spine_region_attachment self) {
    return ((RegionAttachment*)self)->getHeight();
}

void spine_region_attachment_set_height(spine_region_attachment self, float inValue) {
    ((RegionAttachment*)self)->setHeight(inValue);
}

spine_color spine_region_attachment_get_color(spine_region_attachment self) {
    return (spine_color)&((RegionAttachment*)self)->getColor();
}

const char* spine_region_attachment_get_path(spine_region_attachment self) {
    return (const char*)&((RegionAttachment*)self)->getPath();
}

void spine_region_attachment_set_path(spine_region_attachment self, const char* inValue) {
    ((RegionAttachment*)self)->setPath(String(inValue));
}

spine_texture_region spine_region_attachment_get_region(spine_region_attachment self) {
    return (spine_texture_region)((RegionAttachment*)self)->getRegion();
}

void spine_region_attachment_set_region(spine_region_attachment self, spine_texture_region region) {
    ((RegionAttachment*)self)->setRegion((TextureRegion *)region);
}

spine_sequence spine_region_attachment_get_sequence(spine_region_attachment self) {
    return (spine_sequence)((RegionAttachment*)self)->getSequence();
}

void spine_region_attachment_set_sequence(spine_region_attachment self, spine_sequence sequence) {
    ((RegionAttachment*)self)->setSequence((Sequence *)sequence);
}

spine_array_float spine_region_attachment_get_offset(spine_region_attachment self) {
    return (spine_array_float)&((RegionAttachment*)self)->getOffset();
}

spine_array_float spine_region_attachment_get_u_vs(spine_region_attachment self) {
    return (spine_array_float)&((RegionAttachment*)self)->getUVs();
}

spine_attachment spine_region_attachment_copy(spine_region_attachment self) {
    return (spine_attachment)((RegionAttachment*)self)->copy();
}

const char* spine_region_attachment_get_name(spine_region_attachment self) {
    return (const char*)&((Attachment*)(RegionAttachment*)self)->getName();
}

int spine_region_attachment_get_ref_count(spine_region_attachment self) {
    return ((Attachment*)(RegionAttachment*)self)->getRefCount();
}

void spine_region_attachment_reference(spine_region_attachment self) {
    ((Attachment*)(RegionAttachment*)self)->reference();
}

void spine_region_attachment_dereference(spine_region_attachment self) {
    ((Attachment*)(RegionAttachment*)self)->dereference();
}

spine_rtti spine_region_attachment_rtti(void) {
    return (spine_rtti)&RegionAttachment::rtti;
}
