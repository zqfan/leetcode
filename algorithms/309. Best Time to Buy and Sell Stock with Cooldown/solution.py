class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # refer: https://discuss.leetcode.com/topic/30421/share-my-thinking-process
        if len(prices) < 2:
            return 0
        sell = pre_sell = pre_buy = 0
        buy = -prices[0]
        for p in prices:
            pre_buy = buy
            buy = max(pre_sell - p, pre_buy)
            pre_sell = sell
            sell = max(pre_buy + p, pre_sell)
        return sell
