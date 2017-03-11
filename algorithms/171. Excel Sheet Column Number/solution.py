class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = 0
        for c in s:
            num *= 26
            num += ord(c) - ord('A') + 1
        return num

# test
s = Solution().titleToNumber
assert 28 == s('AB')
