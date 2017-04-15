class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = [c.lower() for c in s if c.isalnum()]
        return l == l[::-1]

# 476 / 476 test cases passed.
# Status: Accepted
# Runtime: 75 ms
# beats 86.40%
