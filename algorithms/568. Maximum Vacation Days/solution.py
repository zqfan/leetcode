class Solution(object):
    def maxVacationDays(self, flights, days):
        """
        :type flights: List[List[int]]
        :type days: List[List[int]]
        :rtype: int
        """
        # @awice
        N, K = len(days), len(days[0])
        dp = [float('-inf')] * N
        dp[0] = 0
        for k in xrange(K):
            cur = [float('-inf')] * N
            for i in xrange(N):
                for j in xrange(N):
                    if flights[i][j] or i == j:
                        cur[j] = max(cur[j], dp[i] + days[j][k])
            dp = cur
        return max(dp)

# 57 / 57 test cases passed.
# Status: Accepted
# Runtime: 2549 ms
