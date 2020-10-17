#Submission link:

#https://www.hackerrank.com/challenges/3d-surface-area/submissions/code/184178823

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the surfaceArea function below.
def surfaceArea(A):
    r = H*W * 2
    for i in range(H):
        for j in range(W):
            if i == 0:
                r += A[i][j]
            if j == 0:
                r += A[i][j]
            if i == H-1:
                r += A[i][j]
            if j == W-1:
                r += A[i][j]

            if j != 0:
                r += abs(A[i][j] - A[i][j-1])
            if i != 0:
                r += abs(A[i][j] - A[i-1][j])
            
    return r

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    HW = input().split()

    H = int(HW[0])

    W = int(HW[1])

    A = []

    for _ in range(H):
        A.append(list(map(int, input().rstrip().split())))

    result = surfaceArea(A)

    fptr.write(str(result) + '\n')

    fptr.close()
