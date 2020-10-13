// Static method instantiation JAVA
// author - rudrajit1729

// Class containing static method
class p2{
	// Static Method
	static void hello(){
		System.out.println("Hello World!!!");
	}

	public void hi(){
		System.out.println("HI");
	}

	public static void main(String args[]){
		// Create object of class p2
		p2 h = new p2();
		h.hi(); // Shows no error
		hello(); // Object not needed
	}
}



