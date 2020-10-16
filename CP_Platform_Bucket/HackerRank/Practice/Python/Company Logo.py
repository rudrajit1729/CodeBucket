"""
Submission link:
https://www.hackerrank.com/challenges/most-commons/submissions/code/180275402
"""

#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter


if __name__ == '__main__':
    s =sorted(input())
    n=Counter(s)
   #print(n)
    n=Counter(s).most_common(3)
#print(n)
for x in n:
    print(*x)
