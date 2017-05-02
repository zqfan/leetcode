class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # refer: https://discuss.leetcode.com/topic/30421/share-my-thinking-process
        pre_sell, sell, buy = 0, 0, float('-inf')
        for p in prices:
            pre_sell, sell, buy = sell, max(buy + p, sell), max(pre_sell - p, buy)
        return sell
