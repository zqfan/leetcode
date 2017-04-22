class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        count, product, limit = 1, 1, min(n, 10)
        choices = [9, 9, 8, 7, 6, 5, 4, 3, 2, 1]
        for i in xrange(limit):
            product *= choices[i]
            count += product
        return count
