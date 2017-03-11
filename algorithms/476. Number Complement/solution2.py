class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        # math.log has float point problem: math.log(2147483648,2) = 31.000000000000004
        log = 0; n = num
        while n:
            n >>= 1
            log += 1
        return 2 ** log - num - 1
