class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False

        for pf in [2, 3, 5]:
            while num % pf == 0:
                num /= pf

        return num == 1
