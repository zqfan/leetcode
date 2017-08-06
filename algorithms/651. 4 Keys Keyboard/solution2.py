class Solution(object):
    def maxA(self, N):
        """
        :type N: int
        :rtype: int
        """
        # @  xiyunyue2
        dp = [i for i in xrange(N + 1)]
        for i in xrange(7, N + 1):
            dp[i] = max(dp[i-4] * 3, dp[i-5] * 4)
        return dp[N]

# 50 / 50 test cases passed.
# Status: Accepted
# Runtime: 32 ms
