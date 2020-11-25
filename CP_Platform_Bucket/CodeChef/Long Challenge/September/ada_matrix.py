tests = int(input())
for t in range(tests):
	n = int(input())
	count = 0
	mat = []
	for i in range(n):
		A = list(map(int, input().split()))
		mat.append(A)

	for i in range(n-1, 0, -1):
		d = mat[i][i-1]+1
		if d != mat[i][i]:
			count += 1
			x = i+1
			for a in range(x):
				for b in range(a, x):
					mat[a][b], mat[b][a] = mat[b][a], mat[a][b]
	print(count)