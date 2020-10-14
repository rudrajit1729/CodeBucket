import java.io.*;
import java.util.*;
public class fileRead2 {
    public static void main(String args[])throws FileNotFoundException
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter filename to read ");
        String filename=sc.nextLine();
        
        
        // Reading entire file
        
        Scanner sc2 = new Scanner(new FileReader(filename)); 
        System.out.println("Reading entire file contents: ");
        
        String line = sc2.nextLine();
	    while (sc2.hasNextLine()) {
	      System.out.println(line);
	      line = sc2.nextLine();
        }
        System.out.println(line);
        
        System.out.println();
        
        //Reading a single line
        
        System.out.println("Reading first line of file: ");
        Scanner sc1 = new Scanner(new FileReader(filename));
        System.out.println(sc1.nextLine());       

        sc.close();
        sc2.close();
        sc1.close();
    }    
}
