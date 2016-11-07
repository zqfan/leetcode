class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1:
            return True
        left = 2
        right = num
        while left <= right:
            middle = (left + right) / 2
            mid_square = middle * middle
            if mid_square > num:
                right = middle - 1
            elif mid_square < num:
                left = middle + 1
            else:
                return True
        return False
