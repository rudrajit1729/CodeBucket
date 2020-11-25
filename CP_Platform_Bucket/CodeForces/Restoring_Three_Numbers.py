ip = list(map(int, input().split()))
ip.sort()
p,q,r,s = ip
a,b,c = s-p,s-q,s-r
print(a,b,c)