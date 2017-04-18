class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        m = 1000000007
        A0L0, A0L1, A0L2, A1L0, A1L1, A1L2 = 1, 0, 0, 0, 0, 0
        # iterate one more step to avoid complex return expression
        for i in xrange(n + 1):
            # append P, append L, append L
            A0L0, A0L1, A0L2 = (A0L0 + A0L1 + A0L2) % m, A0L0, A0L1
            # replace A and append P, append L, append L
            A1L0, A1L1, A1L2 = (A0L0 + A1L0 + A1L1 + A1L2) % m, A1L0, A1L1
        return A1L0

# 58 / 58 test cases passed.
# Status: Accepted
# Runtime: 486 ms
