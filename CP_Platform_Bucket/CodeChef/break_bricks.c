#include <stdio.h>

// You can find the problem statement at https://www.codechef.com/JAN20B/problems/BRKBKS

int main()
{
    int t, i, s, w1, w2, w3;
    scanf("%d", &t);
    int minhit;

    for (i = 0; i < t; i++) {
        scanf("%d %d %d %d", &s, &w1, &w2, &w3);
        if ((w1+w2+w3) <= s)
            minhit = 1;
        else if ((w1+w2) <= s || (w2+w3) <= s)
            minhit = 2;
        else
            minhit = 3;
        printf("%d\n", minhit);
    }

    return 0;
}
