package jac444.wk1;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;
import java.util.Date;

import jac444.wk1.Ticket;

public class LottoCentre {
	int opMoney;
	int fPrize, sPrize, tPrize;
	int tCost;
	ArrayList<Ticket> winTickets=new ArrayList<Ticket>();
	
	//Decide initial money, winning prize, ticket cost by Constructor
	public LottoCentre(int om, int fp, int sp, int tp, int tc) {
		opMoney=om;
		fPrize=fp;
		sPrize=sp;
		tPrize=tp;
		tCost=tc;
	}
	
	//nested class Generator to generate ticket
	static class Generator{
		public Ticket generateTicket(String sDate) throws ParseException {
			ArrayList<Integer> numbers = new ArrayList<Integer>();
			for(int i=0;i<10;i++) {
				numbers.add(i+1);
			}
			Collections.shuffle(numbers);
			int[] randNum= {numbers.get(0),numbers.get(1),numbers.get(2)};
			SimpleDateFormat sdf= new SimpleDateFormat("yyyy-MM-dd");
			Date date = sdf.parse(sDate);
			Ticket ret = new Ticket(randNum, date);
			return ret;
		}
	};
	
	//Check all the lists and count how many round the user got prize and return the count
	public int[] getWinCount(ArrayList<Ticket> win, ArrayList<Ticket> userTicket) {
		int[] ret = {0, 0, 0};
		for (int i = 0; i < win.size(); i++) {
			for (int j = 0; j < userTicket.size(); j++) {
				switch (win.get(i).compare(userTicket.get(j).getNumbers(), userTicket.get(j).getDate())) {
				case 3:
					ret[0]++;
					break;
				case 2:
					ret[1]++;
					break;
				case 1:
					ret[2]++;
					break;
				default:
					break;
				}				
			}	
		}	
		return ret;
	};
	
	//main function
	public static void main(String[] args) {
		int count=50;
		SimpleDateFormat sdf= new SimpleDateFormat("yyyy-MM-dd");
		Date date=new Date();
		LottoCentre lottoCentre=new LottoCentre(1000000, 4000, 3500, 3000, 2500);
		Generator gen = new Generator();
		Player[] players=new Player[10];
		
		System.out.println("LottoCentre Initial Account Money: $"+lottoCentre.opMoney+"\n");
		
		//Create 10 player object with random money range of 20000 to 400000
		for(int i=0; i<players.length; i++) {
			players[i]=new Player((int)(Math.random()*((40000-20000)+1))+20000);
		}
		for(int i=0; i<count; i++) {
			//Every round has term of one day
			String dateTemp=sdf.format(date);
			Calendar c= Calendar.getInstance();
			c.setTime(date);
			c.add(Calendar.DATE, 1);
			date=c.getTime();
			
			//generate win ticket for the date, and every players purchase one ticket
			try {
				lottoCentre.winTickets.add(gen.generateTicket(dateTemp));
				for (int j = 0; j < players.length; j++) {
					players[j].purchase(lottoCentre, gen, dateTemp);
				}
			} catch (ParseException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		//Calculate the result and print out
		for(int i=0; i<players.length; i++) {
			System.out.println("Player#"+(i+1)+"\nInitial Account Money: $"+(players[i].money+50*lottoCentre.tCost));
			int[] winCount = lottoCentre.getWinCount(lottoCentre.winTickets, players[i].tickets);
			players[i].money+=lottoCentre.fPrize*winCount[0];
			lottoCentre.opMoney-=lottoCentre.fPrize*winCount[0];
			players[i].money+=lottoCentre.sPrize*winCount[1];
			lottoCentre.opMoney-=lottoCentre.sPrize*winCount[1];
			players[i].money+=lottoCentre.tPrize*winCount[2];
			lottoCentre.opMoney-=lottoCentre.tPrize*winCount[2];
			System.out.println("1st: "+winCount[0]+", 2nd: "+winCount[1]+", 3rd: "+winCount[2]);
			System.out.println("Final Account Money: $"+players[i].money+"\n");
		}
		System.out.println("LottoCentre Final Account Money: $"+lottoCentre.opMoney);
	}
}
