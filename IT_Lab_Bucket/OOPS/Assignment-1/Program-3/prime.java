class prime {
    public static void main(String[] args)
    {
        int a=Integer.parseInt(args[0]);
        int c=0;
        if(a==1 || a==0)
        {
            System.out.println("Not Prime"); // 1 and 0 is neither prime nor composite
        }
        else{
            for(int i=2;i<=Math.sqrt(a);i++)
            {
                if(a%i==0){
                    c+=1;       // Counting the number of factors which is not 1 or the number itself.
                }
            }
            if(c==0){
                System.out.print("Prime Number"); // The number has no factor other than 1 and itself so it is prime.
            }
            else{
                System.out.print("Composite Number");
            }
        }

    }
}
