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

#ifndef Spine_Posed_h
#define Spine_Posed_h

#include <spine/SpineObject.h>

namespace spine {
	template<class D, class P, class A>
	class SP_API Posed : public SpineObject {
	public:
		Posed(D& data, P& pose, A& constrained);
		virtual ~Posed();

		void setupPose();

		/// The constraint's setup pose data.
		D& getData();

		P& getPose();

		A& getAppliedPose();

	protected:
		D& _data;
		P& _pose;
		A& _constrained;
		A* _applied;
	};

	template<class D, class P, class A>
	Posed<D, P, A>::Posed(D& data, P& pose, A& constrained) : _data(data), _pose(pose), _constrained(constrained) {
		_applied = &pose;
	}

	template<class D, class P, class A>
	Posed<D, P, A>::~Posed() {
	}

	template<class D, class P, class A>
	void Posed<D, P, A>::setupPose() {
		_pose.set(_data.setup);
	}

	template<class D, class P, class A>
	D& Posed<D, P, A>::getData() {
		return _data;
	}

	template<class D, class P, class A>
	P& Posed<D, P, A>::getPose() {
		return _pose;
	}

	template<class D, class P, class A>
	A& Posed<D, P, A>::getAppliedPose() {
		return *_applied;
	}
}

#endif /* Spine_Posed_h */