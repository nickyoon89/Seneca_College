/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * WeatherQueueFull class info:
 * 
 * default constructor
 * 1 parameter constructor
 */

package jac444.wk3;

import java.io.IOException;

public class WeatherQueueFull extends IOException{

	private static final long serialVersionUID = 1L;
	
	//default constructor
	public WeatherQueueFull() {
		super("The Queue is Full");
	}
	
	/*
	 * 1 parameter constructor
	 * @param String msg : the custom error message
	 */
	public WeatherQueueFull(String msg){
		super(msg);
	}
	
}
