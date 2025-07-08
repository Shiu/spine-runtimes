/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include "custom.h"
#include <spine/spine.h>
#include <spine/Version.h>
#include <spine/Debug.h>
#include <spine/SkeletonRenderer.h>
#include <spine/AnimationState.h>
#include <cstring>

using namespace spine;

// Internal structures
struct _spine_atlas {
    void *atlas;
    utf8 **imagePaths;
    int32_t numImagePaths;
    utf8 *error;
};

struct _spine_skeleton_data_result {
    spine_skeleton_data skeletonData;
    utf8 *error;
};

struct _spine_bounds {
    float x, y, width, height;
};

struct _spine_vector {
    float x, y;
};

struct _spine_skeleton_drawable : public SpineObject {
    spine_skeleton skeleton;
    spine_animation_state animationState;
    spine_animation_state_data animationStateData;
    spine_animation_state_events animationStateEvents;
    SkeletonRenderer *renderer;
};

struct _spine_skin_entry {
    int32_t slotIndex;
    utf8 *name;
    spine_attachment attachment;
};

struct _spine_skin_entries {
    int32_t numEntries;
    _spine_skin_entry *entries;
};

// Animation state event tracking
struct AnimationStateEvent {
    EventType type;
    TrackEntry *entry;
    Event *event;
    AnimationStateEvent(EventType type, TrackEntry *entry, Event *event) : type(type), entry(entry), event(event){};
};

class EventListener : public AnimationStateListenerObject, public SpineObject {
public:
    Vector<AnimationStateEvent> events;

    void callback(AnimationState *state, EventType type, TrackEntry *entry, Event *event) override {
        events.add(AnimationStateEvent(type, entry, event));
        SP_UNUSED(state);
    }
};

// Static variables
static Color NULL_COLOR(0, 0, 0, 0);
static SpineExtension *defaultExtension = nullptr;
static DebugExtension *debugExtension = nullptr;

static void initExtensions() {
    if (defaultExtension == nullptr) {
        defaultExtension = new DefaultSpineExtension();
        debugExtension = new DebugExtension(defaultExtension);
    }
}

namespace spine {
    SpineExtension *getDefaultExtension() {
        initExtensions();
        return defaultExtension;
    }
}

// Version functions
int32_t spine_major_version() {
    return SPINE_MAJOR_VERSION;
}

int32_t spine_minor_version() {
    return SPINE_MINOR_VERSION;
}

void spine_enable_debug_extension(spine_bool enable) {
    initExtensions();
    SpineExtension::setInstance(enable ? debugExtension : defaultExtension);
}

void spine_report_leaks() {
    initExtensions();
    debugExtension->reportLeaks();
    fflush(stdout);
}

// Color functions
float spine_color_get_r(spine_color color) {
    if (!color) return 0;
    return ((Color *) color)->r;
}

float spine_color_get_g(spine_color color) {
    if (!color) return 0;
    return ((Color *) color)->g;
}

float spine_color_get_b(spine_color color) {
    if (!color) return 0;
    return ((Color *) color)->b;
}

float spine_color_get_a(spine_color color) {
    if (!color) return 0;
    return ((Color *) color)->a;
}

// Bounds functions
float spine_bounds_get_x(spine_bounds bounds) {
    if (!bounds) return 0;
    return ((_spine_bounds *) bounds)->x;
}

float spine_bounds_get_y(spine_bounds bounds) {
    if (!bounds) return 0;
    return ((_spine_bounds *) bounds)->y;
}

float spine_bounds_get_width(spine_bounds bounds) {
    if (!bounds) return 0;
    return ((_spine_bounds *) bounds)->width;
}

float spine_bounds_get_height(spine_bounds bounds) {
    if (!bounds) return 0;
    return ((_spine_bounds *) bounds)->height;
}

// Vector functions
float spine_vector_get_x(spine_vector vector) {
    if (!vector) return 0;
    return ((_spine_vector *) vector)->x;
}

float spine_vector_get_y(spine_vector vector) {
    if (!vector) return 0;
    return ((_spine_vector *) vector)->y;
}

// Atlas functions
class LiteTextureLoad : public TextureLoader {
    void load(AtlasPage &page, const String &path) {
        page.texture = (void *) (intptr_t) page.index;
    }

    void unload(void *texture) {
    }
};
static LiteTextureLoad liteLoader;

spine_atlas spine_atlas_load(const utf8 *atlasData) {
    if (!atlasData) return nullptr;
    int32_t length = (int32_t) strlen(atlasData);
    auto atlas = new (__FILE__, __LINE__) Atlas(atlasData, length, "", &liteLoader, true);
    _spine_atlas *result = SpineExtension::calloc<_spine_atlas>(1, __FILE__, __LINE__);
    result->atlas = atlas;
    result->numImagePaths = (int32_t) atlas->getPages().size();
    result->imagePaths = SpineExtension::calloc<utf8 *>(result->numImagePaths, __FILE__, __LINE__);
    for (int i = 0; i < result->numImagePaths; i++) {
        result->imagePaths[i] = (utf8 *) strdup(atlas->getPages()[i]->texturePath.buffer());
    }
    return (spine_atlas) result;
}

class CallbackTextureLoad : public TextureLoader {
    spine_texture_loader_load_func loadCb;
    spine_texture_loader_unload_func unloadCb;

public:
    CallbackTextureLoad() : loadCb(nullptr), unloadCb(nullptr) {}

    void setCallbacks(spine_texture_loader_load_func load, spine_texture_loader_unload_func unload) {
        loadCb = load;
        unloadCb = unload;
    }

    void load(AtlasPage &page, const String &path) {
        page.texture = this->loadCb(path.buffer());
    }

    void unload(void *texture) {
        this->unloadCb(texture);
    }
};
static CallbackTextureLoad callbackLoader;

spine_atlas spine_atlas_load_callback(const utf8 *atlasData, const utf8 *atlasDir, 
                                     spine_texture_loader_load_func load, 
                                     spine_texture_loader_unload_func unload) {
    if (!atlasData) return nullptr;
    int32_t length = (int32_t) strlen(atlasData);
    callbackLoader.setCallbacks(load, unload);
    auto atlas = new (__FILE__, __LINE__) Atlas(atlasData, length, (const char *) atlasDir, &callbackLoader, true);
    _spine_atlas *result = SpineExtension::calloc<_spine_atlas>(1, __FILE__, __LINE__);
    result->atlas = atlas;
    result->numImagePaths = (int32_t) atlas->getPages().size();
    result->imagePaths = SpineExtension::calloc<utf8 *>(result->numImagePaths, __FILE__, __LINE__);
    for (int i = 0; i < result->numImagePaths; i++) {
        result->imagePaths[i] = (utf8 *) strdup(atlas->getPages()[i]->texturePath.buffer());
    }
    return (spine_atlas) result;
}

int32_t spine_atlas_get_num_image_paths(spine_atlas atlas) {
    if (!atlas) return 0;
    return ((_spine_atlas *) atlas)->numImagePaths;
}

utf8 *spine_atlas_get_image_path(spine_atlas atlas, int32_t index) {
    if (!atlas) return nullptr;
    _spine_atlas *_atlas = (_spine_atlas *) atlas;
    if (index < 0 || index >= _atlas->numImagePaths) return nullptr;
    return _atlas->imagePaths[index];
}

spine_bool spine_atlas_is_pma(spine_atlas atlas) {
    if (!atlas) return 0;
    Atlas *_atlas = (Atlas *) ((_spine_atlas *) atlas)->atlas;
    for (size_t i = 0; i < _atlas->getPages().size(); i++) {
        AtlasPage *page = _atlas->getPages()[i];
        if (page->pma) return -1;
    }
    return 0;
}

utf8 *spine_atlas_get_error(spine_atlas atlas) {
    if (!atlas) return nullptr;
    return ((_spine_atlas *) atlas)->error;
}

void spine_atlas_dispose(spine_atlas atlas) {
    if (!atlas) return;
    _spine_atlas *_atlas = (_spine_atlas *) atlas;
    if (_atlas->atlas) {
        delete (Atlas *) _atlas->atlas;
    }
    if (_atlas->imagePaths) {
        for (int i = 0; i < _atlas->numImagePaths; i++) {
            if (_atlas->imagePaths[i]) {
                SpineExtension::free(_atlas->imagePaths[i], __FILE__, __LINE__);
            }
        }
        SpineExtension::free(_atlas->imagePaths, __FILE__, __LINE__);
    }
    if (_atlas->error) {
        SpineExtension::free(_atlas->error, __FILE__, __LINE__);
    }
    SpineExtension::free(_atlas, __FILE__, __LINE__);
}

// Skeleton data loading
spine_skeleton_data_result spine_skeleton_data_load_json(spine_atlas atlas, const utf8 *skeletonData) {
    if (!atlas || !skeletonData) return nullptr;
    _spine_skeleton_data_result *result = SpineExtension::calloc<_spine_skeleton_data_result>(1, __FILE__, __LINE__);
    SkeletonJson json((Atlas *) ((_spine_atlas *) atlas)->atlas);
    json.setScale(1);
    
    SkeletonData *data = json.readSkeletonData(skeletonData);
    if (!data) {
        result->error = (utf8 *) strdup("Failed to load skeleton data");
        return (spine_skeleton_data_result) result;
    }
    
    result->skeletonData = (spine_skeleton_data) data;
    return (spine_skeleton_data_result) result;
}

spine_skeleton_data_result spine_skeleton_data_load_binary(spine_atlas atlas, const uint8_t *skeletonData, int32_t length) {
    if (!atlas || !skeletonData) return nullptr;
    _spine_skeleton_data_result *result = SpineExtension::calloc<_spine_skeleton_data_result>(1, __FILE__, __LINE__);
    SkeletonBinary binary((Atlas *) ((_spine_atlas *) atlas)->atlas);
    binary.setScale(1);
    
    SkeletonData *data = binary.readSkeletonData((const unsigned char *) skeletonData, length);
    if (!data) {
        result->error = (utf8 *) strdup("Failed to load skeleton data");
        return (spine_skeleton_data_result) result;
    }
    
    result->skeletonData = (spine_skeleton_data) data;
    return (spine_skeleton_data_result) result;
}

utf8 *spine_skeleton_data_result_get_error(spine_skeleton_data_result result) {
    if (!result) return nullptr;
    return ((_spine_skeleton_data_result *) result)->error;
}

spine_skeleton_data spine_skeleton_data_result_get_data(spine_skeleton_data_result result) {
    if (!result) return nullptr;
    return ((_spine_skeleton_data_result *) result)->skeletonData;
}

void spine_skeleton_data_result_dispose(spine_skeleton_data_result result) {
    if (!result) return;
    _spine_skeleton_data_result *_result = (_spine_skeleton_data_result *) result;
    if (_result->error) {
        SpineExtension::free(_result->error, __FILE__, __LINE__);
    }
    SpineExtension::free(_result, __FILE__, __LINE__);
}

// Skeleton drawable
spine_skeleton_drawable spine_skeleton_drawable_create(spine_skeleton_data skeletonData) {
    if (!skeletonData) return nullptr;
    _spine_skeleton_drawable *drawable = new (__FILE__, __LINE__) _spine_skeleton_drawable();
    
    Skeleton *skeleton = new (__FILE__, __LINE__) Skeleton(*((SkeletonData *) skeletonData));
    AnimationStateData *stateData = new (__FILE__, __LINE__) AnimationStateData((SkeletonData *) skeletonData);
    AnimationState *state = new (__FILE__, __LINE__) AnimationState(stateData);
    EventListener *listener = new (__FILE__, __LINE__) EventListener();
    state->setListener(listener);
    
    drawable->skeleton = (spine_skeleton) skeleton;
    drawable->animationStateData = (spine_animation_state_data) stateData;
    drawable->animationState = (spine_animation_state) state;
    drawable->animationStateEvents = (spine_animation_state_events) listener;
    drawable->renderer = new (__FILE__, __LINE__) SkeletonRenderer();
    
    return (spine_skeleton_drawable) drawable;
}

spine_render_command spine_skeleton_drawable_render(spine_skeleton_drawable drawable) {
    if (!drawable) return nullptr;
    _spine_skeleton_drawable *_drawable = (_spine_skeleton_drawable *) drawable;
    Skeleton *skeleton = (Skeleton *) _drawable->skeleton;
    SkeletonRenderer *renderer = _drawable->renderer;
    
    RenderCommand *commands = renderer->render(*skeleton);
    return (spine_render_command) commands;
}

void spine_skeleton_drawable_dispose(spine_skeleton_drawable drawable) {
    if (!drawable) return;
    _spine_skeleton_drawable *_drawable = (_spine_skeleton_drawable *) drawable;
    
    if (_drawable->renderer) {
        delete _drawable->renderer;
    }
    if (_drawable->animationState) {
        delete (AnimationState *) _drawable->animationState;
    }
    if (_drawable->animationStateData) {
        delete (AnimationStateData *) _drawable->animationStateData;
    }
    if (_drawable->skeleton) {
        delete (Skeleton *) _drawable->skeleton;
    }
    if (_drawable->animationStateEvents) {
        delete (EventListener *) _drawable->animationStateEvents;
    }
    
    delete _drawable;
}

spine_skeleton spine_skeleton_drawable_get_skeleton(spine_skeleton_drawable drawable) {
    if (!drawable) return nullptr;
    return ((_spine_skeleton_drawable *) drawable)->skeleton;
}

spine_animation_state spine_skeleton_drawable_get_animation_state(spine_skeleton_drawable drawable) {
    if (!drawable) return nullptr;
    return ((_spine_skeleton_drawable *) drawable)->animationState;
}

spine_animation_state_data spine_skeleton_drawable_get_animation_state_data(spine_skeleton_drawable drawable) {
    if (!drawable) return nullptr;
    return ((_spine_skeleton_drawable *) drawable)->animationStateData;
}

spine_animation_state_events spine_skeleton_drawable_get_animation_state_events(spine_skeleton_drawable drawable) {
    if (!drawable) return nullptr;
    return ((_spine_skeleton_drawable *) drawable)->animationStateEvents;
}

// Render command functions
float *spine_render_command_get_positions(spine_render_command command) {
    if (!command) return nullptr;
    return ((RenderCommand *) command)->positions;
}

float *spine_render_command_get_uvs(spine_render_command command) {
    if (!command) return nullptr;
    return ((RenderCommand *) command)->uvs;
}

int32_t *spine_render_command_get_colors(spine_render_command command) {
    if (!command) return nullptr;
    return (int32_t *) ((RenderCommand *) command)->colors;
}

int32_t *spine_render_command_get_dark_colors(spine_render_command command) {
    if (!command) return nullptr;
    return (int32_t *) ((RenderCommand *) command)->darkColors;
}

int32_t spine_render_command_get_num_vertices(spine_render_command command) {
    if (!command) return 0;
    return ((RenderCommand *) command)->numVertices;
}

uint16_t *spine_render_command_get_indices(spine_render_command command) {
    if (!command) return nullptr;
    return ((RenderCommand *) command)->indices;
}

int32_t spine_render_command_get_num_indices(spine_render_command command) {
    if (!command) return 0;
    return ((RenderCommand *) command)->numIndices;
}

int32_t spine_render_command_get_atlas_page(spine_render_command command) {
    if (!command) return 0;
    return (int32_t) (intptr_t) ((RenderCommand *) command)->texture;
}

spine_blend_mode spine_render_command_get_blend_mode(spine_render_command command) {
    if (!command) return SPINE_BLEND_MODE_NORMAL;
    BlendMode mode = ((RenderCommand *) command)->blendMode;
    switch (mode) {
        case BlendMode_Normal: return SPINE_BLEND_MODE_NORMAL;
        case BlendMode_Additive: return SPINE_BLEND_MODE_ADDITIVE;
        case BlendMode_Multiply: return SPINE_BLEND_MODE_MULTIPLY;
        case BlendMode_Screen: return SPINE_BLEND_MODE_SCREEN;
        default: return SPINE_BLEND_MODE_NORMAL;
    }
}

spine_render_command spine_render_command_get_next(spine_render_command command) {
    if (!command) return nullptr;
    return (spine_render_command) ((RenderCommand *) command)->next;
}

// Skin entries
spine_skin_entries spine_skin_entries_create() {
    _spine_skin_entries *entries = SpineExtension::calloc<_spine_skin_entries>(1, __FILE__, __LINE__);
    return (spine_skin_entries) entries;
}

void spine_skin_entries_dispose(spine_skin_entries entries) {
    if (!entries) return;
    _spine_skin_entries *_entries = (_spine_skin_entries *) entries;
    if (_entries->entries) {
        for (int i = 0; i < _entries->numEntries; i++) {
            if (_entries->entries[i].name) {
                SpineExtension::free(_entries->entries[i].name, __FILE__, __LINE__);
            }
        }
        SpineExtension::free(_entries->entries, __FILE__, __LINE__);
    }
    SpineExtension::free(_entries, __FILE__, __LINE__);
}

int32_t spine_skin_entries_get_num_entries(spine_skin_entries entries) {
    if (!entries) return 0;
    return ((_spine_skin_entries *) entries)->numEntries;
}

spine_skin_entry spine_skin_entries_get_entry(spine_skin_entries entries, int32_t index) {
    if (!entries) return nullptr;
    _spine_skin_entries *_entries = (_spine_skin_entries *) entries;
    if (index < 0 || index >= _entries->numEntries) return nullptr;
    return (spine_skin_entry) &_entries->entries[index];
}

int32_t spine_skin_entry_get_slot_index(spine_skin_entry entry) {
    if (!entry) return 0;
    return ((_spine_skin_entry *) entry)->slotIndex;
}

const utf8 *spine_skin_entry_get_name(spine_skin_entry entry) {
    if (!entry) return nullptr;
    return ((_spine_skin_entry *) entry)->name;
}

spine_attachment spine_skin_entry_get_attachment(spine_skin_entry entry) {
    if (!entry) return nullptr;
    return ((_spine_skin_entry *) entry)->attachment;
}