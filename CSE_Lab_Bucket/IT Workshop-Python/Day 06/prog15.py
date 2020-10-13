def fac(n):
    f=1
    for i in range(2,n+1):
        f*=i
    return f

def comb(n,r):
    return (fac(n)/(fac(n-r)*fac(r)))

n=int(input("\nEnter n:"))
r=int(input("\nEnter r:"))
print("C(n,r)",comb(n,r))
