import math

def Log2(x):
	if x == 0:
		return False
	return (math.log10(x)/math.log10(2))

def isPowerOfTwo(n):
	return (math.ceil(Log2(n)) == math.floor(Log2(n)))

tests = int(input())

def solve(n):
	ans = [2, 3, 1]
	if n == 3:
		return ans
	i = 4
	while(i <= n):
		if isPowerOfTwo(i):
			ans.append(i+1)
			ans.append(i)
			i += 2
		else:
			ans.append(i)
			i += 1
	return ans

for t in range(tests):
	n = int(input())
	if n == 1:
		print(1)
	elif isPowerOfTwo(n):
		print(-1)
	else:
		ans = solve(n)
		for i in ans:
			print(i, end = " ")
		print()



