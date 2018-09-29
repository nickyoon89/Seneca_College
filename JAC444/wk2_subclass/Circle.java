/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * Circle class info:
 * super: Shape
 * interface: Measurable
 * 
 * 2 parameter constructor
 * getCentre() method
 * getArea() method
 * 
 */

package jac444.wk2;

public class Circle extends Shape implements Measurable{
	
	//radius variable
	double _radius;
	
	/*
	 * 2 parameter constructor
	 * @param centre Point object: contains x, y coordinates of centre point
	 * @param radius double: contains radius value 
	 * 
	 */
	public Circle(Point centre, double radius) {
		super.p=centre;
		_radius=radius;
	}
	

	//return centre Point object	
	@Override
	Point getCentre() {
		return super.p;
	}

	//return Area information as String
	@Override
	public String getArea() {
		double area = Math.PI * Math.pow(_radius, 2);
		return "Area: "+area+" units squared\n";
	}

}
