class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        l = []
        count = 0
        for char in reversed(S):
            if char != '-':
                l.append(char.upper())
                count += 1
                if count == K:
                    l.append('-')
                    count = 0
        if l and l[-1] == '-':
            l.pop()
        return ''.join(reversed(l))

# 35 / 35 test cases passed.
# Status: Accepted
# Runtime: 82 ms
