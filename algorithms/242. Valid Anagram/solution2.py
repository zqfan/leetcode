class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return sorted(s) == sorted(t)

# 34 / 34 test cases passed.
# Status: Accepted
# Runtime: 99 ms
