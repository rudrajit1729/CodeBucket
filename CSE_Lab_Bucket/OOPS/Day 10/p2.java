import java.io.*;

class p2{
	public static void main(String args[]){
		// Accessable Section of Code
		System.out.println("Reachable Section");
		return;// Method termination access to call back - here OS
		// Unreachable Section of Code
		System.out.println("Unreachable Section");
	}
}