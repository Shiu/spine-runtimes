
package com.esotericsoftware.spine;

abstract public class ConstraintData< //
	T extends Constraint, //
	P extends Pose> //
	extends PosedData<P> {

	public ConstraintData (String name, P setup) {
		super(name, setup);
	}

	abstract public T create (Skeleton skeleton);
}
