class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = [sys.maxsize] * len(envelopes)
        for e in envelopes:
            dp[bisect.bisect_left(dp, e[1])] = e[1]
        return bisect.bisect_left(dp, sys.maxsize)

# 85 / 85 test cases passed.
# Status: Accepted
# Runtime: 98 ms
# 94.05%
