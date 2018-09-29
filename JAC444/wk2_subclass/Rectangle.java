/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * Rectangle class info:
 * super: Shape
 * interface: Measurable
 * 
 * 3 parameter constructor
 * getCentre() method
 * getArea() method
 * 
 */

package jac444.wk2;

public class Rectangle extends Shape implements Measurable {
	
	double _width;
	double _height;
	
	/*
	 * 3 parameter constructor
	 * @param topLeft Point object: contains top left Point's x, y coordinates value
	 * @param width double: contains rectangle's width
	 * @param height double: contains rectangle's height
	 */
	public Rectangle(Point topLeft, double width, double height) {
		super.p=topLeft;
		_width=width;
		_height=height;
	}
	
	//return center Point object
	@Override
	Point getCentre() {
		Point centre = new Point(this.p.getX()+_width/2.0, this.p.getY()-_height/2.0);
		return centre;
	}
	

	//return Area information as String
	@Override
	public String getArea() {
		double area = _width*_height;
		return "Area: "+area+" units squared\n";
	}

}
