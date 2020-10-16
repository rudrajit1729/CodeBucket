"""
Submission link:
https://www.hackerrank.com/challenges/merge-the-tools/submissions/code/177683494
"""

def merge_the_tools(string, k):
    l=[]
    m=0
    for i in range(len(string)//k):
        l.append(string[m:m+k])
        m+=k
    for v in l:
      print(''.join(list(dict.fromkeys(list(v)).keys()))) 

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
