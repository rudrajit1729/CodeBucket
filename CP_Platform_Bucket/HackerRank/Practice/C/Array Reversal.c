//Submission link:
//https://www.hackerrank.com/challenges/reverse-array-c/submissions/code/181108260

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *a, i;
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int* left_ptr = a;
    int* right_ptr;
    int temp;
    for(i = 0; i < n; i++) {
        if(i == n - 1) {
            right_ptr = (a + i);
        }
    }
    while(left_ptr < right_ptr) {
        temp = *right_ptr;
        *right_ptr = *left_ptr;
        *left_ptr = temp;
        right_ptr--;
        left_ptr++;
    }
   for(i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    free(a);
    return 0;
}

