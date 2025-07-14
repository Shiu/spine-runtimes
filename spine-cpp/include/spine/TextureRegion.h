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

#ifndef Spine_TextureRegion_h
#define Spine_TextureRegion_h

#include <spine/Array.h>

namespace spine {
	class SP_API TextureRegion : public SpineObject {
		friend class MeshAttachment;
		friend class RegionAttachment;
		friend class Atlas;
		friend class AtlasRegion;
		friend class SkeletonRenderer;

	public:
		TextureRegion(): _rendererObject(NULL), _u(0), _v(0), _u2(0), _v2(0), _degrees(0), _offsetX(0), _offsetY(0), _width(0), _height(0), _originalWidth(0), _originalHeight(0) {};
		~TextureRegion() {};

		float getU() const { return _u; };
		void setU(float value) { _u = value; }
		float getV() const { return _v; }
		void setV(float value) { _v = value; }
		float getU2() const { return _u2; }
		void setU2(float value) { _u2 = value; }
		float getV2() const { return _v2; }
		void setV2(float value) { _v2 = value; }
		int getDegrees() const { return _degrees; }
		void setDegrees(int value) { _degrees = value; }
		float getOffsetX() const { return _offsetX; }
		void setOffsetX(float value) { _offsetX = value; }
		float getOffsetY() const { return _offsetY; }
		void setOffsetY(float value) { _offsetY = value; }
		int getRegionWidth() const { return _width; };
		void setRegionWidth(int value) { _width = value; }
		int getRegionHeight() const { return _height; }
		void setRegionHeight(int value) { _height = value; }
		int getOriginalWidth() const { return _originalWidth; };
		void setOriginalWidth(int value) { _originalWidth = value; }
		int getOriginalHeight() const { return _originalHeight; };
		void setOriginalHeight(int value) { _originalHeight = value; }

	private:
		void *_rendererObject;
		float _u, _v, _u2, _v2;
		int _degrees;
		float _offsetX, _offsetY;
		int _width, _height;
		int _originalWidth, _originalHeight;
	};
}

#endif
