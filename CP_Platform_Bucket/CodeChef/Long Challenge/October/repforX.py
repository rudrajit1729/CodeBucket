tests = int(input())

for t in range(tests):
	n, x, p, k = map(int, input().split())
	a = list(map(int, input().split()))
	a.sort()
	p = p - 1
	k = k - 1
	if a[p] == x:
		res = 0
	elif p >= k and a[p] <= x:
		pos = p + 1
		while pos < n:
			if x <= a[pos]:
				break
			else:
				pos = pos + 1
		res = (pos - p)
	elif k >= p and a[p] >= x:
		pos = p - 1
		while pos > 0:
			if x >= a[pos]:
				break
			else:
				pos = pos - 1
		res = (p - pos)
	else:
		res = -1
	print(res)



	

