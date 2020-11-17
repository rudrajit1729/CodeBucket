import java.io.*;
class Student{
	String sname, sid, dept, year;
	void getDetails()throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter name: ");
		sname = in.readLine();
		System.out.print("Enter dept: ");
		dept = in.readLine();
		System.out.print("Enter year: ");
		year = in.readLine();
		System.out.print("Enter ID: ");
		sid = in.readLine();
		System.out.println();
	}
	void showDetails(){
		System.out.println("Student Name: " + sname);
		System.out.println("Department: " + dept);
		System.out.println("Year: " + year);
		System.out.println("Student ID: " + sid);
	}
}

class p2{
	public static void main(String args[])throws IOException{
		Student S[] = new Student[5];
		Student s = new Student();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int i;
		for(i = 0; i< 5; i++){
			System.out.println("Enter details of Student " + (i+1));
			s.getDetails();
			S[i] = s;
		} 
		for(i = 0; i< 5; i++){
			System.out.println("Details of Student " + (i+1));
			S[i].showDetails();
		} 
	}
}