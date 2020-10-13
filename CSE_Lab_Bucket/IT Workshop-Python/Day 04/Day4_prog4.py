n=1
while n<1000:
    flag=1
    for i in range (2,n):
        if n%i==0:
            flag=0
    if flag==1:
        print(n)
    n+=1
