import java.util.*;
public class LeapScanner {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in); // Scanner class object is created.
        System.out.println("Enter Year ");
        
        int year=sc.nextInt();
        
        LeapScanner ob = new LeapScanner(); // Object ob of class LeapScanner is created.
        System.out.println(ob.leap(year)); // Using created object ob to call the leap() function.
    }
    String leap(int year){
        if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)) // Leap Year condition
            return("Year "+year+" is a leap year");
        else
            return("Year "+year+" is not a leap year");
    }
}
