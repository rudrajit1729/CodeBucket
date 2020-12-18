
import java.io.*;

class College{
	void name()throws IOException{
		System.out.println("STCET");
	}
}

class Dept extends College{
	void name()throws IOException{
		System.out.println("CSE");
	}
}

class p1_b{
	public static void main(String args[])throws IOException{
		Dept d = new Dept();
		System.out.println("Overriden Function throws exception");
		System.out.println("Exception defined in parent");
		d.name();
	}
}

