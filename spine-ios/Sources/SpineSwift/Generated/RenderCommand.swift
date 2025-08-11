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

@objc(SpineRenderCommand)
@objcMembers
public final class RenderCommand: NSObject {
    internal let wrappee: spine_render_command

    internal init(_ wrappee: spine_render_command) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? RenderCommand else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public func getPositions() -> UnsafeMutablePointer<Float>? {
        return spine_render_command_get_positions(wrappee)
    }

    public func getUvs() -> UnsafeMutablePointer<Float>? {
        return spine_render_command_get_uvs(wrappee)
    }

    public func getColors() -> OpaquePointer? {
        return spine_render_command_get_colors(wrappee)
    }

    public func getDarkColors() -> OpaquePointer? {
        return spine_render_command_get_dark_colors(wrappee)
    }

    public func getNumVertices() -> Int32 {
        return spine_render_command_get_num_vertices(wrappee)
    }

    public func getIndices() -> OpaquePointer? {
        return spine_render_command_get_indices(wrappee)
    }

    public func getNumIndices() -> Int32 {
        return spine_render_command_get_num_indices(wrappee)
    }

    public func getBlendMode() -> BlendMode {
        return spine_render_command_get_blend_mode(wrappee)
    }

    public func getTexture() -> OpaquePointer? {
        return spine_render_command_get_texture(wrappee)
    }

    public func getNext() -> RenderCommand {
        let result = spine_render_command_get_next(wrappee)
        return RenderCommand(result)
    }

    deinit {
        spine_render_command_dispose(wrappee)
    }
}