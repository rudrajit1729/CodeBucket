	
def solve(A, n):
	memo = dict({})
	for i in range(n):
		x = A[i]
		if x in memo:
			memo[x] += 1
		else:
			memo[x] = 1
	
	memo_freq = {}
	for k, v in memo.items():
		if v in memo_freq:
			memo_freq[v] += 1
		else:
			memo_freq[v] = 1
	
	maxi = max(memo_freq.values())
	ans = []
	for k, v in memo_freq.items():
		if v == maxi:
			ans.append(k)
	print(min(ans))



tests = int(input())
for t in range (tests):
	n = int(input())
	A = list(map(int, input().split()))
	solve(A, n)