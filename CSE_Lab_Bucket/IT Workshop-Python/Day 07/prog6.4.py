x=list(map(int,raw_input("Enter with spaces").split()))
y=list(set(x))
c=[]
for i in range(len(y)):
    c.append(x.count(y[i]))
    print((y[i],c[i]))
