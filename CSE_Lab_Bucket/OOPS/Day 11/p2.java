import java.io.*;

class p2{
	public static void main(String args[])throws IOException{
		try{
		if (args.length > 3)
			throw new IllegalArgumentException("Exception");
		else
			System.out.println("Ok test!!!");
		}
		catch(IllegalArgumentException e){
			System.out.println("Length greater than can be handled");
		}
	}
}