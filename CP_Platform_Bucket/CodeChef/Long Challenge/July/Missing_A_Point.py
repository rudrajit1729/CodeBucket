tests = int(input())

for _ in range(tests):
	n = int(input())
	X, Y = {}, {}
	lim = 4*n-1
	for i in range(lim):
		x, y = map(int, input().split())
		if x in X:
			X[x] += 1
		else:
			X[x] = 1
		if y in Y:
			Y[y] += 1
		else:
			Y[y] = 1
	x, y = 0, 0
	for i in X:
		if X[i] % 2 != 0:
			x = i
			break
	for i in Y:
		if Y[i] % 2 != 0:
			y = i
			break

	print(x, y)
