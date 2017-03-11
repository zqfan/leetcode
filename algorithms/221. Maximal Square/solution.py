class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        r = len(matrix); c = len(matrix[0])
        dp = [[0] * (c+1) for i in xrange(r+1)]
        maxsize = 0
        for i in xrange(r):
            for j in xrange(c):
                if matrix[i][j] == '0':
                    dp[i+1][j+1] = 0
                else:
                    minsize = min(dp[i][j], dp[i][j+1], dp[i+1][j])
                    dp[i+1][j+1] = int((minsize**0.5+1)**2)
                    maxsize = max(maxsize, dp[i+1][j+1])
        return maxsize
