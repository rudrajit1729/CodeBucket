def rev(x):
    x = x[::-1]
    print(x)

def rev_rec(x):
        if(len(x)>1):
            rev_rec(x[1:])
        print(x[0]),
	
x = raw_input()
rev(x)
rev_rec(x)
