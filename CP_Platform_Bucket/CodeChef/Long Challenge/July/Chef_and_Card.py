tests = int(input())

for _ in range(tests):
	n = int(input())
	SA, SB = 0, 0
	for i in range(n):
		a, b = input().split()
		X = [int(x) for x in a]
		Y = [int(y) for y in b]
		x, y = sum(X), sum(Y)
		if x > y:
			SA += 1
		elif x < y:
			SB += 1
		else:
			SA += 1
			SB += 1

	if SA == SB :
		print("{} {}".format(2, SA))
	elif SA > SB:
		print("{} {}".format(0, SA))
	else:
		print("{} {}".format(1, SB))
		


	
