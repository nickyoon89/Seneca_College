package jac444.wk1;

import java.util.Scanner;

public class IsSquare {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		boolean isMagic=true;
		boolean isSquare=true;
		int rowCol =0, sum=0;
		int[] rowSum, colSum, digSum;
		String line="", temp;
		int[][] matrix;

		//Get matrix data from user in one String variable named line
		while(true) {
			System.out.print("Input law No "+(rowCol+1)+":");
			temp = in.nextLine();
			
			//insert '/' as a delimiter represents new line
			if(!temp.isEmpty()) {
				line+=temp;
				line += "/";
				rowCol++;
			}else{
				break;
			}
		};
		matrix = new int[rowCol][rowCol];
		
		//split line by line
		String cols[] = line.split("/");
		
		//Store the input data in shape of matrix
		for (int i = 0; i < rowCol; i++) {
			//column delimiter is space
			String str[] = cols[i].split(" ");
			//check if the matrix is square
			if(str.length!=rowCol) {
				isSquare=false;
				isMagic=false;
				break;
			}
			for (int j = 0; j < rowCol; j++) {
				matrix[i][j]=Integer.parseInt(str[j]);
			}
		}
		
		//calculate row, col and diag sum
		if(isSquare) {
			rowSum = new int[rowCol];
			colSum = new int[rowCol];
			digSum = new int[2];
			for (int i = 0; i < rowCol; i++) {
				sum+=matrix[0][i];
			}
			for (int i = 0; i < rowCol; i++) {
				for (int j = 0; j < rowCol; j++) {
					colSum[i]+=matrix[i][j];
					rowSum[j]+=matrix[i][j];
					if (i==j) {
						digSum[0]+=matrix[i][j];
					}
					if(i==(rowCol-j-1)) {
						digSum[1]+=matrix[i][j];
					}
				}
			}
			//compare if all sum value is same
			for (int i = 0; i < rowCol; i++) {
				if(rowSum[i]!=sum || colSum[i]!=sum) { 
					isMagic=false;
					break;
				}
			}
			if(digSum[0]!=sum || digSum[1]!=sum) isMagic=false;
		}
		
		//print out the result
		if(isMagic) System.out.println("The Matrix is Magic");
		else System.out.println("The Matrix is NOT Magic");
		in.close();
	}
}
