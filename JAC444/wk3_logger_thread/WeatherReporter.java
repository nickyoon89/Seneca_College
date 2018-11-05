/*
 *@author Jihyun Yoon (124 558 172)
 *  
 * WeatherReporter class info:
 * 
 * 4 parameter constructor
 * void reportReadings()
 * void run()
 */

package jac444.wk3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class WeatherReporter implements Runnable{
	WeatherQueue wq;
	String inputFile;
	Logger logger;
	String logFile;

	/*
	 * 4 parameter constructor
	 * @param String input: the location and file name of input file
	 * @param String log: the location and file name of log file
	 * @param WeatherQueue queue: Weather Queue all the reporter will deal with
	 * @param Logger logg: the logger to write log in the log file
	 */
	public WeatherReporter(String input, String log, WeatherQueue queue, Logger logg) {
		logFile=log;
		inputFile=input;
		logger = logg;
		wq = queue;
	}
	
	//Get data from input file and make it as WeatherReading object. Then put it in the queue
	public void reportReadings() {
		try {
			FileHandler handler = new FileHandler(logFile);
			SimpleFormatter sformatter = new SimpleFormatter();
			handler.setFormatter(sformatter);
			logger.addHandler(handler);
			logger.setLevel(Level.ALL);
		} catch (IOException e) {
			System.out.println("File handler failed");
		}
		try (BufferedReader br = new BufferedReader(new FileReader(inputFile))) {
			String line;
				while ((line = br.readLine()) != null) {
					String[] parts = line.split(",");
					SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
					Date date = simpleDateFormat.parse(parts[0]);
					WeatherReading wr = new WeatherReading(date, new Double(parts[2]), parts[1]);
					if(wr._location!="null") {
						synchronized(wq) {
							wq.put(wr);
							//wq.wait(600);
						}
					}
				} 
			logger.log(Level.FINER, "File Successfully red");
		} catch (WeatherQueueFull e) {
			logger.log(Level.WARNING, "The Queue is Full", e);
		} catch (WeatherQueueEmpty e) {
			logger.log(Level.WARNING, "The Queue is Empty", e);
		} catch (IOException e) {
			logger.log(Level.WARNING, "can't open", e);
		} catch (Exception e) {
			logger.log(Level.WARNING, "error", e);
		}
	}
	
	//To call reportReadings() method as a thread
	@Override
	public void run() {
		reportReadings();
	}
}
