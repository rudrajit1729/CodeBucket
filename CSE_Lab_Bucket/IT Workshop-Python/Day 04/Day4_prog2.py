n=int(input('Enter the number:'))
flag=1
for i in range (2,n):
    if n%i==0:
        print("Composite Number")
        flag=0
        break
if flag==1:
    print("Prime Number")
