def arms(n):
    cpy=n
    x=str(n)
    l=len(x)
    s=0
    while(n >0):
        s+=(n%10)**l
        n/=10
    if cpy==s:
        print("\nArmstrong ")
    else:
        print("\nNot armstrong")
n=int(input("\nenter number"))
arms(n)
