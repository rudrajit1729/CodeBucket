l=[1,2,(3,4)]
c=0
for i in l:
    if "tuple" in str(type(i)):
        break
    c+=1
print(c)
