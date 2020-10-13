def comp(n):
    for i in range(2,n):
        if n%i==0:
            return True
    return False
a={x for x in range(1,11) if x%2==0}
b=[x for x in range(1,21)]
b=set(list((filter(comp,b))))
#print(a)
#print(b)
#a even no set b comp no set
a.add(0)
print(a)
print(a.issuperset(b))
print(len(a))
