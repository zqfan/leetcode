class Solution(object):
    def findDerangement(self, n):
        """
        :type n: int
        :rtype: int
        """
        # f(n, 0) = (n - 1) * f(n - 1, 0) + f(n - 1, 1)
        # f(n, 1) = n * f(n - 1, 0)
        f1, f2 = 1, 0
        for i in xrange(3, n + 1):
            f1, f2 = (i - 1) * (f1 + f2) % 1000000007, f1
        return f1 if n > 1 else 0

# 69 / 69 test cases passed.
# Status: Accepted
# Runtime: 246 ms
