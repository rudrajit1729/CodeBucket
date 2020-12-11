import java.io.*;

class p1{
	public static void ball(){
		try{
			throw new ArithmeticException("Ball Thrown");
		}
		catch(ArithmeticException e){
			System.out.println("Ball Caught and thrown back");
			throw e; // Rethrow exception
		}
	}
	public static void main(String args[]){
		try{
			ball();
		}
		catch(ArithmeticException e){
			System.out.println("Ball caught in main");
		}
	}
}

