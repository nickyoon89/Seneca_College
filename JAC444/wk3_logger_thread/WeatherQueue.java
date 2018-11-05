/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * WeatherQueue class info:
 * 
 * 1 parameter constructor
 * void put(WeatherReading) method
 * WeatherReading get() method
 */

package jac444.wk3;

import java.util.LinkedList;
import java.util.Queue;

public class WeatherQueue {
	Queue<WeatherReading> _queue;
	int _maxSize;
	int _size;	
	
	/*
	 * 1 parameter constructor
	 * @param int maxSize: the max size of queue
	 */
	public WeatherQueue(int maxSize){
		_queue = new LinkedList<>();
		_maxSize=maxSize;
		_size=0;
	}
	
	/* 
	 * add WeatherReading object to the WeatherQueue object, throw error when it reaches the max size
	 * @param WeatherReading wr : WeatherReading object to add in WeatherQueue object
	 */
	public void put(WeatherReading wr) throws WeatherQueueFull{
		if(_size>=_maxSize) {
			throw new WeatherQueueFull();
		}
		_queue.add(wr);
		_size++;
	}
	
	// return the first value of the queue, throws error when there is no value
	public WeatherReading get() throws WeatherQueueEmpty {
		if(_size==0) {
			throw new WeatherQueueEmpty();
		}
		return _queue.poll();
	}
}
