d = {}
for i in range(3):
    x = raw_input('Enter name:')
    y = raw_input('Enter DOB:')
    d[x] = y
x = raw_input('Enter name to search:')
if x in d:
    print('Found')
else:
    y = raw_input('Enter DOB:')
    d[x] = y
print d
