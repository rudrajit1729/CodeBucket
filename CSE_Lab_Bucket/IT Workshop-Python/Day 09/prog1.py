try:
    x=int(raw_input("Enter num1"))
    y=int(raw_input("Enter num2"))
    div=x/y
    print(div)
except :
    if y==0:
        print("Zero division error")
    else:
        print("Wrong Input")
