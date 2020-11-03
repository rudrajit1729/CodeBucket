import java.io.*;

interface vehicle{
	public void gear(int g);
	public void speed(double s);
	public void Break();
	public void printstatus();
}

class Bike implements vehicle{
	double s; int g;
	Bike(double s, int g){
		this.s = s;
		this.g = g;
	}
	public void speed(double s){
		System.out.println("Speed of bike = " + s);
	}
	public void gear(int g){
		System.out.println("Bike is in " + g + " gear");
	}
	public void Break(){
		System.out.println("Break() - Stops the bike");
	}
	public void printstatus(){
		System.out.println("Status of bike");
		speed(this.s);
		gear(this.g);
		Break();
	}
}

class Car implements vehicle{
	double s; int g;
	Car(double s, int g){
		this.s = s;
		this.g = g;
	}
	public void speed(double s){
		System.out.println("Speed of car = " + s);
	}
	public void gear(int g){
		System.out.println("Car is in " + g + " gear");
	}
	public void Break(){
		System.out.println("Break() - Stops the Car");
	}
	public void printstatus(){
		System.out.println("Status of car");
		speed(this.s);
		gear(this.g);
		Break();
	}
}

class p1{
	public static void main(String args[]){
		Bike b = new Bike(40, 2);
		Car c = new Car(65, 3);
		b.printstatus();
		c.printstatus();
	}
}