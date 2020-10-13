import java.io.*;

class Figure{
	double d1, d2;
	Figure(double d1, double d2){
		this.d1 = d1;
		this.d2 = d2;
	}
	double area(){
		return d1 * d2;
	}
	void show(){
		System.out.println("Area = " + area());
	}
}

class Rectangle extends Figure{
	Rectangle(double d1, double d2){
		super(d1, d2);	
	}
	
	double area(){
		return d1 * d2;
	}
	void show(){
		System.out.println("Area of Rectangle = " + area());
	}
}

class Triangle extends Figure{
	double d3;
	Triangle(double d1, double d2, double d3){
		super(d1, d2);
		this.d3 = d3;	
	}
	double area(){
		double s = (d1+d2+d3)/2;
		double a = Math.pow((s*(s-d1)*(s-d2)*(s-d3)), 0.5);
		return a;
	}
	void show(){
		System.out.println("Area of Triangle = " + area());
	}
}

class p1{
	public static void main(String args[]){
		Rectangle r = new Rectangle(10, 20);
		r.show();
		Triangle t = new Triangle(10, 10.2, 3.8);
		t.show();
	}
}