tests = int(input())

def solve(S, N, K):
	p, cnt = K + 1, 0
	mag = []
	iron = []
	for i in range(N):
		if (S[i] == "M"):
			mag.append(i)
		if (S[i] == "I"):
			iron.append(i)
		if(S[i] == "X" or i == N-1):
			c = 0
			while(len(mag) and len(iron)):
				l = min(mag[0], iron[0])
				r = max(mag[0], iron[0])
				c = S[l:r].count(":")
				if ((p - abs(l-r) - c) > 0):
					cnt += 1
					mag = mag[1:]
					iron = iron[1:]
				elif (mag[0] < iron[0]):
					mag = mag[1:]
				else:
					iron = iron[1:]
			mag = []
			iron = []
	return cnt

for t in range(tests):
	N, K = map(int, input().split())
	S = input()
	print(solve(S, N, K))






