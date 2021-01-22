import java.io.*;
class Multi extends Thread
{  
    public void run()
    {  
        System.out.println("Thread extending Thread class is running......");  
    }  
}

class Multi3 implements Runnable
{
    public void run()
    {  
    System.out.println("Thread implementing Runnable is running......");  
    }  
}


class p1
{
    public static void main(String args[])
    {  
        Multi t1 = new Multi();  
        t1.start();
        Multi3 m1 = new Multi3();  
        Thread t2 = new Thread(m1);  
        t2.start();  
    }  
}