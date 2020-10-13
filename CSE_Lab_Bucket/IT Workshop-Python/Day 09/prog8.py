f=open("myfile.txt","r")
r=f.readlines()
print("No. of lines={0}".format(len(r)))

f.close()
