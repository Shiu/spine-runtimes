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

@objc(SpineSkeletonJson)
@objcMembers
public final class SkeletonJson: NSObject {
    internal let wrappee: spine_skeleton_json

    internal init(_ wrappee: spine_skeleton_json) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? SkeletonJson else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(atlas: Atlas) {
        let ptr = spine_skeleton_json_create(atlas.wrappee)
        self.init(ptr)
    }

    public convenience init(attachmentLoader: AttachmentLoader, ownsLoader: Bool) {
        let ptr = spine_skeleton_json_create(attachmentLoader.wrappee, ownsLoader)
        self.init(ptr)
    }

    public func readSkeletonDataFile(path: String?) -> SkeletonData {
        let result = spine_skeleton_json_read_skeleton_data_file(wrappee, path?.cString(using: .utf8))
        return SkeletonData(result)
    }

    public func readSkeletonData(json: String?) -> SkeletonData {
        let result = spine_skeleton_json_read_skeleton_data(wrappee, json?.cString(using: .utf8))
        return SkeletonData(result)
    }

    public func setScale(scale: Float) {
        spine_skeleton_json_set_scale(wrappee, scale)
    }

    public func getError() -> String? {
        let result = spine_skeleton_json_get_error(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    deinit {
        spine_skeleton_json_dispose(wrappee)
    }
}