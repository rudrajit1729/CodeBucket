import java.util.*;
public class Bank_Account {
    
    String Account_Holder_Name;
    long Account_Number;
    char Account_Type;
    double balance;

    Bank_Account(String name,long acno,char type,double bal){   // Constructor
        Account_Holder_Name=name;
        Account_Number=acno;
        Account_Type=type;
        balance=bal;
    }
    double withdraw_money(double amount){   // Method to update balance after withdrawal
        balance-=amount;
        return balance;
    }
    double deposit_money(double amount){    // Method to update balance after deposit
        balance+=amount;
        return balance;
    }
    public static void main(String args[])
    {
        String name;
        long acno;
        char type;
        double bal, amount;

        //Input of Account Holder details
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Account Holder Name: ");
        name=sc.nextLine();
        System.out.println("Enter Account Number: ");
        acno=sc.nextLong();
        System.out.println("Enter Account Type: ");
        type=sc.nextLine().charAt(0);
        System.out.println("Enter Balance: ");
        bal=sc.nextDouble();
        
        Bank_Account ob= new Bank_Account(name, acno, type, bal);  
        
        //Displaying balance after deposit and withdraw from account.
        System.out.println("Enter Amount to deposit: ");
        amount=sc.nextDouble();
        System.out.println("Balance is : "+ob.deposit_money(amount));

        System.out.println("Enter Amount to withdraw: ");
        amount=sc.nextDouble();
        System.out.println("Balance is : "+ob.withdraw_money(amount));

    }
}
