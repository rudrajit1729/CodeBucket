def maximum(x, y, z):
    if x>y and x>z:
        print("Max: ", x)
    if y>x and y>z:
        print("Max: ", y)
    if z>y and z>x:
        print("Max: ", z)

def minimum(x, y, z):
    if x<y and x<z:
        print("Min: ", x)
    if y<x and y<z:
        print("Min: ", y)
    if z<y and z<x:
        print("Min: ", z)

x = input("Enter x:")
y = input("Enter y:")
z = input("Enter z:")

maximum(x, y, z)
minimum(x, y, z)
