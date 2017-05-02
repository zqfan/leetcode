class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        return math.factorial(n+m-2) / math.factorial(n-1) / math.factorial(m-1)
