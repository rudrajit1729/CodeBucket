m,n,p,q=list(map(int,raw_input("Enter dimensions of mat separate by comma:").split(",")))
print(m,n,p,q)
if n!=p:
    print("Not possible")
    exit()
print("enter elements of mat1")
mat1=[[int(input()) for i in range(n)] for i in range (m)]

print("enter elements of mat2")
mat2=[[int(input()) for i in range(q)] for i in range(p)]
mat3=[[0 for x in range(q)]for i in range(m)]
for i in range(len(mat1)):
    for j in range(len(mat2[0])):
        for k in range (len(mat2)):
            mat3[i][j]+=mat1[i][k]*mat2[k][j]
    
print(mat3)

    
