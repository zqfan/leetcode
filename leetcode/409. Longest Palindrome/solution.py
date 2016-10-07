class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        longest = 0
        has_odd = 0
        sorted_s = sorted(s)
        i = 0
        while i + 1 < len(sorted_s):
            if sorted_s[i] == sorted_s[i + 1]:
                longest += 2
                i += 2
            else:
                i += 1
                has_odd = 1
        if i + 1 == len(sorted_s):
            has_odd = 1
        return longest + has_odd

# test
s = Solution().longestPalindrome
assert s("abccccdd") == 7
