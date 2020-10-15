"""
Submission Link :-

https://www.hackerrank.com/challenges/maximize-it/submissions/code/175617858
"""


# Enter your code here. Read input from STDIN. Print output to STDOUT
K, M = [int(x) for x in input().split()]
arrayN = []
for _i_ in range(K):
    arrayN.append([int(x) for x in input().split()][1:])
    
from itertools import product
possible_combination = list(product(*arrayN))

def func(nums):
    return sum(x*x for x in nums) % M

print(max(list(map(func, possible_combination))))
