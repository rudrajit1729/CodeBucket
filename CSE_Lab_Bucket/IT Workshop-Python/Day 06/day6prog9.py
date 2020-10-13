c = input("Enter choice")
def add():
    x = input()
    y = input()
    print(x + y)
def sub():
    x = input()
    y = input()
    print(x - y)
def mul():
    x = input()
    y = input()
    print(x * y)
def div():
    x = input()
    y = input()
    print(x / y)
def exp():
    x = input()
    y = input()
    print(x ** y)

if c == 1:
    add()
elif c == 2:
    sub()
elif c == 3:
    mul()
elif c == 4:
    div()
elif c == 5:
    exp()
else:
    print("Wrong choice")
