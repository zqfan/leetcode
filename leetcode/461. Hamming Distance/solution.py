class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        return bin(x ^ y).count('1')

# 149 / 149 test cases passed.
# Status: Accepted
# Runtime: 48 ms
# 100%
