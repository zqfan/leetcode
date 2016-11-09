class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        n = min(10, n)
        k = [0] * n
        k[0] = 10
        for i in range(2, n+1):
            k[i-1] = 9 * reduce(operator.mul, range(9,10-i,-1))
        return sum(k)
