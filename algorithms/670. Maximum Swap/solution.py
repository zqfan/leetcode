class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = list(str(num))
        for i in xrange(len(s)):
            for j in xrange(i+1, len(s)):
                s[i], s[j] = s[j], s[i]
                num = max(num, int(''.join(s)))
                s[i], s[j] = s[j], s[i]
        return num

# 111 / 111 test cases passed.
# Status: Accepted
# Runtime: 39 ms
