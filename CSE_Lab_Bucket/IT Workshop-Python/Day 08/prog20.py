d = {}
key = []
value = []
for i in range(10):
    x, y = raw_input('Enter Products purchased and price separated by space:').split()
    key.append(x)
    value.append(y)
d = dict(zip(key, value))
print(sum(d.values()))
