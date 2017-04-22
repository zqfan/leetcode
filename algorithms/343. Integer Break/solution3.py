class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        maxp = [1] * (n + 1)
        for i in xrange(3, n + 1):
            for j in xrange(1, i/2 + 1):
                a = j * (i - j)
                b = j * maxp[i - j]
                c = maxp[j] * (i - j)
                d = maxp[j] * maxp[i - j]
                maxp[i] = max(maxp[i], a, b, c, d)
        return maxp[n]

# 50 / 50 test cases passed.
# Status: Accepted
# Runtime: 49 ms
# beats 43.77%
