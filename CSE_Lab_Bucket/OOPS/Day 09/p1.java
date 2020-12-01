import java.io.*;
class p1{
	public static void main(String args[]){
		int a = 5/0; // Divide by 0 -> ArithmeticException
		// Not handling the exception
		// Next statements shouldn't be executed
		System.out.println("Code block");
	}
}