try:
    x = input("Enter 1st number:")
    y = input("Enter 2nd number:")
except:
    print("Wrong input")
if x == y:
    print("Equal")
elif x > y:
    print("Number 2 < Number 1")
else:
    print("Number 2 > Number 1")
