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

#ifndef Spine_Sequence_h
#define Spine_Sequence_h

#include <spine/Array.h>
#include <spine/SpineString.h>
#include <spine/TextureRegion.h>
#include <spine/RTTI.h>

namespace spine {
	class SlotPose;
	class Attachment;

	class SkeletonBinary;
	class SkeletonJson;

	class SP_API Sequence : public SpineObject {
		friend class SkeletonBinary;
		friend class SkeletonJson;

	public:
		Sequence(int count);

		~Sequence();

		Sequence *copy();

		void apply(SlotPose *slot, Attachment *attachment);

		String &getPath(const String &basePath, int index);

		/// Returns a unique ID for this attachment.
		int getId() {
			return _id;
		}

		void setId(int id) {
			_id = id;
		}

		int getStart() {
			return _start;
		}

		void setStart(int start) {
			_start = start;
		}

		int getDigits() {
			return _digits;
		}

		void setDigits(int digits) {
			_digits = digits;
		}

		/// The index of the region to show for the setup pose.
		int getSetupIndex() {
			return _setupIndex;
		}

		void setSetupIndex(int setupIndex) {
			_setupIndex = setupIndex;
		}

		Array<TextureRegion *> &getRegions() {
			return _regions;
		}

	private:
		static int _nextID;
		int _id;
		Array<TextureRegion *> _regions;
		int _start;
		int _digits;
		int _setupIndex;
		String _tmpPath;

		static int nextID();
	};

	enum SequenceMode {
		SequenceMode_hold = 0,
		SequenceMode_once = 1,
		SequenceMode_loop = 2,
		SequenceMode_pingpong = 3,
		SequenceMode_onceReverse = 4,
		SequenceMode_loopReverse = 5,
		SequenceMode_pingpongReverse = 6
	};

	inline SequenceMode SequenceMode_valueOf(const String &value) {
		if (value == "hold") return SequenceMode_hold;
		if (value == "once") return SequenceMode_once;
		if (value == "loop") return SequenceMode_loop;
		if (value == "pingpong") return SequenceMode_pingpong;
		if (value == "onceReverse") return SequenceMode_onceReverse;
		if (value == "loopReverse") return SequenceMode_loopReverse;
		if (value == "pingpongReverse") return SequenceMode_pingpongReverse;
		return SequenceMode_hold;
	}
}

#endif
