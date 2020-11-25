tests = int(input())

def solve(A, n):
	if(n == 1):
		return A[0]
	A.sort(reverse = True)
	x, y = A[0], A[1]
	for d in range(2, n):
		if y <= x:
			y+= A[d]
		else:
			x+= A[d]
	return max(x, y)



for t in range(tests):
	n = int(input())
	A = list(map(int, input().split()))
	print(solve(A, n))


