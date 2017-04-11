class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = len(s)
        for i in xrange(1, l/2 + 1):
            if l % i != 0:
                continue
            if s == s[:i] * (l / i):
                return True
        return False

# 107 / 107 test cases passed.
# Status: Accepted
# Runtime: 78 ms
# beats 60.87%
