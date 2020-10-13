//Java Program to create a class called Piggy_bag
// author - rudrajit1729 

import java.io.*;

class Piggy_bag{
    double amt;
    Piggy_bag(){
        amt = 40.0;
        System.out.println("Balance: " + amt);
    }
    public double Balance()
    {
        return amt;
    }
    public void AddAmt(double amount)
    {
        amt += amount;
    }
}

class p4{
    public static void main(String args[])throws IOException{
        Piggy_bag bag = new Piggy_bag();
        //System.out.println("Initial balance in the piggy bag is "+bag.Balance());
        bag.AddAmt(500.0);
        System.out.println("Balance in the piggy bank after adding Rs 500 is "+bag.Balance());
    }
}