import math

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        flags = [1] * n
        for i in range(2, int(math.sqrt(n)) + 1):
            if flags[i] == 0:
                continue
            j = i
            while j + i < n:
                j += i
                flags[j] = 0
        return sum(flags) - 2

# test
s = Solution().countPrimes
print s(499979)
