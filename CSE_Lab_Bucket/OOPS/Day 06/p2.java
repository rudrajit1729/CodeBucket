import java.io.*;
class p2{
	public static void main(String args[]){
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		if (args.length > 0){
			int n = args.length;
			// Raise Exception - OutOfBound
			System.out.println("Access out of bound - Exception Upcoming");
			System.out.println(args[n+1]);
		}
		else{
			System.out.println("No args passed - Exception Upcoming");
			System.out.println(args[1]);
		}

	}
}