
package com.esotericsoftware.spine;

abstract public class Posed<D extends PosedData<P>, P extends Pose, A extends P> {
	final D data;
	final P pose;
	final A constrained;
	A applied;

	public Posed (D data, P pose, A constrained) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		this.data = data;
		this.pose = pose;
		this.constrained = constrained;
		applied = (A)pose;
		setupPose();
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

	public A getConstrainedPose () {
		return constrained;
	}

	public void setConstrained (boolean constrained) {
		applied = constrained ? this.constrained : (A)pose;
	}

	public void resetAppliedPose () {
		applied.set(pose);
	}

	public String toString () {
		return data.name;
	}
}
