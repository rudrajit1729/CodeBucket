m,n=int(input("Enter Row:")),int(input("Enter column:"))
l1=[[int(input("Enter element")) for x in range (n)] for x in range(m)]
l2=[[int(input("Enter element")) for x in range (n)] for x in range(m)]
l3=[[0 for x in range(n)] for x in range(m)]
for i in range (m):
	for j in range(n):
		l3[i][j]=l1[i][j]+l2[i][j]
for i in range(m):
	for j in range(n):
		print(l[i][j]+"\t")
	print()