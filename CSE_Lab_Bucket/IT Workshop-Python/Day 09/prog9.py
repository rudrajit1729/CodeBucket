f=open("myfile.txt","r")
tot=0
r=f.readlines()
for i in r:
    x=i.split()
    tot+=len(x)

print("Total no. of words={0}".format(tot))
f.close()
