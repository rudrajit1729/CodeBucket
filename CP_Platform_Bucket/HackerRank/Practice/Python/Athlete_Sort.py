"""

Submission link:

https://www.hackerrank.com/challenges/python-sort-sort/submissions/code/184104295

"""

n, m = map(int, input().split())

rows = [input() for _ in range(n)]

k = int(input())

for r in sorted(rows, key=lambda r: int(r.split()[k])):
    print(r)
