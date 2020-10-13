d = {}
for i in range(3):
    x = raw_input('Enter name:')
    y = int(raw_input('Enter price:'))
    d[x] = y
print('Menu\n')
print d
bill = 0

try:
    x = raw_input('Order:')
except:
    x = raw_input('Order again:')
finally:
    indexx = d.keys().index(x)
    bill += d.values()[indexx]
print bill
