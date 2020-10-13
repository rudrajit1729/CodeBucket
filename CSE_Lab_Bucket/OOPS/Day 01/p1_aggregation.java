// Concept of Aggregation in JAVA
// author - rudrajit1729

import java.io.*;
import java.util.*;


// Class for student representation
class Student{
	String name, dept; int roll;
	Student(String name, String dept, int roll){
		this.name = name;
		this.dept = dept;
		this.roll = roll;
	}
}

// Class for dept representation
class Dept{
	String name;
	private List<Student> students;

	Dept(String name, List<Student> students){
		this.name = name;
		this.students = students;
	}

	public List<Student> getList(){
		return students;
	}
}

// Class for Institute representation
class Institute{
	String name;
	private List<Dept> depts;

	Institute(String name, List<Dept> depts){
		this.name = name;
		this.depts = depts;
	}

	public int getAllStudents(){
		int ans = 0;
		List<Student> students;
		for(Dept dept: depts){
			students = dept.getList();
			ans += students.size();
		}
		return ans;
	}
}

class p1_aggregation{
	public static void main(String args[]){
		// Students
		Student s1 = new Student("Rudy", "CSE", 16);
		Student s2 = new Student("Alex", "IT", 15);
		Student s3 = new Student("Max", "ECE", 63);
		Student s4 = new Student("Angela", "EE", 32);

		// List of Students
		List <Student> cse_guys = new ArrayList<Student>();
		cse_guys.add(s1);

		List <Student> it_guys = new ArrayList<Student>();
		cse_guys.add(s2);

		List <Student> ece_guys = new ArrayList<Student>();
		cse_guys.add(s3);

		List <Student> ee_guys = new ArrayList<Student>();
		cse_guys.add(s4);

		// Departments
		Dept CSE = new Dept("CSE", cse_guys);
		Dept IT = new Dept("IT", it_guys);
		Dept ECE = new Dept("ECE", ece_guys);
		Dept EE = new Dept("EE", ee_guys);

		// List of depts
		List <Dept> depts = new ArrayList<Dept>();
		depts.add(CSE);
		depts.add(IT);
		depts.add(ECE);
		depts.add(EE);

		// Institute
		Institute institute = new Institute("XYZ College", depts);
		System.out.println("Total students in XYZ College = " + institute.getAllStudents());
	}

}

