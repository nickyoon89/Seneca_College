/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * WeatherQueueEmpty class info:
 * 
 * default constructor
 * 1 parameter constructor
 */

package jac444.wk3;

import java.io.IOException;

public class WeatherQueueEmpty extends IOException{
	private static final long serialVersionUID = 2L;
	
	//default constructor
	public WeatherQueueEmpty() {
		super("The Queue is Empty");
	}
	
	/*
	 * 1 parameter constructor
	 * @param String msg : the custom error message
	 */
	public WeatherQueueEmpty(String msg){
		super(msg);
	}
}
