class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        for i in xrange(int(c ** 0.5) + 1):
            j = (c - i ** 2) ** 0.5
            if j == int(j):
                return True
        return False
