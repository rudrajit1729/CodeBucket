import math
import os
import random
import re
import sys

# Complete the solve function below.
mc=input()
mc=float(mc)
tip=int(input())
tax=int(input())

t=mc*(tip/100)
t1=mc*(tax/100)

total=mc+t+t1
print(int(round(total,0)))
