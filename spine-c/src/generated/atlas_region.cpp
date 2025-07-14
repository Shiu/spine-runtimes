#include "atlas_region.h"
#include <spine/spine.h>

using namespace spine;

spine_atlas_region spine_atlas_region_create(void) {
    return (spine_atlas_region) new (__FILE__, __LINE__) AtlasRegion();
}

void spine_atlas_region_dispose(spine_atlas_region self) {
    delete (AtlasRegion*)self;
}

spine_atlas_page spine_atlas_region_get_page(spine_atlas_region self) {
    return (spine_atlas_page)((AtlasRegion*)self)->getPage();
}

int spine_atlas_region_get_index(spine_atlas_region self) {
    return ((AtlasRegion*)self)->getIndex();
}

int spine_atlas_region_get_x(spine_atlas_region self) {
    return ((AtlasRegion*)self)->getX();
}

int spine_atlas_region_get_y(spine_atlas_region self) {
    return ((AtlasRegion*)self)->getY();
}

spine_array_int spine_atlas_region_get_splits(spine_atlas_region self) {
    return (spine_array_int)&((AtlasRegion*)self)->getSplits();
}

spine_array_int spine_atlas_region_get_pads(spine_atlas_region self) {
    return (spine_array_int)&((AtlasRegion*)self)->getPads();
}

spine_array_float spine_atlas_region_get_values(spine_atlas_region self) {
    return (spine_array_float)&((AtlasRegion*)self)->getValues();
}

void spine_atlas_region_set_page(spine_atlas_region self, spine_atlas_page value) {
    ((AtlasRegion*)self)->setPage((AtlasPage *)value);
}

void spine_atlas_region_set_name(spine_atlas_region self, const char* value) {
    ((AtlasRegion*)self)->setName(String(value));
}

void spine_atlas_region_set_index(spine_atlas_region self, int value) {
    ((AtlasRegion*)self)->setIndex(value);
}

void spine_atlas_region_set_x(spine_atlas_region self, int value) {
    ((AtlasRegion*)self)->setX(value);
}

void spine_atlas_region_set_y(spine_atlas_region self, int value) {
    ((AtlasRegion*)self)->setY(value);
}

void spine_atlas_region_set_splits(spine_atlas_region self, spine_array_int value) {
    ((AtlasRegion*)self)->setSplits(*((const Array<int>*)value));
}

void spine_atlas_region_set_pads(spine_atlas_region self, spine_array_int value) {
    ((AtlasRegion*)self)->setPads(*((const Array<int>*)value));
}

void spine_atlas_region_set_values(spine_atlas_region self, spine_array_float value) {
    ((AtlasRegion*)self)->setValues(*((const Array<float>*)value));
}

float spine_atlas_region_get_u(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getU();
}

void spine_atlas_region_set_u(spine_atlas_region self, float value) {
    ((TextureRegion*)(AtlasRegion*)self)->setU(value);
}

float spine_atlas_region_get_v(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getV();
}

void spine_atlas_region_set_v(spine_atlas_region self, float value) {
    ((TextureRegion*)(AtlasRegion*)self)->setV(value);
}

float spine_atlas_region_get_u2(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getU2();
}

void spine_atlas_region_set_u2(spine_atlas_region self, float value) {
    ((TextureRegion*)(AtlasRegion*)self)->setU2(value);
}

float spine_atlas_region_get_v2(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getV2();
}

void spine_atlas_region_set_v2(spine_atlas_region self, float value) {
    ((TextureRegion*)(AtlasRegion*)self)->setV2(value);
}

int spine_atlas_region_get_degrees(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getDegrees();
}

void spine_atlas_region_set_degrees(spine_atlas_region self, int value) {
    ((TextureRegion*)(AtlasRegion*)self)->setDegrees(value);
}

float spine_atlas_region_get_offset_x(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getOffsetX();
}

void spine_atlas_region_set_offset_x(spine_atlas_region self, float value) {
    ((TextureRegion*)(AtlasRegion*)self)->setOffsetX(value);
}

float spine_atlas_region_get_offset_y(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getOffsetY();
}

void spine_atlas_region_set_offset_y(spine_atlas_region self, float value) {
    ((TextureRegion*)(AtlasRegion*)self)->setOffsetY(value);
}

int spine_atlas_region_get_region_width(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getRegionWidth();
}

void spine_atlas_region_set_region_width(spine_atlas_region self, int value) {
    ((TextureRegion*)(AtlasRegion*)self)->setRegionWidth(value);
}

int spine_atlas_region_get_region_height(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getRegionHeight();
}

void spine_atlas_region_set_region_height(spine_atlas_region self, int value) {
    ((TextureRegion*)(AtlasRegion*)self)->setRegionHeight(value);
}

int spine_atlas_region_get_original_width(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getOriginalWidth();
}

void spine_atlas_region_set_original_width(spine_atlas_region self, int value) {
    ((TextureRegion*)(AtlasRegion*)self)->setOriginalWidth(value);
}

int spine_atlas_region_get_original_height(spine_atlas_region self) {
    return ((TextureRegion*)(AtlasRegion*)self)->getOriginalHeight();
}

void spine_atlas_region_set_original_height(spine_atlas_region self, int value) {
    ((TextureRegion*)(AtlasRegion*)self)->setOriginalHeight(value);
}
