class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        l1 = len(s1)
        l2 = len(s2)
        dp = [[0] * (l2 + 1) for i in xrange(l1 + 1)]
        for i in xrange(l1):
            for j in xrange(l2):
                if s1[i] == s2[j]:
                    dp[i+1][j+1] = dp[i][j] + ord(s1[i]) * 2
                else:
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
        n1 = sum(ord(c) for c in s1)
        n2 = sum(ord(c) for c in s2)
        return n1 + n2 - dp[l1][l2]

# 94 / 94 test cases passed.
# Status: Accepted
# Runtime: 1259 ms
