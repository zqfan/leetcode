class Solution(object):
    def maxA(self, N):
        """
        :type N: int
        :rtype: int
        """
        # @mzchen
        if N <= 6:
            return N
        if N == 10:
            return 20
        n = N / 5 + 1
        n3 = n * 5 - 1 - N
        return (3 ** n3) * (4 ** (n - n3))

# 50 / 50 test cases passed.
# Status: Accepted
# Runtime: 42 ms
