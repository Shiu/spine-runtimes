#include "texture_region.h"
#include <spine/spine.h>

using namespace spine;

spine_texture_region spine_texture_region_create(void) {
    return (spine_texture_region) new (__FILE__, __LINE__) TextureRegion();
}

void spine_texture_region_dispose(spine_texture_region self) {
    delete (TextureRegion*)self;
}

void * spine_texture_region_get_renderer_object(spine_texture_region self) {
    return ((TextureRegion*)self)->rendererObject;
}

void spine_texture_region_set_renderer_object(spine_texture_region self, void * value) {
    ((TextureRegion*)self)->rendererObject = (void*)value;
}

float spine_texture_region_get_u(spine_texture_region self) {
    return ((TextureRegion*)self)->u;
}

void spine_texture_region_set_u(spine_texture_region self, float value) {
    ((TextureRegion*)self)->u = value;
}

float spine_texture_region_get_v(spine_texture_region self) {
    return ((TextureRegion*)self)->v;
}

void spine_texture_region_set_v(spine_texture_region self, float value) {
    ((TextureRegion*)self)->v = value;
}

float spine_texture_region_get_u2(spine_texture_region self) {
    return ((TextureRegion*)self)->u2;
}

void spine_texture_region_set_u2(spine_texture_region self, float value) {
    ((TextureRegion*)self)->u2 = value;
}

float spine_texture_region_get_v2(spine_texture_region self) {
    return ((TextureRegion*)self)->v2;
}

void spine_texture_region_set_v2(spine_texture_region self, float value) {
    ((TextureRegion*)self)->v2 = value;
}

int spine_texture_region_get_degrees(spine_texture_region self) {
    return ((TextureRegion*)self)->degrees;
}

void spine_texture_region_set_degrees(spine_texture_region self, int value) {
    ((TextureRegion*)self)->degrees = value;
}

float spine_texture_region_get_offset_x(spine_texture_region self) {
    return ((TextureRegion*)self)->offsetX;
}

void spine_texture_region_set_offset_x(spine_texture_region self, float value) {
    ((TextureRegion*)self)->offsetX = value;
}

float spine_texture_region_get_offset_y(spine_texture_region self) {
    return ((TextureRegion*)self)->offsetY;
}

void spine_texture_region_set_offset_y(spine_texture_region self, float value) {
    ((TextureRegion*)self)->offsetY = value;
}

int spine_texture_region_get_width(spine_texture_region self) {
    return ((TextureRegion*)self)->width;
}

void spine_texture_region_set_width(spine_texture_region self, int value) {
    ((TextureRegion*)self)->width = value;
}

int spine_texture_region_get_height(spine_texture_region self) {
    return ((TextureRegion*)self)->height;
}

void spine_texture_region_set_height(spine_texture_region self, int value) {
    ((TextureRegion*)self)->height = value;
}

int spine_texture_region_get_original_width(spine_texture_region self) {
    return ((TextureRegion*)self)->originalWidth;
}

void spine_texture_region_set_original_width(spine_texture_region self, int value) {
    ((TextureRegion*)self)->originalWidth = value;
}

int spine_texture_region_get_original_height(spine_texture_region self) {
    return ((TextureRegion*)self)->originalHeight;
}

void spine_texture_region_set_original_height(spine_texture_region self, int value) {
    ((TextureRegion*)self)->originalHeight = value;
}
