class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[0] * n for i in xrange(n + 1)]
        for i in xrange(n):
            dp[i][i] = 1
        for l in xrange(1, n):
            for i in xrange(n-l):
                e = i + l
                dp[i][e] = dp[i+1][e] + 1
                for j in xrange(i+1, e+1):
                    if s[i] == s[j] and dp[i][j-1] + dp[j+1][e] < dp[i][e]:
                        dp[i][e] = dp[i][j-1] + dp[j+1][e]
        return dp[0][-1] if s else 0

# 201 / 201 test cases passed.
# Status: Accepted
# Runtime: 852 ms
