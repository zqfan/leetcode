class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        # num is signed 32 bits
        if num < 1:
            return False
        return bool((num & 0x55555555) and (bin(num).count('1') == 1))

# test
s = Solution().isPowerOfFour
assert True == s(16)
assert False == s(5)
total_set = set([pow(4, i) for i in range(16)])
import random
for i in range(10000):
    num = random.randint(-32767, 32767)
    assert (num in total_set) == s(num)
