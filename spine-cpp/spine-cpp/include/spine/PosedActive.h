/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated January 1, 2020. Replaces all prior versions.
 *
 * Copyright (c) 2013-2020, Esoteric Software LLC
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

#ifndef SPINE_POSEDACTIVE_H_
#define SPINE_POSEDACTIVE_H_

#include <spine/dll.h>
#include <spine/Posed.h>

namespace spine {
	template<class D, class P, class A>
	class SP_API PosedActive : public Posed<D, P, A> {
	protected:
		bool _active;

	public:
		PosedActive(D& data);
		virtual ~PosedActive();

		/// Returns false when this constraint won't be updated by
		/// Skeleton::updateWorldTransform() because a skin is required and the
		/// active skin does not contain this item.
		/// @see Skin::getBones()
		/// @see Skin::getConstraints()
		/// @see PosedData::getSkinRequired()
		/// @see Skeleton::updateCache()
		bool isActive();
	};

	template<class D, class P, class A>
	PosedActive<D, P, A>::PosedActive(D& data) : Posed<D, P, A>(data), _active(false) {
		this->setupPose();
	}

	template<class D, class P, class A>
	PosedActive<D, P, A>::~PosedActive() {
	}

	template<class D, class P, class A>
	bool PosedActive<D, P, A>::isActive() {
		return _active;
	}
}

#endif /* SPINE_POSEDACTIVE_H_ */