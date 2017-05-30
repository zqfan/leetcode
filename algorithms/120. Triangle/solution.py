class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        n = len(triangle)
        dp = triangle[-1][:]
        for i in xrange(n-2, -1, -1):
            for j in xrange(i+1):
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1])
        return dp[0]
