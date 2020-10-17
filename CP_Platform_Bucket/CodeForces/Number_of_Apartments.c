#include <stdio.h>

// You can find the problem statement at https://codeforces.com/contest/1430/problem/A

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        if (n == 1 || n == 2 || n == 4)
            printf("-1\n");
        else {
            int r, c3, c5, c7;
            r = n % 7;
            c7 = n / 7;
            switch(r) {
                case 0:
                    c3 = 0;
                    c5 = 0;
                    break;
                case 1:
                    c7--;
                    c3 = 1;
                    c5 = 1;
                    break;
                case 2:
                    c7--;
                    c3 = 3;
                    c5 = 0;
                    break;
                case 3:
                    c3 = 1;
                    c5 = 0;
                    break;
                case 4:
                    c7--;
                    c3 = 2;
                    c5 = 1;
                    break;
                case 5:
                    c3 = 0;
                    c5 = 1;
                    break;
                case 6:
                    c3 = 2;
                    c5 = 0;
                    break;
            }
            printf("%d %d %d\n", c3, c5, c7);
        }
    }
}