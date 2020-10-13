s = 0
try:
    x = int(input("Enter a number:"))
except:
    x = 'n'
if x is 'n':
    print("Invalid input")
else:
    x = str(x)
    length = len(x)
    for i in x:
        s += int(i) ** length
    if s == int(x):
        print("Armstrong")
    else:
        print("Not armstrong")
        
