// JAVA program to demonstrate anonymous object
// author - rudrajit1729

import java.io.*;

// Class for Sum of natural nos till n
class SumOfNumbers{
	// Utility - Calculates sum of natural nos. from 1...n
	public int getSum(int n){
		return ((n*(n+1))/2);
	}
}

class p3{
	public static void main(String [] args)throws IOException{
		int n;
		System.out.print("Enter value of n : ");
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(in.readLine());
		// Anonymous object
		int sum = new SumOfNumbers().getSum(n);
		System.out.println("Sum of natural nos. till " + n + " is = " + sum);
	}
}