class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        # @StefanPochmann
        n -= 1
        for width in xrange(1, 11):
            first = 10 ** (width - 1)
            if n < 9 * width * first:
                return int(str(first + n / width)[n % width])
            n -= 9 * width * first
