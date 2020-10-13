def p1(row, char):
    for i in range(1, row+1):
        for j in range(i):
            print(char+""),
        print("\n")

def p2(row, char):
    for i in range(1, row+1):
        for k in range(row-i):
            print(""),
        for j in range(i):
            print(char+""),
        print("\n")

def p3(row):
    for i in range(1, row+1):
        c = 1
        for j in range(i):
            print(str(c)+""),
            c += 1
        print("\n")

def p4(row):
    c = 1
    for i in range(1, row+1):
        for j in range(i):
            print(str(c)+""),
            c += 1
        print("\n")
