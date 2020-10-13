t1=(input("Enter x1"),input("Enter y1"))
t2=(input("Enter x2"),input("Enter y2"))
def edis(t1,t2):
    d=((t1[0]-t2[0])**2+(t1[1]-t2[1])**2)**0.5
    return d
def mdis(t1,t2):
    d=abs(t1[0]-t2[0])+abs(t1[1]-t2[1])
    return d

print("Euclidean distance=",edis(t1,t2))
print("Manhattan distance=",mdis(t1,t2))
