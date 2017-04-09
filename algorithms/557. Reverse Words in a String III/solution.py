class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(w[::-1] for w in s.split())

# 30 / 30 test cases passed.
# Status: Accepted
# Runtime: 52 ms
