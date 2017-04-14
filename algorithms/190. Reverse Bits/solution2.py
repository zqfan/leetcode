class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        return int("{0:032b}".format(n)[::-1], 2)
