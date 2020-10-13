spnos=[i for i in range(1,5)]
sales=list()
colsum=[0 for x in range (4)]

for no in range(5):
	xlist=list()
	c=0
	xlist.append("Product{0}".format(no+1))
	xlist.extend(list(map(int,input("Enter sales per salesman for product"+str(no+1)+":\n").split())))
	for slsman in xlist[1:]:
		colsum[c]+=slsman
		c+=1
	xlist.append(sum(xlist[1:]))
	sales.append(xlist)
        print("Salesperson no \t") 
        for no in spnos:
                print(str(no)+"\t",end="")
print("total")
c=0
