import calendar
yy=int(raw_input("Enter year:"))
bln=calendar.isleap(yy)
if bln:
    print("Leap Year")
else:
    print("Not a leap Year")
print("enter range:")
y1,y2=raw_input().split()
y1=int(y1)
y2=int(y2)
print("Leap years in given range:")
c=0
for i in range(y1,y2+1):
    if calendar.isleap(i):
        print(i)
        c+=1
print("Total leap years:{0}".format(c))
