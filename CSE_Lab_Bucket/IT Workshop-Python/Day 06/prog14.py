def fac(n):
    f=1
    for i in range(2,n+1):
        f*=i
    return f

def permu(n,r):
    return (fac(n)/fac(n-r))

n=int(input("\nEnter n:"))
r=int(input("\nEnter r:"))
print("P(n,r)",permu(n,r))
