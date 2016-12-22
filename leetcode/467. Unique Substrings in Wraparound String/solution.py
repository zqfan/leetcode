class Solution(object):
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        dp = [0] * 26  # maxlength ends with i+'a'
        cur = 0
        for i, c in enumerate(p):
            if i > 0 and ord(p[i]) - ord(p[i-1]) in (1, -25):
                cur += 1
            else:
                cur = 1
            idx = ord(c) - ord('a')
            dp[idx] = max(dp[idx], cur)
        return sum(dp)

# 81 / 81 test cases passed.
# Status: Accepted
# Runtime: 139 ms
