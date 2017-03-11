class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count_5 = 0
        while n > 0:
            count_5 += n / 5
            n /= 5
        return count_5
