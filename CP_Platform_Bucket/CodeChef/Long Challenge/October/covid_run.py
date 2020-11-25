tests = int(input())

def solve(N, K, X, Y):
	visited = [X]
	flag = 0
	curr = X
	while True:
		curr = (curr+K)%N
		if curr in visited:
			break
		if curr == Y:
			flag = 1
			return "YES"
		visited.append(curr)
	if flag == 0:
		return "NO"

for t in range(tests):
	N, K, X, Y = map(int, input().split())
	if (X == Y):
		print("YES")
	else:
		print(solve(N, K, X, Y))


