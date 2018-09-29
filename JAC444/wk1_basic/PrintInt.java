package jac444.wk1;

import java.util.Scanner;

public class PrintInt {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		//get integer value from user
		System.out.println("Input Number:");
		int num = in.nextInt();
		
		//print out part
		System.out.println("Input Number: "+num);
		System.out.println("Binary: "+Integer.toString(num,2));
		System.out.println("Octal: "+Integer.toString(num,8));
		System.out.println("Hex: "+Integer.toString(num,16));
		System.out.println("Reciprocal Hex: "+Float.toHexString(1f/num));
		in.close();
	}
}
