class calculate {
    public static void main(String args[])
    {
        System.out.println("Enter 2 numbers: ");
        
        int a=Integer.parseInt(args[0]); //First commandline argument
        int b=Integer.parseInt(args[1]); // Second commandline argument

        System.out.println("SUM:"+(a+b)+"\nDIFF:"+(a-b)+"\nPRODUCT:"+(a*b)); // Finding Sum , Difference and Product of the 2 numbers
        

    }
}
