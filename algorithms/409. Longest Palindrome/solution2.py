class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        odd = 0
        for i in xrange(26):
            odd += s.count(chr(ord('a') + i)) & 1
            odd += s.count(chr(ord('A') + i)) & 1
        return len(s) - odd + (odd > 0)

# 95 / 95 test cases passed.
# Status: Accepted
# Runtime: 42 ms
