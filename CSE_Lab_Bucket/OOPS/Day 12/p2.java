import java.io.*;

class RankException extends Exception{
	RankException(String txt){
		super(txt);
	}
}

class p2{
	static void rankValidation(int rank)throws RankException{
		if(rank > 1000)
			throw new RankException("Rank No: " + rank + ", You are not selected :(");
		else
			System.out.println("Rank No: " + rank + "!!! You are selected!");
	}
	public static void main(String args[]){
		try{
			rankValidation(2000);
		}
		catch(Exception e){
			System.out.println("Exception Occured: " + e);
		}
		System.out.println("Safe block of code");
	}
}