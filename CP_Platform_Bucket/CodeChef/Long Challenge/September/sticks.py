tests = int(input())

for t in range(tests):
	n = int(input())
	A = list(map(int, input().split()))
	A = list(set(A))
	if A[0] == 0:
		print(len(A) - 1)
	else:
		print(len(A))








