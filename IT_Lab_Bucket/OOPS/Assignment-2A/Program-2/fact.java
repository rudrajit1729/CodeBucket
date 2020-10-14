import java.io.*;
class fact
{
  public static void main(String args[])throws IOException
  {
    BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
    System.out.print("Enter number to find its factorial: ");
    int a= Integer.parseInt(br.readLine());
    int ch;
    char i;
    while(true)
    {
      System.out.print("Enter 1 to use recursive method\nEnter 2 to use non-recursive method\nEnter choice: ");
      ch=Integer.parseInt(br.readLine());
      switch(ch)
      {
        case 1: int r=factRec(a);
                System.out.print("Factorial of "+a+" is "+r+" (Recursive method)");
                break;
        case 2: int t=factNonRec(a);
                System.out.print("Factorial of "+a+" is "+t+" (Non-recursive method)");
                break;
        default: System.out.print("Invalid choice. Enter again....");
                continue;
      }
      System.out.print("\nDo you wish to continue?(Y/N): ");
      
      i=(char)br.read();
      if(!(i=='Y'||i=='y'))
        break;
        br.readLine();
    }
    br.close();
    System.exit(0);
  }
  public static int factRec(int a)
  {
    if(a==0)
      return 1;
    else
      return a--*factRec(a);
  }
  public static int factNonRec(int a)
  {
    int f=1;
    if(a==0)
      return 1;
    do
    {
      f*=a;
    }while(--a>0);
    return f;
  }
}
