x=list(map(int,input("Enter with spaces").split()))
for i in x:
    print("{0:>3}\t{1}".format(i,"*"*i))
