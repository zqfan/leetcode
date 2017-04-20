class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        total = cur = 0
        for i in xrange(2, len(A)):
            if A[i] - A[i-1] == A[i-1] - A[i-2]:
                cur += 1
                total += cur
            else:
                cur = 0
        return total
