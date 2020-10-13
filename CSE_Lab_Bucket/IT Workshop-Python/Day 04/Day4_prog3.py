for i in range(1,1001):
    x=str(i)
    s=0
    l=len(x)
    for j in x:
        s+=int(j)**l
    if s==i:
        print(i)
