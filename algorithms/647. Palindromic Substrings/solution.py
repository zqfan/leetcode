class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[0] * n for i in xrange(n)]
        count = 0
        for end in xrange(n):
            dp[end][end] = 1
            count += 1
            for start in xrange(end):
                if s[start] == s[end] and (start+1 >= end-1 or dp[start+1][end-1]):
                    count += 1
                    dp[start][end] = 1
        return count

# 130 / 130 test cases passed.
# Status: Accepted
# Runtime: 512 ms
