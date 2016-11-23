class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        # refer to LastCrazy@leetcode.com
        x, y = min(x, y), max(x, y)
        if z in (0, x, y):
            return True
        if x + y < z:
            return False
        while x != 0:
            y, x = x, y % x
        return z % y == 0
