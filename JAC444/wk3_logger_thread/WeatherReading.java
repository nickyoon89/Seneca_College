/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * WeatherReading class info:
 * 
 * default constructor
 * 3 parameter constructor
 * toString() method
 * equals(WeatherReading) method
 */

package jac444.wk3;

import java.text.SimpleDateFormat;
import java.util.Date;

public class WeatherReading {
	Date _date;
	double _temp;
	String _location;
	
	//default constructor
	public WeatherReading() {
		_date = new Date();
		_temp = 0.0;
		_location = "null";
	}
	
	/*
	 * 3 parameter constructor
	 * @param Date date: date information of the weather forecast
	 * @param double temp: temperature
	 * @param String location: location name
	 */
	public WeatherReading(Date date, double temp, String location) {
		if(temp>=-40 && temp<=40 && date.before(new Date())) {
			_date = date;
			_temp=temp;
			_location = location;
		}else {
			_date = new Date();
			_temp = 0.0;
			_location = "null";
		}
	}
	
	//return well-formatted String
	@Override
	public String toString() {
		
		SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd");
		String format = formatter.format(_date);
		return format+", "+_location+": "+_temp+"\u00b0C";
	}
	
	/*
	 * check if parameter is same as current WeatherReading object
	 * @param WeatherReading arg: the object to compare with current object
	 */
	public boolean equals(WeatherReading arg) {
		boolean ret=true;
		if(!_date.equals(arg._date)||_temp!=arg._temp||_location!=arg._location) {
			ret = false;
		}
		return ret;
	}
}
