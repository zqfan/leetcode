class Solution(object):
    def findIntegers(self, num):
        """
        :type num: int
        :rtype: int
        """
        presum = [0] * 32
        for i in xrange(2, 32):
            presum[i] = (1 << (i - 2)) + sum(presum[:i-1])
        def count11(n):
            if n < 3:
                return 0
            bn = bin(n)[2:]
            c = sum(presum[:len(bn)])
            if bn[1] == '1':
                c += n - (3 << (len(bn) - 2)) + 1
                return c + sum(presum[:len(bn) - 1])
            else:
                return c + count11(int(bn[2:] or '0', 2))
        return num + 1 - count11(num)
