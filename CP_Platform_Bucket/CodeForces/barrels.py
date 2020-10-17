t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    s = 0
    for j in range(k+1):
        s += a[j]
    print(s)

# You can find the problem statement at https://codeforces.com/contest/1430/problem/B