f=open("myfile.txt","r")
r=f.read().split()
l=[len(x) for x in r]
print(r)
m=max(l)
print("Maximum length words:\n")
for i in r:
    if len(i)==m:
        print(i)
f.close()
