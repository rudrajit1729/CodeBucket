import java.io.*;
class p1{
	public static void main(String args[]){
		try{
			int A[] = new int[5];
			// A[1] = 5/0;
			System.out.println("Commented division by 0 to demonstrate NullPointerException handling. \nUncomment to see ArithmeticException handling");
			String s = null;
			System.out.println(s.toString());
		}
		catch(ArithmeticException e){
			System.out.println("Arithmetic Exception Occured :( ");
		}
		catch(NullPointerException e){
			System.out.println("Null Pointer Exception Occured :( ");
		}
	}
}