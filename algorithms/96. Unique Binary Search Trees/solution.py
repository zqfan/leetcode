class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # catalan number = (2n)!/(n!*(n+1)!)
        return math.factorial(2 * n) / math.factorial(n) / math.factorial(n + 1)
