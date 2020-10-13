import module_fun as mf

while(1):
    print("Press i to access function number i(eg:-1 for fun1)\nPress 6 to exit")
    c=int(input())
    if c==1:
        print("Enter x and y:")
        x,y=input().split()
        x=int(x)
        y=int(y)
        print("Result=",mf.f1(x,y))
    elif c==2:
        print("Enter n and r:")
        n,r=input().split()
        n=int(n)
        r=int(r)
        print("Result=",mf.f2(n,r))
    elif c==3:
        n=int(input("Enter n:"))
        print("Result=",mf.f3(n))
    elif c==4:
        print("Enter m and n")
        m,n=input().split()
        m=int(m)
        n=int(n)
        print("Result=",mf.f4(m,n))
    elif c==5:
        print("Enter m and x")
        m,x=input().split()
        m=int(m)
        x=int(n)
        print("Result=",mf.f5(m,x))
    elif c==6:
        print("Thanks")
        break
    else:
        print("Wrong input")
        
