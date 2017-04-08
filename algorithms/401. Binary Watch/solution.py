class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        return ['%d:%02d' % (h, m)
                for h in xrange(12)
                for m in xrange(60)
                if (bin(h) + bin(m)).count("1") == num]

# 10 / 10 test cases passed.
# Status: Accepted
# Runtime: 45 ms
