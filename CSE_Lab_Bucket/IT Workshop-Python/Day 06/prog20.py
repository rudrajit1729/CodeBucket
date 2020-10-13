def prime(n):
    for i in range(2,n-1):
        if n%i==0:
            print("\nComposite number")
    print("\nPrime number")
n=int(input("\nenter number"))
prime(n)
