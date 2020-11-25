tests = int(input())
import numpy as np

for t in range(tests):
	N, M = map(int, input().split())
	# N players rating
	rating = list(map(int, input().split()))
	pr = [[] for x in range(M)]
	prx = [[] for x in range(M)]

	for i in range(N):
		chn = list(map(int, input().split()))
		for j in range(M):
			pr[i].append(rating[i] + chn[j])
			rating[i] += chn[j]
	rows, cols = N, M
	mat = np.ndarray(pr)

	



