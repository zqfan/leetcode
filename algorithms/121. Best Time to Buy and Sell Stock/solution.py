class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minprice = sys.maxsize
        maxprofit = 0
        for p in prices:
            maxprofit = max(maxprofit, p-minprice)
            minprice = min(minprice, p)
        return maxprofit

# 200 / 200 test cases passed.
# Status: Accepted
# Runtime: 43 ms
# 86.49%
