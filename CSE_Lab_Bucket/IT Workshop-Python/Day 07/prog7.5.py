t=tuple(input("Enter elements"))
x=input("Enter element to search for")
print("Using no parameters")
try:
    print("Found at index {0}".format(t.index(x)))
except:
    print("Not Found")
print("Using 2 parameters")
try:
    print("Found at index {0}".format(t.index(x,2,4)))
except:
    print("Not Found")
print("Using one parameters")
try:
    print("Found at index {0}".foramt(t.index(x,3)))
except:
    print("Not Found")
