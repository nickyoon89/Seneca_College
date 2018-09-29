/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * Shape class info:
 * 
 * default constructor
 * moveBy(double, double) method
 * getCentre() abstract method
 * 
 */

package jac444.wk2;

public abstract class Shape {
	protected Point p;
	
	//default constructor
	public Shape() {
		p=new Point();
	}
	
	/*
	 * moveBy method: move Point by given x, y value
	 * @param dx double: horizontal move amount value
	 * @param dy double: vertical move amount value
	 */
	public void moveBy(double dx, double dy) {
		p._x+=dx;
		p._y+=dy;
	}
	
	abstract Point getCentre();
}
