class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        res = m & n
        t = 1
        while t <= res:
            if n - m >= t:
                res &= ~t
            t <<= 1
        return res
