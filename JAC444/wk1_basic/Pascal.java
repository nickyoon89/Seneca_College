package jac444.wk1;

import java.util.Scanner;

public class Pascal {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		//get how level of triangle user want to make
		System.out.println("How many level of Pascal Triangle do you want: ");
		int level= in.nextInt();
		
		//allocate memory as given triangle level
		int pascalTriangle[][]=new int[level][];
		
		//decide value
		for (int i = 0; i < level; i++) {
			pascalTriangle[i]=new int[i+1];
			
			//insert value as 1 to first and last value of the level 
			pascalTriangle[i][0]=1;
			pascalTriangle[i][i]=1;
			
			//calculate middle values 
			for (int j = 1; j < i; j++) {
				pascalTriangle[i][j]=pascalTriangle[i-1][j-1]+pascalTriangle[i-1][j];
			}
			
			//print out level by level
			for (int j = 0; j < i+1; j++) {
				System.out.print(pascalTriangle[i][j]+"\t");
			}
			System.out.println();
		}
		in.close();
	}
}
