class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        return ''.join(s[i:i+k][::-1] + s[i+k:i+2*k] for i in xrange(0, len(s), 2*k))
