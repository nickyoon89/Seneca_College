/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * Country class info:
 * interface: Measurable
 * 
 * 2 parameter constructor
 * getArea() method
 * 
 */

package jac444.wk2;

public class Country implements Measurable{
	String _name;
	double _area;
	
	/*
	 * 2 parameter constructor
	 * @param name String: country name value
	 * @param area double: contains area size value
	 * 
	 */
	public Country(String name, double area) {
		_name=name;
		_area=area;
	}

	//return Area information as String	
	@Override
	public String getArea() {
		return "Area: "+_area +"sqare kilometers\n";
	}
}
