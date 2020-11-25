
tests = int(input())

def solve(A, n):
	ans = 0
	for i in range(n-1):
		ans += abs(A[i+1]-A[i]) - 1
	return ans

for _ in range(tests):
	n = int(input())
	A = list(map(int, input().split()))
	print(solve(A, n))

	
