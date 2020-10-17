#Submission link:

#https://www.hackerrank.com/challenges/encryption/submissions/code/184169346

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the encryption function below.
def encryption(s):
    l = len(s)
    row = int(math.floor(l**(0.5)))
    column = int(math.ceil(l**(0.5)))
    output = ""
    for i in range(column):
        k = i
        for j in range(k,l,column):
            output+=s[j]
        output+=" "
    return output

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = encryption(s)

    fptr.write(result + '\n')

    fptr.close()
