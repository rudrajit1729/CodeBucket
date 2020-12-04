import java.io.*;
class p3{
	public static void main(String args[]){
		try{
			int a = 5/0;
		}
		catch(ArithmeticException e){
			System.out.println("Exception Occured :( ");
		}
		finally{
			System.out.println("Code under final block");
		}
	}
}