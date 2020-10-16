n=int(input())
if(n%2 != 0):
    print("Weird")
else:
    if(n==2 or n==4 or n>20):
        print("Not Weird")
    else:
        print("Weird")
