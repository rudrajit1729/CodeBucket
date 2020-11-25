
P = []
# Fastest prime generation
def rwh_primes(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]
P = rwh_primes(1300000)

tests = int(input())

for t in range(tests):
	N = int(input())
	A = list(map(int, input().split()))
	B = []
	for i in A:
		B.append(P[i-1])
	for i in B:
		print(i, end = " ")
	print()

