def linear(x, y):
    for i in range(len(x)):
        if x[i] == y:
            print("Found at position " + str(i))
            return
    print("Not found")

def binary(x, y):
    l = 0
    u = len(x)
    while(l < u):
        mid = (l + u) / 2
        if y == x[mid]:
            print("Found")
            return
        elif y > x[mid]:
            l = mid + 1
        elif y < x[mid]:
            u = mid - 1
    print("Not Found")

x = list(map(int, raw_input("Enter elements with spaces:").split()))
y = input("Enter element to search:")
c = input("1. Linear Search \n2. Binary search")
if c == 1:
    linear(x, y)
if c == 2:
    x.sort()
    binary(x, y)
