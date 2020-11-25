tests = int(input())
for t in range(tests):
	n, k = map(int, input().split())
	Q = list(map(int, input().split()))
	s = sum(Q)
	ans = s // k
	print(ans+1)