class Solution(object):
    def newInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        base9 = 0
        p = 1
        while n > 0:
            base9 += (n % 9) * p
            p *= 10
            n /= 9
        return base9
