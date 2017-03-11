class Solution(object):
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        def get_num(base, bits):
            n = 0; t = 1
            for i in xrange(bits):
                n += t
                t *= base
            return n

        n = int(n); maxlength = int(math.log(n, 2)) + 1
        for bits in xrange(maxlength, 0, -1):
            low = 2; high = n - 1
            while low <= high:
                middle = (low + high) / 2
                num = get_num(middle, bits)
                if num < n:
                    low = middle + 1
                elif num > n:
                    high = middle - 1
                else:
                    return str(middle)
