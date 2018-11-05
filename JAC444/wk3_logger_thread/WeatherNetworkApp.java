/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * WeatherNetworkApp class info:
 * 
 * static void main(String[] args) method
 */

package jac444.wk3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class WeatherNetworkApp {
	
	//main function
	public static void main(String[] args){
		//Saving all the WeatherReadings in this queue object
		WeatherQueue wq = new WeatherQueue(50);
		
		//loggers declaration
		Logger logger = Logger.getLogger("wk3Log");
		try {		
			FileHandler handler = new FileHandler("wk3.log");
			SimpleFormatter sformatter = new SimpleFormatter();
			handler.setFormatter(sformatter);
			logger.addHandler(handler);
			logger.setLevel(Level.ALL);
		} catch (IOException e) {
			System.out.println("File handler failed");
		}
		Logger logger1 = Logger.getLogger("wk3Thread1");
		Logger logger2 = Logger.getLogger("wk3Thread2");
		Logger logger3 = Logger.getLogger("wk3Thread3");
		
		// spawn multiple threads
		Thread t1= new Thread(new WeatherReporter("./inputFile.txt", "thread1.log", wq, logger1));
		Thread t2= new Thread(new WeatherReporter("inputFile.txt", "thread2.log", wq, logger2));
		Thread t3= new Thread(new WeatherReporter("inputFile.txt", "thread3.log", wq, logger3));
		
		// start the threads
		t1.start();
		t2.start();
		t3.start();
		// wait until they are done
		try {
			t1.join();
			t2.join();
			t3.join();
		} catch (InterruptedException e) {
			logger.log(Level.WARNING, "thread join interrupted", e);
		}
		
		//outputting the data within the queue object in the file named "output.txt"
		System.out.println("File writing start");
		try {
			File file = new File("output.txt");
			PrintWriter pw = new PrintWriter(file);
			for(int i=0; i<wq._size; i++) {
				pw.println((i+1)+". "+wq.get());
			}
			pw.close();
		} catch (WeatherQueueEmpty e) {
			logger.log(Level.WARNING, e.getMessage(), e);
		} catch (FileNotFoundException e) {
			logger.log(Level.WARNING, "can't open", e);
		}
		logger.log(Level.FINER, "File writing ends successfully");
		System.out.println("File writing ends successfully");
	}
}
