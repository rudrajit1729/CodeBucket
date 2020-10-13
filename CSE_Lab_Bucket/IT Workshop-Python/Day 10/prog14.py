from random import randint as r
dice={1:0,2:0,3:0,4:0,5:0,6:0}
for i in range(6000):
    c=r(1,6)
    dice[c]=dice[c]+1
print("Number  Frequency")
for k,v in dice.items():
    print("{0}         {1}".format(k,v))
