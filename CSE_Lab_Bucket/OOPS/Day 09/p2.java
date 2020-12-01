import java.io.*;
class p2{
	public static void main(String args[]){
		try{
			int A[] = new int[5];
			A[6] = 10;// Array has length 5 which makes 6 an invalid index
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Array Index is out of Bounds");
		}
	}
}
			
