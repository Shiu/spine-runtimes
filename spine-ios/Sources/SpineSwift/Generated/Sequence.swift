// Spine Runtimes License Agreement
// Last updated April 5, 2025. Replaces all prior versions.
// 
// Copyright (c) 2013-2025, Esoteric Software LLC
// 
// Integration of the Spine Runtimes into software or otherwise creating
// derivative works of the Spine Runtimes is permitted under the terms and
// conditions of Section 2 of the Spine Editor License Agreement:
// http://esotericsoftware.com/spine-editor-license
// 
// Otherwise, it is permitted to integrate the Spine Runtimes into software
// or otherwise create derivative works of the Spine Runtimes (collectively,
// "Products"), provided that each user of the Products must obtain their own
// Spine Editor license and redistribution of the Products in any form must
// include this license and copyright notice.
// 
// THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
// BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 

import Foundation
import SpineC

@objc(SpineSequence)
@objcMembers
public final class Sequence: NSObject {
    internal let wrappee: spine_sequence

    internal init(_ wrappee: spine_sequence) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? Sequence else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(count: Int32) {
        let ptr = spine_sequence_create(count)
        self.init(ptr)
    }

    public func copy() -> Sequence {
        let result = spine_sequence_copy(wrappee)
        return Sequence(result)
    }

    public func apply(slot: SlotPose, attachment: Attachment) {
        spine_sequence_apply(wrappee, slot.wrappee, attachment.wrappee)
    }

    public func getPath(basePath: String?, index: Int32) -> String? {
        let result = spine_sequence_get_path(wrappee, basePath?.cString(using: .utf8), index)
        return result != nil ? String(cString: result!) : nil
    }

    public func getId() -> Int32 {
        return spine_sequence_get_id(wrappee)
    }

    public func setId(id: Int32) {
        spine_sequence_set_id(wrappee, id)
    }

    public func getStart() -> Int32 {
        return spine_sequence_get_start(wrappee)
    }

    public func setStart(start: Int32) {
        spine_sequence_set_start(wrappee, start)
    }

    public func getDigits() -> Int32 {
        return spine_sequence_get_digits(wrappee)
    }

    public func setDigits(digits: Int32) {
        spine_sequence_set_digits(wrappee, digits)
    }

    public func getSetupIndex() -> Int32 {
        return spine_sequence_get_setup_index(wrappee)
    }

    public func setSetupIndex(setupIndex: Int32) {
        spine_sequence_set_setup_index(wrappee, setupIndex)
    }

    public func getRegions() -> ArrayTextureRegion {
        return spine_sequence_get_regions(wrappee)
    }

    deinit {
        spine_sequence_dispose(wrappee)
    }
}