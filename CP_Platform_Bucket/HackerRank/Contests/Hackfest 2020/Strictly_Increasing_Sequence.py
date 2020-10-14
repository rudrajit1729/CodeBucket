#!/bin/python3

import math
import os
import random
import re
import sys

def whoIsTheWinner(arr,n):
    arr.sort()
    for i in range(0,n-1):
        if(arr[i]==arr[i+1]):
            if(n%2==0):
                return "Second"
            else:
                return "First"
    return "First"
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = whoIsTheWinner(arr,n)

        fptr.write(result + '\n')

    fptr.close()
