"""
Submission link:
https://www.hackerrank.com/challenges/word-order/submissions/code/179777143
"""

import collections

N = int(input())
d = collections.OrderedDict()

for i in range(N):
    word = input()
    if word in d:
        d[word] +=1
    else:
        d[word] = 1

print(len(d));

for k,v in d.items():
    print(v,end = " ")
