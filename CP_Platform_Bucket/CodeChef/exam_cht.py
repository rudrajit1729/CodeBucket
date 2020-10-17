# cook your dish here

t = int(input())
for i in range(t):
    a, b = list(map(int, input().split()))
    n = abs(a - b)
    result = []
    j = 1
    while j*j <= n:
        if n % j == 0:
            result.append(j)
            if n//j != j:
                result.append(n//j)
        j += 1
    print(len(result))

# You can find the problem statement at https://www.codechef.com/COOK114B/problems/EXAMCHT