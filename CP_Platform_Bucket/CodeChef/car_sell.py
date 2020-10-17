# cook your dish here
t = int(input())
for i in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    p.sort()
    profit = 0
    for j in range(n):
        if p[n-j-1]-j > 0:
            p[n-j-1] -= j
            profit += p[n-j-1]
    print(profit%1000000007)

# You can find the problem statement at https://www.codechef.com/APRIL20B/problems/CARSELL