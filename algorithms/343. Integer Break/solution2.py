class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        maxp = 1
        for i in xrange(2, n):
            m = int(round(n / float(i)))
            p = m ** (i - 1) * (n - m * (i - 1))
            maxp = max(maxp, p)
        return maxp
