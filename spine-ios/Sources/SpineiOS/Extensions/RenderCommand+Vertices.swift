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

import Foundation
import SpineShadersStructs
import SpineSwift
import simd

extension RenderCommand {
    func getVertices() -> [SpineVertex] {
        var vertices = [SpineVertex]()

        let numVerts = Int(numVertices)
        let numInds = Int(numIndices)
        guard let indicesPtr = indices,
            let positionsPtr = positions,
            let uvsPtr = uvs,
            let colorsPtr = colors
        else {
            return vertices
        }
        let indicesArray = Array(UnsafeBufferPointer(start: indicesPtr, count: numInds))
        let positionsArray = Array(UnsafeBufferPointer(start: positionsPtr, count: numVerts * 2))
        let uvsArray = Array(UnsafeBufferPointer(start: uvsPtr, count: numVerts * 2))
        let colorsArray = Array(UnsafeBufferPointer(start: colorsPtr, count: numVerts))
        vertices.reserveCapacity(numInds)
        for i in 0..<numInds {
            let index = Int(indicesArray[i])
            let xIndex = 2 * index
            let yIndex = xIndex + 1
            let position = SIMD2<Float>(positionsArray[xIndex], positionsArray[yIndex])
            let uv = SIMD2<Float>(uvsArray[xIndex], uvsArray[yIndex])
            let color = extractRGBA(from: colorsArray[index])
            let vertex = SpineVertex(
                position: position,
                color: color,
                uv: uv
            )
            vertices.append(vertex)
        }

        return vertices
    }

    private func extractRGBA(from color: UInt32) -> SIMD4<Float> {
        let alpha = Float((color >> 24) & 0xFF) / 255.0
        let red = Float((color >> 16) & 0xFF) / 255.0
        let green = Float((color >> 8) & 0xFF) / 255.0
        let blue = Float(color & 0xFF) / 255.0
        return SIMD4<Float>(red, green, blue, alpha)
    }
}
