
import java.io.*;

class College{
	void name(){
		System.out.println("STCET");
	}
}

class Dept extends College{
	void name()throws IOException{
		System.out.println("CSE");
	}
}

class p1_a{
	public static void main(String args[])throws IOException{
		Dept d = new Dept();
		System.out.println("Overriden Function throws exception");
		System.out.println("Exception not defined in parent -> Compilation Error coming up");
		d.name();
	}
}

