def add(x):
    s=0
    for i in x:
       s+=i
    return s
def sub(x,y):
    return x-y
def mul(x):
    p=1
    for i in x:
        p*=i
    return p
def div(x,y):
    if y==0:
        print("ZeroDivisionError")
    else:
        return (round(x/y,4))
def exp(x,y):
    return x**y
