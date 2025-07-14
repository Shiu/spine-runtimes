#include "texture_region.h"
#include <spine/spine.h>

using namespace spine;

spine_texture_region spine_texture_region_create(void) {
    return (spine_texture_region) new (__FILE__, __LINE__) TextureRegion();
}

void spine_texture_region_dispose(spine_texture_region self) {
    delete (TextureRegion*)self;
}

float spine_texture_region_get_u(spine_texture_region self) {
    return ((TextureRegion*)self)->getU();
}

void spine_texture_region_set_u(spine_texture_region self, float value) {
    ((TextureRegion*)self)->setU(value);
}

float spine_texture_region_get_v(spine_texture_region self) {
    return ((TextureRegion*)self)->getV();
}

void spine_texture_region_set_v(spine_texture_region self, float value) {
    ((TextureRegion*)self)->setV(value);
}

float spine_texture_region_get_u2(spine_texture_region self) {
    return ((TextureRegion*)self)->getU2();
}

void spine_texture_region_set_u2(spine_texture_region self, float value) {
    ((TextureRegion*)self)->setU2(value);
}

float spine_texture_region_get_v2(spine_texture_region self) {
    return ((TextureRegion*)self)->getV2();
}

void spine_texture_region_set_v2(spine_texture_region self, float value) {
    ((TextureRegion*)self)->setV2(value);
}

int spine_texture_region_get_degrees(spine_texture_region self) {
    return ((TextureRegion*)self)->getDegrees();
}

void spine_texture_region_set_degrees(spine_texture_region self, int value) {
    ((TextureRegion*)self)->setDegrees(value);
}

float spine_texture_region_get_offset_x(spine_texture_region self) {
    return ((TextureRegion*)self)->getOffsetX();
}

void spine_texture_region_set_offset_x(spine_texture_region self, float value) {
    ((TextureRegion*)self)->setOffsetX(value);
}

float spine_texture_region_get_offset_y(spine_texture_region self) {
    return ((TextureRegion*)self)->getOffsetY();
}

void spine_texture_region_set_offset_y(spine_texture_region self, float value) {
    ((TextureRegion*)self)->setOffsetY(value);
}

int spine_texture_region_get_region_width(spine_texture_region self) {
    return ((TextureRegion*)self)->getRegionWidth();
}

void spine_texture_region_set_region_width(spine_texture_region self, int value) {
    ((TextureRegion*)self)->setRegionWidth(value);
}

int spine_texture_region_get_region_height(spine_texture_region self) {
    return ((TextureRegion*)self)->getRegionHeight();
}

void spine_texture_region_set_region_height(spine_texture_region self, int value) {
    ((TextureRegion*)self)->setRegionHeight(value);
}

int spine_texture_region_get_original_width(spine_texture_region self) {
    return ((TextureRegion*)self)->getOriginalWidth();
}

void spine_texture_region_set_original_width(spine_texture_region self, int value) {
    ((TextureRegion*)self)->setOriginalWidth(value);
}

int spine_texture_region_get_original_height(spine_texture_region self) {
    return ((TextureRegion*)self)->getOriginalHeight();
}

void spine_texture_region_set_original_height(spine_texture_region self, int value) {
    ((TextureRegion*)self)->setOriginalHeight(value);
}
