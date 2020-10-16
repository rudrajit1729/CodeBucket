"""
Submission link:
https://www.hackerrank.com/challenges/compress-the-string/submissions/code/180244287
"""

from itertools import groupby
print(*[(len(list(a)), int(n)) for n, a in groupby(input())])
