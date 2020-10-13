import calculator_p2 as calc
while(1):
    c=int(raw_input("Press 1/2/3/4/5/6 to add/subtract/multi/divide/exponent/exit"))
    if c==1:
        print("enter all the numbers You wanna add")
        l=list(map(int,raw_input().split()))
        print("Sum={0}".format(calc.add(l)))
    elif c==2:
        x=float(raw_input("Enter num 1"))
        y=float(raw_input("enter num 2"))
        print("Diff={0}".format(calc.sub(x,y)))
    elif c==3:
        print("enter all the numbers You wanna multiply")
        l=list(map(int,raw_input().split()))
        print("Prod={0}".format(calc.mul(l)))
        
    elif c==4:
        x=float(raw_input("Enter num 1"))
        y=float(raw_input("enter num 2"))
        print("Div={0}".format(calc.div(x,y)))
    elif c==5:
        x=float(raw_input("Enter base"))
        y=float(raw_input("enter exponent"))
        print("Ans={0}".format(calc.exp(x,y)))
    elif c==6:
        print("Thanks")
        break
    else:
        print("Wrong input")

    
