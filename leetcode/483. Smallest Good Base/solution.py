class Solution(object):
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        n = int(n); maxl = int(math.log(n, 2))
        for l in xrange(maxl, 1, -1):
            k = int(n ** l ** -1)
            if k ** (l + 1) - 1 == n * (k - 1):
                return str(k)
        return str(n - 1)
