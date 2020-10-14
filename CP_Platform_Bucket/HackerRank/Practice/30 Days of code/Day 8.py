n=int(input())
d={}
for i in range(n):
    a,b=input().split()
    d[a]=b
while True:
    try:
        name=input()
        if name in d:
            print('%s=%s' %(name,d[name]))
        else:
            print('Not found')
    except:
        break
