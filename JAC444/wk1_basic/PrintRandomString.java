package jac444.wk1;

import java.util.Random;

public class PrintRandomString {
	public static void main(String[] args) {
		//generate random long value
		long randomLong=new Random().nextLong();
		//print out the value as String base in 36
		System.out.println(Long.toString(randomLong,36));
	}
}
