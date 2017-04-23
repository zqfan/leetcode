class Solution(object):
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        n, m, ll = len(M), len(M[0]) if M else 0, 0
        dp = [[[0, 0, 0 ,0] for j in xrange(m + 2)] for i in xrange(2)]
        for i in xrange(n):
            for j in xrange(m):
                if M[i][j] == 1:
                    dp[1][j+1][0] = dp[1][j][0] + 1
                    dp[1][j+1][1] = dp[0][j][1] + 1
                    dp[1][j+1][2] = dp[0][j+1][2] + 1
                    dp[1][j+1][3] = dp[0][j+2][3] + 1
                    ll = max(ll, max(dp[1][j+1]))
            dp[0], dp[1] = dp[1], dp[0]
            for j in xrange(1, m + 1):
                dp[1][j][:] = [0] * 4
        return ll
