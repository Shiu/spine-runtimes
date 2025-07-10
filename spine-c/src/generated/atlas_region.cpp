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
    return (spine_atlas_page)((AtlasRegion*)self)->page;
}

void spine_atlas_region_set_page(spine_atlas_region self, spine_atlas_page value) {
    ((AtlasRegion*)self)->page = (AtlasPage*)value;
}

const char* spine_atlas_region_get_name(spine_atlas_region self) {
    return ((AtlasRegion*)self)->name.buffer();
}

void spine_atlas_region_set_name(spine_atlas_region self, const char* value) {
    ((AtlasRegion*)self)->name = String(value);
}

int spine_atlas_region_get_index(spine_atlas_region self) {
    return ((AtlasRegion*)self)->index;
}

void spine_atlas_region_set_index(spine_atlas_region self, int value) {
    ((AtlasRegion*)self)->index = value;
}

int spine_atlas_region_get_x(spine_atlas_region self) {
    return ((AtlasRegion*)self)->x;
}

void spine_atlas_region_set_x(spine_atlas_region self, int value) {
    ((AtlasRegion*)self)->x = value;
}

int spine_atlas_region_get_y(spine_atlas_region self) {
    return ((AtlasRegion*)self)->y;
}

void spine_atlas_region_set_y(spine_atlas_region self, int value) {
    ((AtlasRegion*)self)->y = value;
}

spine_array_int spine_atlas_region_get_splits(spine_atlas_region self) {
    return (spine_array_int)&((AtlasRegion*)self)->splits;
}

void spine_atlas_region_set_splits(spine_atlas_region self, spine_array_int value) {
    ((AtlasRegion*)self)->splits = *((Array<int>*)value);
}

spine_array_int spine_atlas_region_get_pads(spine_atlas_region self) {
    return (spine_array_int)&((AtlasRegion*)self)->pads;
}

void spine_atlas_region_set_pads(spine_atlas_region self, spine_array_int value) {
    ((AtlasRegion*)self)->pads = *((Array<int>*)value);
}

spine_array_float spine_atlas_region_get_values(spine_atlas_region self) {
    return (spine_array_float)&((AtlasRegion*)self)->values;
}

void spine_atlas_region_set_values(spine_atlas_region self, spine_array_float value) {
    ((AtlasRegion*)self)->values = *((Array<float>*)value);
}
