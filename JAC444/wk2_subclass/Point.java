/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * Point class info:
 * 
 * default constructor
 * 2 parameter constructor
 * getX() method
 * getY() method
 * toString() method
 * equals() method
 * hashCode() method
 * 
 */

package jac444.wk2;

public class Point {
	protected double _x;
	protected double _y;
	
	//default constructor
	public Point() {
		_x=0.0;
		_y=0.0;
	}
	
	/*
	 * 2 parameter constructor
	 * @param x double: contains x coordinate value of Point
	 * @param y double: contains y coordinate value of Point
	 */
	public Point(double x, double y) {
		_x=x;
		_y=y;
	}
	
	//return x value
	public double getX() {
		return _x;
	}
	
	//return y value
	public double getY() {
		return _y;
	}
	
	//return label String object	
	public String toString() {
		return "x: "+ getX() +"\ny: "+getY()+"\n";
	}
	
	/*
	 * @param o Point object: a Point object to compare
	 * return true if this Point object and parameter are same
	 */	
	public boolean equals(Point o) {
		if(getX()==o.getX()&&getY()==o.getY()) return true;
		else return false;
	}
	
	//return unique hash code
	public int hashCode() {
		int ret = 0;
		ret += getX();
		System.out.println(getX());
		int mult = 10;
		while((int)getX()/mult!=0) {
			mult *=10;
		}
		ret += getY()*mult;
		return ret;
	}
	
}
