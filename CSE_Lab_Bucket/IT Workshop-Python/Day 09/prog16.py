f1=open("myfile3.txt","w")
f2=open("myfile2.txt","r")
f1.write("Case Swapped:\n")
'''
#long way
while(1):
    c=f2.read(1)
    if not c:
        f1.write("\n")
        break
    f1.write(c.swapcase())
f1.close()
f1=open("myfile3.txt","r")
print(f1.read())
f1.close()
'''

r=f2.read().swapcase()
f1.write(r)
f1.close()
f1=open("myfile3.txt","r")
print(f1.read())
f1.close()
