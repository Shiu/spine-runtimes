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

import CoreGraphics
import Foundation

/// Base class for bounds providers. A bounds provider calculates the axis aligned bounding box
/// used to scale and fit a skeleton inside the bounds of a ``SpineUIView``.
@objc(SpineBoundsProvider)
public protocol BoundsProvider {
    func computeBounds(for drawable: SkeletonDrawableWrapper) -> CGRect
}

/// A ``BoundsProvider`` that calculates the bounding box of the skeleton based on the visible
/// attachments in the setup pose.
@objc(SpineSetupPoseBounds)
@objcMembers
public final class SetupPoseBounds: NSObject, BoundsProvider {

    public override init() {
        super.init()
    }

    public func computeBounds(for drawable: SkeletonDrawableWrapper) -> CGRect {
        return CGRect(bounds: drawable.skeleton.bounds)
    }
}

/// A ``BoundsProvider`` that returns fixed bounds.
@objc(SpineRawBounds)
@objcMembers
public final class RawBounds: NSObject, BoundsProvider {
    public let x: Double
    public let y: Double
    public let width: Double
    public let height: Double

    public init(x: Double, y: Double, width: Double, height: Double) {
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        super.init()
    }

    public func computeBounds(for drawable: SkeletonDrawableWrapper) -> CGRect {
        return CGRectMake(CGFloat(x), CGFloat(y), CGFloat(width), CGFloat(height))
    }
}

/// A ``BoundsProvider`` that calculates the bounding box needed for a combination of skins
/// and an animation.
@objc(SpineSkinAndAnimationBounds)
@objcMembers
public final class SkinAndAnimationBounds: NSObject, BoundsProvider {

    private let animation: String?
    private let skins: [String]
    private let stepTime: TimeInterval

    /// Constructs a new provider that will use the given `skins` and `animation` to calculate
    /// the bounding box of the skeleton. If no skins are given, the default skin is used.
    /// The `stepTime`, given in seconds, defines at what interval the bounds should be sampled
    /// across the entire animation.
    public init(animation: String? = nil, skins: [String]? = nil, stepTime: TimeInterval = 0.1) {
        self.animation = animation
        if let skins, !skins.isEmpty {
            self.skins = skins
        } else {
            self.skins = ["default"]
        }
        self.stepTime = stepTime
        super.init()
    }

    public func computeBounds(for drawable: SkeletonDrawableWrapper) -> CGRect {
        let data = drawable.skeletonData
        let oldSkin: Skin? = drawable.skeleton.skin
        let customSkin = Skin.create(name: "custom-skin")
        for skinName in skins {
            let skin = data.findSkin(name: skinName)
            if let skin = data.findSkin(name: skinName) {
                customSkin.addSkin(other: skin)
            }
        }
        drawable.skeleton.skin = customSkin
        drawable.skeleton.setToSetupPose()

        let animation = animation.flatMap { data.findAnimation(name: $0) }
        var minX = Float.Magnitude.greatestFiniteMagnitude
        var minY = Float.Magnitude.greatestFiniteMagnitude
        var maxX = -Float.Magnitude.greatestFiniteMagnitude
        var maxY = -Float.Magnitude.greatestFiniteMagnitude
        if let animation {
            drawable.animationState.setAnimation(trackIndex: 0, animation: animation, loop: false)
            let steps = Int(max(Double(animation.duration) / stepTime, 1.0))
            for i in 0..<steps {
                drawable.update(delta: i > 0 ? Float(stepTime) : 0.0)
                let bounds = drawable.skeleton.bounds
                minX = min(minX, bounds.x)
                minY = min(minY, bounds.y)
                maxX = max(maxX, minX + bounds.width)
                maxY = max(maxY, minY + bounds.height)
            }
        } else {
            let bounds = drawable.skeleton.bounds
            minX = bounds.x
            minY = bounds.y
            maxX = minX + bounds.width
            maxY = minY + bounds.height
        }
        drawable.skeleton.setSkinByName(skinName: "default")
        drawable.animationState.clearTracks()

        if let oldSkin {
            drawable.skeleton.skin = oldSkin
        }
        drawable.skeleton.setToSetupPose()
        drawable.update(delta: 0)
        customSkin.dispose()
        return CGRectMake(CGFloat(minX), CGFloat(minY), CGFloat(maxX - minX), CGFloat(maxY - minY))
    }
}

/// How a view should be inscribed into another view.
@objc
public enum ContentMode: Int {
    case fit
    /// As large as possible while still containing the source view entirely within the target view.
    case fill/// Fill the target view by distorting the source's aspect ratio.
}

/// How a view should aligned withing another view.
@objc
public enum Alignment: Int {
    case topLeft
    case topCenter
    case topRight
    case centerLeft
    case center
    case centerRight
    case bottomLeft
    case bottomCenter
    case bottomRight

    internal var x: CGFloat {
        switch self {
        case .topLeft, .centerLeft, .bottomLeft: return -1.0
        case .topCenter, .center, .bottomCenter: return 0.0
        case .topRight, .centerRight, .bottomRight: return 1.0
        }
    }

    internal var y: CGFloat {
        switch self {
        case .topLeft, .topCenter, .topRight: return -1.0
        case .centerLeft, .center, .centerRight: return 0.0
        case .bottomLeft, .bottomCenter, .bottomRight: return 1.0
        }
    }
}
