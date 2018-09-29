package jac444.wk1;

import java.util.Date;

public class Ticket {
	int number[]=new int[3];
	Date date;
	
	//Constructor with 2 parameters
	public Ticket(int n[], Date date) {
		for (int i = 0; i < n.length; i++) {
			number[i]=n[i];
		}
		this.date=date;
	};
	
	//check if the ticket won, return how many number they got
	public int compare(int n[], Date date) {
		int ret=0;
		if(date.compareTo(this.date)==0) {
			for (int i = 0; i < n.length; i++) {
				for (int j = 0; j < n.length; j++) {
					if(number[i]==n[j]) ret++;
				}
			}
		};
		return ret;			
	}
	
	//Getters
	public Date getDate() {
		return this.date;
	}
	public int[] getNumbers() {
		return this.number;
	}
}
