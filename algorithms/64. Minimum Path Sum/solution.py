class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        dp = [grid[0][0]] * n
        for i in xrange(1, n):
            dp[i] = grid[0][i] + dp[i-1]
        for i in xrange(1, m):
            dp[0] += grid[i][0]
            for j in xrange(1, n):
                dp[j] = grid[i][j] + min(dp[j-1], dp[j])
        return dp[n-1]
