from random import randint
def generate(n = 10, max = 50):
    l = []
    while(n>0):
        l.append(randint(0, max))
        n -= 1
    return l

def insertion_sort(A, n):
    for i in range(1, n):
        d = i
        while(d>0):
            if A[d]<A[d-1]:
                A[d], A[d-1] = A[d-1], A[d]
            d -= 1
    return A

def print_array(A):
    for i in A:
        print(i, end = "\t")
    print("\n")

def main():
    A = generate()
    print("Original Array:\n")
    print_array(A)
    A = insertion_sort(A, len(A))
    print("Sorted Array:\n")
    print_array(A)

if __name__ == "__main__":
    main()
