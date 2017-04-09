class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and 1162261467 % n == 0

# 21038 / 21038 test cases passed.
# Status: Accepted
# Runtime: 259 ms
# beats 23.96%
