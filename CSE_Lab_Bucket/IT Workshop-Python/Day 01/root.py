print("Input a, b, c in 'ax^2 + bx + c:'")
a = input("Enter a:")
b = input("Enter b:")
c = input("Enter c:")
d = b*b - 4*a*c
if (d > 0):
    print("Root 1: ", ((- b - (d ** 0.5))/(2*a)))
    print("Root 2: ", ((- b + (d ** 0.5))/(2*a)))
elif(d == 0):
    print("Root:", (-b / (2*a)))
else:
    import cmath
    d = cmath.sqrt(d)
    root1 = (((- b - d)/(2*a)))
    root2 = (((- b + d)/(2*a)))
    print("Imaginary Root 1: ", root1)
    print("Imaginary Root 2: ", root2)
