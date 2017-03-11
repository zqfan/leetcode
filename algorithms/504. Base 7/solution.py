class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num < 0:
            return '-' + self.convertToBase7(-num)
        res = ''
        while num:
            res = str(num % 7) + res
            num //= 7
        return res or '0'
