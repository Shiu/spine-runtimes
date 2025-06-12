
package com.esotericsoftware.spine;

abstract public class Posed< //
	D extends PosedData<P>, //
	P extends Pose, //
	A extends P> {

	final D data;
	final A pose;
	final A constrained;
	A applied;

	public Posed (D data, A pose, A constrained) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		this.data = data;
		this.pose = pose;
		this.constrained = constrained;
		applied = pose;
	}

	public void setupPose () {
		pose.set(data.setup);
	}

	/** The constraint's setup pose data. */
	public D getData () {
		return data;
	}

	public P getPose () {
		return pose;
	}

	public A getAppliedPose () {
		return applied;
	}

	void pose () {
		applied = pose;
	}

	void constrained () {
		applied = constrained;
	}

	void reset () {
		constrained.set(pose);
	}

	public String toString () {
		return data.name;
	}
}
