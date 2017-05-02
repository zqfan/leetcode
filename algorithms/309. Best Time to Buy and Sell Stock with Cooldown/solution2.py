class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        buy, sell, rest = [0] * (n + 1), [0] * (n + 1), [0] * (n + 1)
        buy[0] = float('-inf')
        for i, p in enumerate(prices):
            buy[i+1] = max(buy[i], rest[i] - p)
            sell[i+1] = max(sell[i], buy[i] + p)
            rest[i+1] = max(buy[i], sell[i], rest[i])
        return sell[n]
