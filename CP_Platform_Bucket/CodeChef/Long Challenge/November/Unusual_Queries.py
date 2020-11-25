N, Q, s = map(int, input().split())
ans = 0
H = list(map(int, input().split()))


def solve(A):
	m = 0
	ans = 0
	for i in A:
		if i > m:
			m = i
			ans += 1
	return ans

for q in range(Q):
	x, y = map(int, input().split())
	L = (x + s * ans - 1)%(N + 1)
	R = (y + s * ans - 1)%(N + 1)
	if L > R:
		L, R = R, L
	print(H[L:R+1])
	ans = solve(H[L:R+1])
	print(ans)


