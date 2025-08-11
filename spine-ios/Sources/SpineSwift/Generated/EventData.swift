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

@objc(SpineEventData)
@objcMembers
public final class EventData: NSObject {
    internal let wrappee: spine_event_data

    internal init(_ wrappee: spine_event_data) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? EventData else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(name: String?) {
        let ptr = spine_event_data_create(name)
        self.init(ptr)
    }

    public func getName() -> String? {
        let result = spine_event_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getInt() -> Int32 {
        return spine_event_data_get_int(wrappee)
    }

    public func setInt(inValue: Int32) {
        spine_event_data_set_int(wrappee, inValue)
    }

    public func getFloat() -> Float {
        return spine_event_data_get_float(wrappee)
    }

    public func setFloat(inValue: Float) {
        spine_event_data_set_float(wrappee, inValue)
    }

    public func getString() -> String? {
        let result = spine_event_data_get_string(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setString(inValue: String?) {
        spine_event_data_set_string(wrappee, inValue?.cString(using: .utf8))
    }

    public func getAudioPath() -> String? {
        let result = spine_event_data_get_audio_path(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setAudioPath(inValue: String?) {
        spine_event_data_set_audio_path(wrappee, inValue?.cString(using: .utf8))
    }

    public func getVolume() -> Float {
        return spine_event_data_get_volume(wrappee)
    }

    public func setVolume(inValue: Float) {
        spine_event_data_set_volume(wrappee, inValue)
    }

    public func getBalance() -> Float {
        return spine_event_data_get_balance(wrappee)
    }

    public func setBalance(inValue: Float) {
        spine_event_data_set_balance(wrappee, inValue)
    }

    deinit {
        spine_event_data_dispose(wrappee)
    }
}