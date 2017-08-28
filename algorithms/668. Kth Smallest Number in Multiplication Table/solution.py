class Solution(object):
    def findKthNumber(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        lo, hi = 1, m * n
        while lo < hi:
            mid = lo + (hi - lo) / 2
            if sum(min(mid / i, n) for i in xrange(1, m + 1)) >= k:
                hi = mid
            else:
                lo = mid + 1
        return lo

# 69 / 69 test cases passed.
# Status: Accepted
# Runtime: 1046 ms
