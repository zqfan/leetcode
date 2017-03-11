class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i = 0
        for c in s:
            while i < len(t) and t[i] != c:
                i += 1
            i += 1
        return i <= len(t)
