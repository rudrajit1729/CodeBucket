f=open("myfile.txt","w")
f.write("Hi!!!\nI am Rudy!!!\nWelcome to the programming screencast\n")
f.close()
f=open("myfile.txt","r")
print(f.read())
f.seek(0)
print(f.readlines()[:2])
f.seek(0)
print(f.read(5))
f.seek(0)
l=len(f.readlines())
f.seek(0)
print("\n")
for i in range(l):
    print(f.readline()),

f.close()
