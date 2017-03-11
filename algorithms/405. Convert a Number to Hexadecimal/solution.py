class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        # return '%x' % (num + (1 << 32) if num < 0 else num)
        if not isinstance(num, int):
            raise Exception("param num must be an integer.")

        if num == 0:
            return "0"

        if num < 0:
            num = (1 << 32) + num

        c_list = '0123456789abcdef'

        hexstr = ""
        while num > 0:
            hexstr = '%s%s' % (c_list[num % 16], hexstr)
            num = num / 16

        return hexstr


# test
import random
s = Solution()
for i in range(10000):
    num = random.randint(-pow(2, 32) + 1, pow(2, 32)-1)
    assert s.toHex(num) == ('%x' % (num + (1 << 32) if num < 0 else num))
