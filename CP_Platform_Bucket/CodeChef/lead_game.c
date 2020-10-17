#include <stdio.h>

// You can find the problem statement at https://www.codechef.com/IARCSJUD/problems/LEADGAME

int main()
{
    int n, max = 0, j;
    scanf("%d", &n);
    int s[n+1], t[n+1], w[n], l[n];
    s[0] = t[0] = 0;

    for (int i = 1; i < n+1; i++) {
        scanf("%d %d", &s[i], &t[i]);
        s[i] += s[i-1];
        t[i] += t[i-1];
        if (s[i] > t[i]) {
            w[i-1] = 1;
            l[i-1] = s[i] - t[i];
        } else {
            w[i-1] = 2;
            l[i-1] = t[i] - s[i];
        }
        if (l[i-1] > max) {
            max = l[i-1];
            j = i - 1;
        }
    }

    printf("%d %d", w[j], max);

    return 0;
}
