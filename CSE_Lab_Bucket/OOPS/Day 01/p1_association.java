// Concept of Association in JAVA
// author - rudrajit1729

import java.io.*;

// Demo Classes
class Dept{
	String name;
	Dept(String name){
		this.name = name;
	}

	public String getDeptName(){
		return name;
	}
}

// Demo Classes
class Employee{
	String name;
	Employee(String name){
		this.name = name;
	}

	public String getEmpName(){
		return name;
	}
}

class p1_association{
	public static void main(String args[])throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter employee name: ");
		String name = in.readLine();
		System.out.print("Enter dept name: ");
		String dept = in.readLine();
		Employee e = new Employee(name);
		Dept d = new Dept(dept);

		// Associating different classes 
		System.out.println(e.getEmpName() + " works in " + d.getDeptName() + " department");

	}
}
