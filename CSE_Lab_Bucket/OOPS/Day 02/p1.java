// Demonstration of static data member, method and block in JAVA
// author - rudrajit1729

class p1{

	// Static Variables
	static int roll; static String name;

	// Static Method
	static void hello(){
		System.out.println("Hello World!!!");
	}

	// Static Block
	static{
		roll = 16;
		name = "Rudy";
	}

	public static void main(String args[]){
		hello(); // method called without having to create any object

		// Accessing Static variables - values of which are set in static block
		System.out.println("Roll: " + roll + "\nName: " + name);
	}
}
