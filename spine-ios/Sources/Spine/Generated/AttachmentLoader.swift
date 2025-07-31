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

@objc(SpineAttachmentLoader)
@objcMembers
public final class AttachmentLoader {
    internal let wrappee: spine_attachment_loader

    internal init(_ wrappee: spine_attachment_loader) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? AttachmentLoader else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public func newRegionAttachment(skin: Skin, name: String?, path: String?, sequence: Sequence) -> RegionAttachment {
        let result = spine_attachment_loader_new_region_attachment(wrappee, skin.wrappee, name?.cString(using: .utf8), path?.cString(using: .utf8), sequence.wrappee)
        return RegionAttachment(result)
    }

    public func newMeshAttachment(skin: Skin, name: String?, path: String?, sequence: Sequence) -> MeshAttachment {
        let result = spine_attachment_loader_new_mesh_attachment(wrappee, skin.wrappee, name?.cString(using: .utf8), path?.cString(using: .utf8), sequence.wrappee)
        return MeshAttachment(result)
    }

    public func newBoundingBoxAttachment(skin: Skin, name: String?) -> BoundingBoxAttachment {
        let result = spine_attachment_loader_new_bounding_box_attachment(wrappee, skin.wrappee, name?.cString(using: .utf8))
        return BoundingBoxAttachment(result)
    }

    public func newPathAttachment(skin: Skin, name: String?) -> PathAttachment {
        let result = spine_attachment_loader_new_path_attachment(wrappee, skin.wrappee, name?.cString(using: .utf8))
        return PathAttachment(result)
    }

    public func newPointAttachment(skin: Skin, name: String?) -> PointAttachment {
        let result = spine_attachment_loader_new_point_attachment(wrappee, skin.wrappee, name?.cString(using: .utf8))
        return PointAttachment(result)
    }

    public func newClippingAttachment(skin: Skin, name: String?) -> ClippingAttachment {
        let result = spine_attachment_loader_new_clipping_attachment(wrappee, skin.wrappee, name?.cString(using: .utf8))
        return ClippingAttachment(result)
    }

    deinit {
        spine_attachment_loader_dispose(wrappee)
    }
}