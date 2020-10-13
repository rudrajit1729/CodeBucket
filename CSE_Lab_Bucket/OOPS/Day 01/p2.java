// Class Student with members - dept, roll, name, year
// Instantiate the class into main method - JAVA
// author - rudrajit1729

import java.io.*;

// Student class
class Student{
	String name, dept, year;
	int roll;

	// Constructor
	Student(String name, String dept, String year, int roll){
		this.name = name;
		this.dept = dept;
		this.year = year;
		this.roll = roll;
	}

	// Utility function - Shows details
	public void showDetails(){
		System.out.println("Student details:\nName: " + name + "\nDept: " + dept + "\nyear: " + year + "\nroll: " + roll + "\n");
	}
}

class p2{
	public static void main(String [] args)throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String name, dept, year; int roll;
		System.out.println("Enter Student Details: ");
		System.out.print("Enter Name: ");
		name = in.readLine();
		System.out.println("Enter Dept: ");
		dept = in.readLine();
		System.out.print("Enter Year: ");
		year = in.readLine();
		System.out.println("Enter Roll: ");
		roll = Integer.parseInt(in.readLine());

		// Create an object of Student Class
		Student student = new Student(name, dept, year, roll);
		// Show student details
		student.showDetails();

	}
}