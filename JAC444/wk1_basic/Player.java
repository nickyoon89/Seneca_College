package jac444.wk1;

import java.text.ParseException;
import java.util.ArrayList;

public class Player {
	int money;
	ArrayList<Ticket> tickets=new ArrayList<Ticket>();
	
	//Constructor with one parameter, initial money
	public Player(int initMoney) {
		this.money=initMoney;
	}
	
	//Purchase one ticket, and add it to ticket list
	public void purchase(LottoCentre lot, LottoCentre.Generator gen, String date) throws ParseException {
		tickets.add(gen.generateTicket(date));
		this.money-=lot.tCost;
		lot.opMoney+=lot.tCost;
	}
}
