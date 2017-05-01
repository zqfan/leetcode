class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in xrange(1, n + 1):
            for j in xrange(i):
                dp[i] += dp[j] * dp[i-1-j]
        return dp[n]
