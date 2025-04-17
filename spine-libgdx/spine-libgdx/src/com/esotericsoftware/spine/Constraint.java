
package com.esotericsoftware.spine;

abstract public class Constraint<D extends PosedData<P>, P extends Pose> extends PosedActive<D, P, P> implements Update {
	public Constraint (D data, P pose, P constrained) {
		super(data, pose, constrained);
	}

	abstract public void sort ();
}
