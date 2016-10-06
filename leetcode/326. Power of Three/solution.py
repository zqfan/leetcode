class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # we need math to avoid loop, which actually is worse
        import math
        # we assume n is a signed 32 bits int
        max_log3_32 = math.log10(0x7fffffff) / math.log10(3)
        max_pow3_32 = math.pow(3, int(max_log3_32))
        # it must be a factor of max pow3
        return (n > 0) and (max_pow3_32 % n == 0)

# test
s = Solution().isPowerOfThree
total_set = set([pow(3, i) for i in range(32) if pow(3, i) <= 0x7fffffff])
import random
for i in range(10000):
    n = random.randint(-32767,32767)
    assert s(n) == (n in total_set)
