class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n, start, maxlen, i = len(s), 0, 1, 0
        while i < n:
            l = r = i
            while r + 1 < n and s[r] == s[r + 1]:
                r += 1
            i = r + 1
            while l > 0 and r + 1 < n and s[l - 1] == s[r + 1]:
                l -= 1
                r += 1
            if r - l + 1 > maxlen:
                maxlen = r - l + 1
                start = l
        return s[start:start + maxlen]

# 94 / 94 test cases passed.
# Status: Accepted
# Runtime: 169 ms
# beats 74.03 %
