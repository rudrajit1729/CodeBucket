d = {}
d2 = {}
for i in range(3):
    x = raw_input('Enter name:')
    y = raw_input('Enter ID:')
    z = list(map(str, raw_input('Enter products sold:').split()))
    d['name'] = x
    d['ID'] = y
    d['Products'] = z
    d2[i+1] = d
print(d2)
