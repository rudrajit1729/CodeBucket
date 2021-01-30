class Sync{
	int n;
	synchronized int consume(){
		System.out.println("Consumed: " + n);
		return n;
	}
	synchronized void produced(int n){
	this.n=n;
	System.out.println("produced: " + n);
	}
}
class producer implements Runnable{
	Sync q;
	producer(Sync q){
		this.q=q;
		new Thread(this, "Producer").start();
	}
	public void run(){
		int i=0;
		while(true){
		q.produced(i++);
	 	}
	}
}
class consumer implements Runnable{
	Sync q;
	consumer(Sync q){
		this.q=q;
		new Thread(this, "Consumer").start();
	}
	public void run(){
		while(true){
		q.consume();
		}
	}
}
public class p1{
	public static void main(String[] args) {
		Sync q= new Sync();
		new producer(q);
		new consumer(q);
	}
}
