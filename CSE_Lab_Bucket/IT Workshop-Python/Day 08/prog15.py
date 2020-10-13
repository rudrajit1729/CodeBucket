#bprint={'row':0,'col':0,'value'=0}
smat={}
r=int(input("enter rows:"))
c=int(input("enter columns:"))
print("enter elements:")
mat=[[int(input()) for x in range(c)] for x in range(r)]
k=0
smat[0]=[r,c,0]
for i in range(r):
    for j in range(c):
        if mat[i][j]!=0:
            val=mat[i][j]
            k+=1
            smat[k]=[i,j,mat[i][j]]
            print(smat)
for i in smat.values():
    for j in i:
        print(j),
    print("\n")
        
