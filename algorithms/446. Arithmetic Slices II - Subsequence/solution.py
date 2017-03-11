class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res = 0
        # store number of arithetic slices ends at i, for each delta.
        # note that potential arithetic slices are counted as well.
        dp = [{} for i in xrange(len(A))]
        for end in xrange(len(A)):
            for pre in xrange(end):
                d = A[end] - A[pre]
                dp[end].setdefault(d, 0)
                if d in dp[pre]:
                    res += dp[pre][d]
                    dp[end][d] += dp[pre][d] + 1
                else:
                    dp[end][d] += 1
        return res
