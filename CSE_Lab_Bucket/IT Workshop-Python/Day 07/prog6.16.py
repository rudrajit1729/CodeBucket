m,n=list(map(int,raw_input("Enter dimensions of mat separate by comma:").split(",")))
print("enter elements of mat1")
mat1=[[int(input()) for i in range(n)] for i in range (m)]

mat2=[[0 for x in range(m)] for x in range(n)]
for i in range (m):
    for j in range (n):
        mat2[i][j]=mat1[j][i]

print(mat2)
        
