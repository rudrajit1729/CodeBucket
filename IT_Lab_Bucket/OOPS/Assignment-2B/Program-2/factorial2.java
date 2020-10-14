import java.util.*;
public class factorial2 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter a number ");
        long no=sc.nextLong();
        
        factorial2 ob = new factorial2();
        
        System.out.println("Factorial using iterations "+ob.fact(no));      
        System.out.println("Factorial using recursion "+ob.recfact(no));
    }
    long fact(long no){
        long f=1L;
        for(int i=1;i<=no;i++)
                f*=i;           //Iterative method of factorial calculation
        return f;
    }
    long recfact(long no){
        if(no==1)
            return 1L;
        return no*recfact(no-1); // Recursive method of factorial calculation
    }
}
