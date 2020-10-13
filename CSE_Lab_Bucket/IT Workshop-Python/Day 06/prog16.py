n=int(input("\nenter limit"))

def fac(n):
    f=1
    for i in range(2,n+1):
        f*=i
    return f

def sum(n):
    s=0
    for i in range(1,n+1):
        s+=float((i**i)/fac(i))
    return s

print("sum=",sum(n))
