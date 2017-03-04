class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # @xcv58
        if not s or len(s) == 1:
            return s
        # try to find potentional longest palindrome
        j = 0
        for i in xrange(len(s)-1, -1, -1):
            if s[i] == s[j]:
                j += 1
        # find substr shortest palindrome
        ss = self.shortestPalindrome(s[:j-len(s)])
        return s[:j-len(s)-1:-1] + ss + s[j-len(s):]
