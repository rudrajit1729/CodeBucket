# cook your dish here

tests = int(input())

def solve(k):
	k -= 1
	for i in range(8):
		for j in range(8):
			if i == 0 and j == 0:
				print("O", end = "")
			else:
				if k > 0:
					print(".", end = "")
					k -= 1
				else:
					print("X", end = "")
		print()


for _ in range(tests):
	k = int(input())
	solve(k)

