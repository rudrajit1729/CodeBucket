try:
    x = input("Enter a number : ")
except:
    x = 'n'
if x is 'n':
    pass
elif x%2 == 0:
    print("Even")
else:
    print("Odd")
