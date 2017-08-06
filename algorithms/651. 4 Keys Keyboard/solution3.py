class Solution(object):
    def maxA(self, N):
        """
        :type N: int
        :rtype: int
        """
        # @ xiyunyue2
        dp = [i for i in xrange(N + 1)]
        for i in xrange(1, N + 1):
            for j in xrange(3, i):
                dp[i] = max(dp[i], dp[i-j] * (j - 1))
        return dp[N]

# 50 / 50 test cases passed.
# Status: Accepted
# Runtime: 42 ms
