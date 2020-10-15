import java.util.*;
public class Demo {

    private String data;
    public static void main(String args[])
    {
        Demo ob1=new Demo(); 
        Demo ob2=new Demo();
        
        Scanner sc=new Scanner(System.in);
        String data1,data2;
        
        System.out.println("Enter first data: ");
        data1=sc.nextLine();
        ob1.setData(data1); // Setting first data to entered value.
        ob1.displayData();  // Displaying first data.
        
        System.out.println("Enter second data: ");
        data2=sc.nextLine();
        ob2.setData(data2); // Setting second data to entered value.
        ob2.displayData();  // Displaying second data.
    }

    void setData(String d){
        data=d;             // Setting the data.
    }
    void displayData(){
        System.out.println("The data is: "+data);   // Displaying the data.
    }
    
}
