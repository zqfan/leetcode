class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        # @StefanPochmann
        b = c = d = e = f = 0
        for a in x:
            if d >= b > 0 and (a >= c or a >= c-e >= 0 and f >= d-b):
                return True
            b, c, d, e, f = a, b, c, d, e
        return False

# 29 / 29 test cases passed.
# Status: Accepted
# Runtime: 32 ms
# 87.97%
