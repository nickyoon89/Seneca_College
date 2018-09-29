/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * LabeledPoint class info:
 * super: Point
 * 
 * 3 parameter constructor
 * getLabel() method
 * toString() method
 * equals() method
 * hashCode() method
 * 
 */

package jac444.wk2;

public class LabeledPoint extends Point {
	String _label;
	
	/*
	 * 3 parameter constructor
	 * @param label String object: contains Point's label
	 * @param x double: contains Point's x coordinate
	 * @param y double: contains Point's y coordinate
	 */
	public LabeledPoint(String label, double x, double y) {
		super(x,y);
		_label=label;
	}
	
	//return label String object
	public String getLabel() {
		return _label;
	}
	
	//return LabeledPoint information as String object
	public String toString() {
		return "Label: "+getLabel()+"\n" + super.toString();
	}
	
	/*
	 * @param o LabeledPoint object: a LabeledPoint object to compare
	 * return true if this LabeledPoint object and parameter are same
	 */
	public boolean equals(LabeledPoint o) {
		if(super.equals(o)&&getLabel()==o.getLabel()) return true;
		else return false;
	}
	
	// return unique hash code
	public int hashCode() {
		int ret = super.hashCode();
		ret *= _label.hashCode();
		return ret;
	}
}
