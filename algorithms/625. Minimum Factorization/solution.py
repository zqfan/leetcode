class Solution(object):
    def smallestFactorization(self, a):
        """
        :type a: int
        :rtype: int
        """
        if a < 10:
            return a
        b = 0
        for i in xrange(11):
            for d in xrange(9, 1, -1):
                if a % d == 0:
                    b += (10 ** i) * d
                    a /= d
                    break
        return b if b < (1 << 31) and a == 1 else 0
