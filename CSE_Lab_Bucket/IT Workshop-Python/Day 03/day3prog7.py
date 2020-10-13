x = input("Enter number 1:")
y = input("Enter number 2:")
z = input("Enter number 3:")
try:
    x = int(x)
    y = int(y)
    z = int(z)
except:
    x = y = z = 'n'
if x is 'n':
    pass
else:
    print("Max is : ", str(max(x, y, z)))
    print("Min is : ", str(min(x, y, z)))
