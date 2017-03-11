class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        MAX = 0xffffffffffffffff
        x, y = a & MAX, b & MAX
        while y:
            z = x ^ y
            y = ((x & y) << 1) & MAX
            x = z & MAX
        if x >> 63:
            return self.fixed_width_neg_int(x)
        else:
            return x

    @staticmethod
    def fixed_width_neg_int(x):
        reverse = {'1': '0', '0': '1'}
        str_x = list(bin(x)[2:])
        for i in range(len(str_x)):
            str_x[i] = reverse[str_x[i]]
        while i >= 0:
            if str_x[i] == '1':
                str_x[i] = '0'
            else:
                break
            i -= 1
        if i >= 0:
            str_x[i] = '1'
        return int('-0b%s' % ''.join(str_x), 2)

# test
s = Solution().getSum
assert -3 == s(-1, -2), s(-1, -2)
assert 1 == s(-1, 2), s(-1, 2)
import random
for i in range(10000):
    a = random.randint(-32767, 32767)
    b = random.randint(-32767, 32767)
    assert (a + b) == s(a, b)
