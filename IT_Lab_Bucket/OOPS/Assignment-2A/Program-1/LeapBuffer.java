import java.io.*;
public class LeapBuffer {
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter Year ");
        int year=Integer.parseInt(br.readLine());
        LeapBuffer ob = new LeapBuffer();
        System.out.println(ob.leap(year));
    }
    String leap(int year){
        if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
            return("Year "+year+" is a leap year");
        else
            return("Year "+year+" is not a leap year");
    }
}
