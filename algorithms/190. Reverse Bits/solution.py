class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        m = 0
        for i in xrange(32):
            m = (m << 1) | (n & 1)
            n >>= 1
        return m
