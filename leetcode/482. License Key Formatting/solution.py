class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        s = S.replace('-', '').upper()[::-1]
        return '-'.join([s[i:i+K] for i in xrange(0, len(s), K)])[::-1]

# 35 / 35 test cases passed.
# Status: Accepted
# Runtime: 42 ms
# 89.29%
