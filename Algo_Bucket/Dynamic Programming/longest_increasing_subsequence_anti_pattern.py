# this problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. 
# This subsequence is not necessarily contiguous, or unique.
# solvable in time O(n**2)

from collections import deque

class Dp:
    def __init__(self,seq:list):
        self._seq = seq

    # Get the longest subsequence list
    def lis(self) -> list:
        n = len(self._seq)
        LIS = [1]*n
        for i in range(1, n):
            for j in range(i):
                if self._seq[j] < self._seq[i]:
                    LIS[i] = max(LIS[i], LIS[j]+1)
        return self.__restore(LIS)
            
    
    # Restoration of longest subsequence
    def __restore(self, LIS:list) -> list:
        m = max(LIS)
        index = LIS.index(m)
        RESTORE = [0]*m
        while 0 < m:
            for i in range(index, -1, -1):
                if LIS[i] == m:
                    RESTORE[m-1] = self._seq[i]
                    index = i
                    m -= 1
                    break
        return RESTORE
            

data = [19, 11, 10, 7, 8, 9, 17, 1, 20, 4, 3, 15, 16, 1, 5, 14, 6, 2, 13, 12]
l = Dp(data)
result = l.lis()
print(result) #[7, 8, 9, 17, 20]


# lis()
# data 
# [19, 11, 10, 7, 8, 9, 17, 1, 20, 4, 3, 15, 16, 1, 5, 14, 6, 2, 13, 12]
# Subsequence length
# [1, 1, 1, 1, 2, 3, 4, 1, 5, 2, 2, 4, 5, 1, 3, 4, 4, 2, 5, 5]

# restore()
# [0, 0, 0, 0, 20]
# [0, 0, 0, 17, 20]
# [0, 0, 9, 17, 20]
# [0, 8, 9, 17, 20]
# [7, 8, 9, 17, 20]
# [7, 8, 9, 17, 20]