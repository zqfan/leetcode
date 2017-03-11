class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        # based on @jedihy
        dp = [1] * len(s)
        for end in xrange(len(s)):
            for start in reversed(xrange(end)):
                if s[start] == s[end]:
                    m = 2 + pre if start < end - 1 else 2
                else:
                    m = max(dp[start+1], dp[start])
                pre, dp[start] = dp[start], m
        return dp[0] if dp else 0
