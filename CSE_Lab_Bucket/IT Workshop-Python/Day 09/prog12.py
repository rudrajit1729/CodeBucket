
try:
    x = int(input('Enter number'))
    if x<0:
        raise ValueError("Negative number encountered")
    y=x**0.5
    y=round(y,3)
    print("Square Root of {0} is {1}".format(x,y))
except ValueError as ve:
    print(ve)
