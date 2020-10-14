//**Program for calculating Taylor's Series
#include<stdio.h>

//Conventional approach using expansion e^x= 1 + x + (x^2)/2! + (x^3)/3! + ...
float e(int x, int n)
{
    static int p=1,f=1;
    float r;

    if(n==0)
        return 1;
    else
    {
        r=e(x,n-1);
        p=p*x;
        f=f*n;

        return r+(p/f);
    }

}

// We can perform this function with less number of multiplications. eg. for four terms: e^x = 1 + x[1 + x/2{ 1 + x/3( 1 + x/4)}]
//HORNER'S RULE:
float eH(int x, int n)
{
    static float s=1;

    if(n==0)
        return s;
    else
    {
        s = (1+x/n)*s;
        return eH(x,n-1);
    }

}

/* NOTE: There will be a difference in precision of both the functions becuase of number of multiplications*/
void main()
{
    printf("1+7+(7^2)/2+(7^3)/6+(7^4)/24=%f",e(7,4));
    printf("\n1+7+(7^2)/2+(7^3)/6+(7^4)/24=%f",eH(7,4));
}
