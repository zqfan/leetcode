class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2:
            return 0
        sellprofits = [0, 0, 0]
        maxprofits = [0, 0, 0]
        sellprofits[1] = prices[1] - prices[0]
        maxprofits[1] = max(sellprofits[1], 0)
        for i in xrange(1, len(prices)-1):
            profit = prices[i+1] - prices[i]
            sellprofits[2] = max(sellprofits[2], maxprofits[1]) + profit
            maxprofits[2] = max(sellprofits[2], maxprofits[2])
            sellprofits[1] = max(sellprofits[1], maxprofits[0]) + profit
            maxprofits[1] = max(sellprofits[1], maxprofits[1])
        return max(maxprofits)

# 198 / 198 test cases passed.
# Status: Accepted
# Runtime: 65 ms
# 83.82%
