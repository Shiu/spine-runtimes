
package com.esotericsoftware.spine;

abstract public class PosedActive<D extends PosedData<P>, P extends Pose, A extends P> extends Posed<D, P, A> {
	boolean active;

	public PosedActive (D data, P pose, A constrained) {
		super(data, pose, constrained);
	}

	/** Returns false when this constraint won't be updated by
	 * {@link Skeleton#updateWorldTransform(com.esotericsoftware.spine.Physics)} because a skin is required and the
	 * {@link Skeleton#getSkin() active skin} does not contain this item.
	 * @see Skin#getBones()
	 * @see Skin#getConstraints()
	 * @see PosedData#getSkinRequired()
	 * @see Skeleton#updateCache() */
	public boolean isActive () {
		return active;
	}
}
