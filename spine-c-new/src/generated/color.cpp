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

#include "color.h"
#include <spine/spine.h>

using namespace spine;

spine_color spine_color_create(void) {
    Color *obj = new (__FILE__, __LINE__) Color();
    return (spine_color) obj;
}

spine_color spine_color_create_with_float_float_float_float(float r, float g, float b, float a) {
    Color *obj = new (__FILE__, __LINE__) Color(r, g, b, a);
    return (spine_color) obj;
}

void spine_color_dispose(spine_color obj) {
    if (!obj) return;
    delete (Color *) obj;
}

spine_color spine_color_set(spine_color obj, float _r, float _g, float _b, float _a) {
    if (!obj) return nullptr;
    Color *_obj = (Color *) obj;
    return (spine_color) &_obj->set(_r, _g, _b, _a);
}

spine_color spine_color_set(spine_color obj, float _r, float _g, float _b) {
    if (!obj) return nullptr;
    Color *_obj = (Color *) obj;
    return (spine_color) &_obj->set(_r, _g, _b);
}

void spine_color_set(spine_color obj, spine_color value) {
    if (!obj) return;
    Color *_obj = (Color *) obj;
    _obj->set(value);
}

spine_color spine_color_add(spine_color obj, float _r, float _g, float _b, float _a) {
    if (!obj) return nullptr;
    Color *_obj = (Color *) obj;
    return (spine_color) &_obj->add(_r, _g, _b, _a);
}

spine_color spine_color_add(spine_color obj, float _r, float _g, float _b) {
    if (!obj) return nullptr;
    Color *_obj = (Color *) obj;
    return (spine_color) &_obj->add(_r, _g, _b);
}

spine_color spine_color_add(spine_color obj, spine_color other) {
    if (!obj) return nullptr;
    Color *_obj = (Color *) obj;
    return (spine_color) &_obj->add(other);
}

spine_color spine_color_clamp(spine_color obj) {
    if (!obj) return nullptr;
    Color *_obj = (Color *) obj;
    return (spine_color) &_obj->clamp();
}
