class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        n = 0
        for i in xrange(len(s) - 1):
            if roman[s[i]] < roman[s[i + 1]]:
                n -= roman[s[i]]
            else:
                n += roman[s[i]]
        return n + roman[s[-1]]

# 3999 / 3999 test cases passed.
# Status: Accepted
# Runtime: 142 ms
