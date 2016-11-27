class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envelopes.sort(cmp=lambda x,y: x[0]-y[0] or y[1]-x[1])
        dp = []
        for e in envelopes:
            l, r = 0, len(dp)-1
            while l <= r:
                m = (l + r) / 2
                if dp[m] < e[1]:
                    l = m + 1
                else:
                    r = m - 1
            if l >= len(dp):
                dp.append(e[1])
            else:
                dp[l] = e[1]
        return len(dp)

# 85 / 85 test cases passed.
# Status: Accepted
# Runtime: 122 ms
# 78.57%
