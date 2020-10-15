//Program to print nth term of Fibonacci series

//Fibonacci series: 1 1 2 3 5 8 13 ...
//The nth term is the summation of (n-1)th and (n-2)th term

//Conventional function using formula:

int fib(int n)
{
    if(n<=1)
        return n;
    else 
        return fib(n-2) + fib(n-1);
}
//The above recursive function calls itself for the same values again i.e for eg. fib(0),fib(1),fib(2), etc.
//Such functions are called EXCESSIVE RECURSION FUNCTIONS.
//To avoid such a problem, we use MEMOIZATION. We store results of a function call so that we can utilize it again for the same function call.

int f[20];//Global array for storing values



int Mfib(int n)
{   
    if(n<=1)
    {
        f[n]=n;
        return n;
    }
    else
    {
        if(f[n-2]==-1)
            f[n-2]=fib(n-2);
        if(f[n-1]==-1)
            f[n-1]=fib(n-1);
        return f[n-1]+f[n-2];
        
            
    }
    
}

void main()
{   
    int i;
    for(i=0;i<20;i++)
    {
        f[i]=-1;
    }
    printf("%d",fib(6));
    printf("\n%d",Mfib(6));
}
