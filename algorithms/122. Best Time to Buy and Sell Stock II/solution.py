class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0; buy = sys.maxsize; sell = 0
        for p in prices:
            if p <= buy and not sell:
                buy = p
            elif p >= sell:
                sell = p
            else:
                profit += sell - buy
                buy = p
                sell = 0
        if sell:
            profit += sell - buy
        return profit

# 198 / 198 test cases passed.
# Status: Accepted
# Runtime: 36 ms
# 95.94%
