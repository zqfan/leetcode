class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n, m, f, s = len(A), 0, 0, sum(A)
        for i in xrange(n):
            m = f = f + i * A[i]
        for i in reversed(A):
            f = f + s - n * i
            m = max(m, f)
        return m
