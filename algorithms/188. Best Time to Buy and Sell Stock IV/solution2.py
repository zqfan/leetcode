class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if k >= len(prices)/2:
            profit = 0
            for i in xrange(1, len(prices)):
                if prices[i] > prices[i-1]:
                    profit += prices[i] - prices[i-1]
            return profit
        sellprofits = [0] * (k+1)
        maxprofits = [0] * (k+1)
        for i in xrange(len(prices)-1):
            profit = prices[i+1] - prices[i]
            for j in xrange(min(i+1, k), 0, -1):
                sellprofits[j] = max(sellprofits[j], maxprofits[j-1]) + profit
                maxprofits[j] = max(sellprofits[j], maxprofits[j])
        return max(maxprofits)

# 211 / 211 test cases passed.
# Status: Accepted
# Runtime: 96 ms
# 89.43%
