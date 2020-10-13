i,total,avg=0,0,0
x=input("Enter:")
maxi=x
mini=x
while 1:
    try:
        x=input("Enter:")
    except:
        print("wrong Input")
        continue
    if x=='done':
        break
    if x>maxi:
        maxi=x
    if x<mini:
        mini=x
    total+=x
    i+=1
avg=float(total/i)

print("total=",total)
print("Number of terms=",i)
print("avg=",avg)
print("max=",maxi,"min=",mini)

