d1={'a':1,'b':2,'c':3}
d2={}
print(d1)
for key in d1:
    d2[d1[key]]=key
print(d2)
