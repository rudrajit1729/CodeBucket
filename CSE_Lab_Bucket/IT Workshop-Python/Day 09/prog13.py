import math
try:
    x=int(raw_input("enter the number"))
    y=x**2
    print("Square of {0} is {1}".format(x,y))
except:
    print("Not a number")
