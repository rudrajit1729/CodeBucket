i,total,avg=0,0,0
a=[]
while 1:
    try:
        x=input("Enter:")
    except:
        print("Wrong input")
        continue
    
    if x=='done':
        break
    a.append(x)
for i in a:
    print(i)
print('No more items')
