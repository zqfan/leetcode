class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        rx = int(str(abs(x))[::-1])
        return cmp(x, 0) * rx if rx < 2 ** 31 else 0
