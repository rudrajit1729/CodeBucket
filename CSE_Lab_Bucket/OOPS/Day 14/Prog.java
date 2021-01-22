class Prog{
	public static void main(String args[])throws InterruptedException{
		long mem;
		Prog p1 = new Prog(); // Reference object
		Prog p2 = new Prog();
		
		mem = Runtime.getRuntime().freeMemory();
		System.out.println("Free memory : " + mem);

		p1 = null; // reference object nullified
		
		System.gc(); // Garbage collector called

		mem = Runtime.getRuntime().freeMemory();
		System.out.println("Free memory : " + mem);

		p2 = p1;//Reassigned reference object
		System.gc(); // Garbage collector called

		mem = Runtime.getRuntime().freeMemory();
		System.out.println("Free memory : " + mem);

		System.out.println(p2);
	}
	protected void finalize()throws Throwable{
		System.out.println("Object destroyed via GC : " + this);
	}
}

