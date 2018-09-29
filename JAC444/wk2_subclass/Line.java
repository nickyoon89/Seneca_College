/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * Line class info:
 * super: Shape
 * interface: Measurable
 * 
 * 2 parameter constructor
 * getCentre() method
 * getArea() method
 * 
 */

package jac444.wk2;

public class Line extends Shape implements Measurable {
	
	Point _to;
	
	/*
	 * 2 parameter constructor
	 * @param from Point object: contains x, y coordinates of from Point
	 * @param to Point object: contains x, y coordinates of to Point
	 */
	public Line(Point from, Point to) {
		super.p=from;
		_to=to;
	}
	
	//return centre Point object;
	@Override
	Point getCentre() {
		double x, y;
		x= (_to.getX()+super.p.getX())/2.0;
		y= (_to.getY()+super.p.getY())/2.0;
		return new Point(x,y);
	}
	
	//return String object that notice Area information is not available
	@Override
	public String getArea() {
		return "Area: Not Available\n";
	}
}
