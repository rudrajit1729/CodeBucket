abstract class EMP{
	void getinfo(String emp_id, String name, String date){
		System.out.println("Emp ID: " + emp_id);
		System.out.println("Emp Name: " + name);
		System.out.println("Date of joining: " + date);
	}
	abstract double get_sal();
}

class Manager extends EMP{
	double basic = 65000, allow = 0.75;
	double get_sal(){
		getinfo("MANAGER1", "ALEX", "4th JAN, 2000");
		return (1+allow) * basic;
	}

}

class Sales extends EMP{
	double basic = 30000, allow = 0.99;
	double get_sal(){
		getinfo("SALES1", "MAX", "4th APR, 2010");
		return (1+allow) * basic;
	}
}

class p2{
	public static void main(String args[]){
		Manager m = new Manager();
		Sales s = new Sales();
		double ms = m.get_sal();
		System.out.println("Salary = " + ms + "\n");
		double ss = s.get_sal();
		System.out.println("\nSalary = " + ss);
	}
}