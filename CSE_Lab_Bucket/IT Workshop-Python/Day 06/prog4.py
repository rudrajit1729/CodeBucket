def fact(n):
    for i in range(1,n):
        if n%i==0:
            print(i),
n=int(input("\nEnter number:"))
print("\nfactors:")
fact(n)
