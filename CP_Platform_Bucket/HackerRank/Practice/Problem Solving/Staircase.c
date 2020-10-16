//Submission link:
//https://www.hackerrank.com/challenges/staircase/submissions/code/184115325

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a,i,j,k;
    scanf("%d",&a);
    
    for(i=1;i<a+1;i++)
        {
        for(j=1;j<=a-i;j++)
            {
            printf(" ");  
            }
        for(k=i;k>0;k--)
            {
            printf("#");
        }
        printf("\n");
        }
    return 0;
}

