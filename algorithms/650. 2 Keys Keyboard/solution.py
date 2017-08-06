class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        s, f = 0, 2
        while f <= n:
            while n % f == 0:
                s += f
                n /= f
            f += 1
        return s

# 126 / 126 test cases passed.
# Status: Accepted
# Runtime: 42 ms
# beats 66.22 %
