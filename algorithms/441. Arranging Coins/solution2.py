class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        rows = 0
        while n > rows:
            rows += 1
            n -= rows
        return rows
