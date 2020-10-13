// Program to demonstrate constructor overloading
// author - rudrajit1729

import java.io.*;

// Class for representing employee
class Employee{
	String name, id; int age;

	// Default Constructor
	Employee(){
		this.name = "";
		this.id = "";
		this.age = 0;
	}

	// Two argument constructor
	Employee(String name, String id){
		this.name = name;
		this.id = id;
	}

	// Three argument constructor
	Employee(String name, String id, int age){
		this.name = name;
		this.id = id;
		this.age = age;
	}

	// Passing Object
	Employee(Employee e){
		this.name = e.name;
		this.id = e.id;
		this.age = e.age;
	}

	// Utility - shows details
	void showDetails(){
		System.out.println("Employee Details:\nName: " + name + "\nID: " + id + "\nAge: " + age);
	}
}

class p5{
	public static void main(String args[]){
		Employee e1 = new Employee("id1", "Rudy"); // Two args
		Employee e2 = new Employee("id1", "Rudy", 21); // Three args
		Employee e3 = new Employee(e2); // Object params
		e1.showDetails();
		e2.showDetails();
		e3.showDetails();

	}
}
