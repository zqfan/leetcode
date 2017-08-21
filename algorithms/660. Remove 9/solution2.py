import numpy

class Solution(object):
    def newInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int(numpy.base_repr(n, 9))

# 102 / 102 test cases passed.
# Status: Accepted
# Runtime: 122 ms
# beats 2.00 %
