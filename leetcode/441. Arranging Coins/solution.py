import math

class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int(math.floor(math.sqrt(2*n+0.25)-0.5))
