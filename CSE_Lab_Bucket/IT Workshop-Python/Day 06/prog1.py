def fact_recursive(n):
    if n>0:
        return n*fact_recursive(n-1)
    return 1
def fact_iterative(n):
    s=1
    while n>0:
        s*=n
        n-=1
    return s
a=fact_recursive(5)
b=fact_iterative(4)
print("Factorial of 5=%d",a)
print("Factorial of 4=%d",b)
