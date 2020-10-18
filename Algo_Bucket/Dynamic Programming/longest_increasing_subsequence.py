# this problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. 
# This subsequence is not necessarily contiguous, or unique.
# solvable in time O(nlogn)

import bisect
from collections import deque

class Dp:
    def __init__(self,seq:list):
        self._seq = seq

    def lis(self) -> list:
        LIS = [self._seq[0]]
        for i in range(len(self._seq)):
            if self._seq[i] > LIS[-1]:
                LIS.append(self._seq[i])
            else:
                LIS[bisect.bisect_left(LIS, self._seq[i])] = self._seq[i]
        return self.restore(LIS)
    
    def restore(self, LIS:list) -> list:
        LIS.append(10**10)
        RESTORE = deque()
        m = len(LIS)-2
        for i in range(len(self._seq)-1, -1, -1):
            if LIS[m] <= self._seq[i] < LIS[m+1]:
                RESTORE.appendleft(self._seq[i])
                LIS[m] = self._seq[i]
                m -= 1
        return list(RESTORE)

data = [19, 11, 10, 7, 8, 9, 17, 1, 20, 4, 3, 15, 16, 1, 5, 14, 6, 2, 13, 12]
l = Dp(data)
result = l.lis()
print(result)  #[1, 3, 5, 6, 12]

# lis()
# [19]
# [11]
# [10]
# [7]
# [7, 8]
# [7, 8, 9]
# [7, 8, 9, 17]
# [1, 8, 9, 17]
# [1, 8, 9, 17, 20]
# [1, 4, 9, 17, 20]
# [1, 3, 9, 17, 20]
# [1, 3, 9, 15, 20]
# [1, 3, 9, 15, 16]
# [1, 3, 9, 15, 16]
# [1, 3, 5, 15, 16]
# [1, 3, 5, 14, 16]
# [1, 3, 5, 6, 16]
# [1, 2, 5, 6, 16]
# [1, 2, 5, 6, 13]
# [1, 2, 5, 6, 12]

# restore()
# [12]
# [12]
# [12]
# [6, 12]
# [6, 12]
# [5, 6, 12]
# [5, 6, 12]
# [5, 6, 12]
# [5, 6, 12]
# [3, 5, 6, 12]
# [3, 5, 6, 12]
# [3, 5, 6, 12]
# [1, 3, 5, 6, 12]
# [1, 3, 5, 6, 12]
# [1, 3, 5, 6, 12]
# [1, 3, 5, 6, 12]
# [1, 3, 5, 6, 12]
# [1, 3, 5, 6, 12]
# [1, 3, 5, 6, 12]
# [1, 3, 5, 6, 12]
