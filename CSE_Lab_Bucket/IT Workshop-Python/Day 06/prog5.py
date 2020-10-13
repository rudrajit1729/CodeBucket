def fib(n):
    if n<=1:
        return n
    return fib(n-1)+fib(n-2)

def fib_iter(n):
    a=0
    b=1
    print(a),
    print(b),
    while(n-2):
        c=a+b
        a=b
        b=c
        print(c),
        n=n-1
        
for i in range(9):
        print(fib(i)),
print()
print(fib_iter(9))
