def solve(A, n):
	if A.count(1) == n:
		return "No"
	cnt = 0
	ind = []
	i = 0
	while (i < n):
		if A[i] == 0:
			cnt = 1
			j = i+1
			while (j < n and A[j] != 1):
				cnt += 1
				j+=1
				if j == n:
					break
			if cnt % 2 == 0:
				return "No"
			else:
				ind.append(cnt)
				cnt = 0
				i = j+1
		else:
			i += 1
	x = len(ind)
	flag = 0
	for i in range(x):
		if ind[i] != 1:
			flag = 1
	if flag == 0 and x!=1:
		return "No"
	else:
		return "Yes"

tests = int(input())
for t in range(tests):
	n = int(input())
	A = list(map(int, input().split()))
	print(solve(A, n))


