class Solution(object):
    def kInversePairs(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 1000000007
        before, after = [0] * (k + 1), [0] * (k + 1)
        before[0] = after[0] = 1
        for i in xrange(1, n+1):
            after, before = before, after
            for j in xrange(1, k+1):
                after[j] = after[j-1] + before[j]
                if j >= i:
                    after[j] -= before[j-i]
                if after[j] < 0:
                    after[j] += MOD
                elif after[j] >= MOD:
                    after[j] -= MOD
        return after[k]

# 80 / 80 test cases passed.
# Status: Accepted
# Runtime: 398 ms
# beats 94.05 %
