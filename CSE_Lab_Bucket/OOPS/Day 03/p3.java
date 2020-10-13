import java.io.*;

abstract class Example{
	void printing(){
		System.out.println("Non abstract method here");
	}
	abstract double show();
}

class p3{
	public static void main(String args[]){
		Example e = new Example();
		System.out.println("Test Pass ? ");
	}
}