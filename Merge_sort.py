from random import randint

def generate(n = 10, max = 50):
    l = []
    while(n>0):
        l.append(randint(0, max))
        n -= 1
    return l

def print_array(A):
    for i in A:
        print(i, end = "\t")
    print("\n")

def merge(A, lb, mid, ub):
    i, j = lb, mid+1
    temp = []
    while(i<=mid and j<=ub):
        if A[i]<A[j]:
            temp.append(A[i])
            i += 1
        else:
            temp.append(A[j])
            j += 1
    while i <= mid:
        temp.append(A[i])
        i += 1
    while j <= ub:
        temp.append(A[j])
        j += 1
    
    k = 0
    for i in range(lb, ub+1):
        A[i] = temp[k]
        k += 1
 
def split(A, lb, ub):
    if (lb<ub):
        mid = (lb + ub) // 2
        split(A, lb, mid)
        split(A, mid+1, ub)
        merge(A, lb, mid, ub)


def main():
    A = generate()
    print("Original Array:\n")
    print_array(A)
    split(A, 0, len(A) - 1)
    print("Sorted Array:\n")
    print_array(A)

if __name__ == "__main__":
    main()

