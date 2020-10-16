import java.io.*;
public class fileRead {
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter filename to read ");
        String filename=br.readLine();
        
        // Reading entire file
        
        BufferedReader br2 = new BufferedReader(new FileReader(filename));
        
        System.out.println("Reading entire file contents: ");

        String line = br2.readLine();       // Reading the first line
	    while (line != null) {              // Reading all lines till the end of file.
	        System.out.println(line); 
	        line = br2.readLine();
        }
        
        System.out.println();
        
        //Reading a single line
        System.out.println("Reading first line of file: ");
        BufferedReader br1 = new BufferedReader(new FileReader(filename));
        System.out.println(br1.readLine());       // Reading only the first line

        br.close(); 
        br1.close();
        br2.close();
    }
    
}
