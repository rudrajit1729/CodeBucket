f1=open("myfile.txt","r")
f2=open("myfile2.txt","r")
r1=f1.read()
r2=f2.read()
if r1==r2:
    print("Same content")
else:
    print("Different Content")

f1.close()
f2.close()

