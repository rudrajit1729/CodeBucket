def f1(x,y):
    if y<=x:
        return f1(x-y,y)+1
    return 1

def f2(n,r):
    if n>0 or r>0:
        return (f2(n-1,r)+f2(n-1,r-1))
    else:
        return 0
def f3(n):
    if n>1:
        return f3(n/2)+1
    return 0
def f4(m,n):
    if m==0 or (m>=n and n>=1):
        return 1
    else:
        return f4(m-1,n)+f4(m-1,n-1)
def fact(n):
    p=1
    for i in range(1,n+1):
        p*=i
    return p
def f5(m,x):
    if x==0:
        return 1
    if m>x:
        return (fact(m)/(fact(x)*fact(m-x)))
    else:
        return (f5(m,x-1)*((m-x+1)/x))
        
    
