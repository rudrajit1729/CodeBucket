# this problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. 
# This subsequence is not necessarily contiguous, or unique.
# solvable in time O(n**2)

from collections import deque

class Dp:
    def __init__(self,seq:list):
        self._seq = seq

    # Get the longest subsequence element
    def lis(self) -> list:
        n = len(self._seq)
        LIS = [1]*n
        for i in range(1, n):
            for j in range(i):
                if self._seq[j] < self._seq[i]:
                    LIS[i] = max(LIS[i], LIS[j]+1)
        return self.restore(LIS)
            
    
    # Restoration of longest subsequence
    def restore(self, LIS:list) -> list:
        RESTORE = deque()
        m = len(LIS)-2
        for i in range(len(self._seq)-1, -1, -1):
            if LIS[m] <= self._seq[i] < LIS[m+1]:
                RESTORE.appendleft(self._seq[i])
                # Update longest common subsequence element
                LIS[m] = self._seq[i]
                m -= 1
        return list(RESTORE)

data = [19, 11, 10, 7, 8, 9, 17, 1, 20, 4, 3, 15, 16, 1, 5, 14, 6, 2, 13, 12]
l = Dp(data)
result = l.lis()
print(result)