class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        # I don't know O(1) method, 2016-10-07
        while num > 9:
            num = sum([int(d) for d in str(num)])
        return num

# test
s = Solution().addDigits
assert s(38) == 2, s(38)
