class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(map(lambda x: x[::-1], s.split()))

# 30 / 30 test cases passed.
# Status: Accepted
# Runtime: 52 ms
