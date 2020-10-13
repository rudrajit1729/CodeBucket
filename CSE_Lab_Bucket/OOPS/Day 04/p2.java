import java.io.*;
class Employee{
	String ename, empid, dob, doj, designation;
	void getinfo()throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter name: ");
		ename = in.readLine();
		System.out.print("Enter ID: ");
		empid = in.readLine();
		System.out.print("Enter DOB: ");
		dob = in.readLine();
		System.out.print("Enter DOJ: ");
		doj = in.readLine();
		System.out.print("Enter designation: ");
		designation = in.readLine();
		System.out.println();
	}
	void showinfo(){
		System.out.println("Emp Name: " + ename);
		System.out.println("Emp ID: " + empid);
		System.out.println("Emp dob: " + dob);
		System.out.println("Emp doj: " + doj);
		System.out.println("Emp designation: " + designation);
	}
}

class p2{
	public static void main(String args[])throws IOException{
		Employee e[] = new Employee[10];
		Employee x = new Employee();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int i;
		for(i = 0; i< 10; i++){
			System.out.println("Enter details of Employee " + (i+1));
			x.getinfo();
			e[i] = x;
		} 
		for(i = 0; i< 10; i++){
			System.out.println("Details of Employee " + (i+1));
			e[i].showinfo();
		} 
	}
}