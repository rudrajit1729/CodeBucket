import java.io.*;

class Complex{
	public void toString(double a, double b){
		char sym = (b >= 0)?'+':'-';
		if(b < 0) b *=-1;
		System.out.print(a + " " + sym + " " + b + "i");
		System.out.println();
	}
	public void add(double a, double b, double c, double d){
		double x = a + c;
		double y = b + d;
		System.out.print("Result : ");
		toString(x, y);
	} 

	public void subtract(double a, double b, double c, double d){
		double x = a - c;
		double y = b - d;
		System.out.print("Result : ");
		toString(x, y);
	}

	public void multiply(double a, double b, double c, double d){
		double x = (a * c) - (b * d);
		double y = (a * d) + (b * c);
		System.out.print("Result : ");
		toString(x, y);
	}
}

public class p1{
	public static void main(String args[]){
		double a = 3, b = 2; // (3 + 2i)
		double c = 1, d = 7; // (1 + 7i)
		Complex C = new Complex();
		System.out.println("Complex Numbers : ");
		C.toString(a, b);
		C.toString(c, d);
		System.out.println("Addition of 2 complex numbers: ");
		C.add(a, b, c, d);
		System.out.println("Subtraction of 2 complex numbers: ");
		C.subtract(a, b, c, d);
		System.out.println("Multiplication of 2 complex numbers: ");
		C.multiply(a, b, c, d);

	}
}