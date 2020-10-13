import java.io.*;

abstract class Bank{
	String Bank_iD, bank_name, IFSC_code;
	void display(){
		System.out.println("Bank ID: " + Bank_iD);
		System.out.println("Bank Name: " + bank_name);
		System.out.println("IFSC Code: " + IFSC_code);
	}
	abstract double getROI();
}

class SBI extends Bank{
	double rate = 1.05;
	String Bank_iD = "SBIN007";
	String bank_name = "SBI";
	String IFSC_code = "SBI1000000";
	void show(){
		display();
	}
	
	double getROI(){
		return 500000 * rate;
	}
}

class HDFC extends Bank{
	double rate = 1.08;
	String Bank_iD = "HDFC00108";
	String bank_name = "HDFC";
	String IFSC_code = "HDFC2000000";
	void show(){
		display();
	};
	double getROI(){
		return 500000 * rate;
	}
}

class PNB extends Bank{
	double rate = 1.06;
	String Bank_iD = "PNBIN00699";
	String bank_name = "PNB";
	String IFSC_code = "PNB3000000";
	void show(){
		display();
	}
	double getROI(){
		return 500000 * rate;
	}
}

class p1{
	public static void main(String args[]){
		SBI s = new SBI();
		HDFC h = new HDFC();
		PNB p = new PNB();
		double i1 = s.getROI(), i2 = h.getROI(), i3 = p.getROI();
		if(i1 > i2 && i1 > i3){
			System.out.println("Bank SBI");
			System.out.println("Highest Sum = " + i1);
		}
		else if(i2 > i3 && i3 > i1){
			System.out.println("Bank HDFC");
			System.out.println("Highest Sum = " + i2);
		}
		else{
			System.out.println("Bank PNB");
			System.out.println("Highest Sum = " + i3);
		}
	}
}