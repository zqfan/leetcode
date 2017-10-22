class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        # inspired by @zestypanda 
        s0, s1 = 0, float('-inf')
        for p in prices:
            s0, s1 = max(s0, s1 + p - fee), max(s1, s0 - p)
        return s0

# 44 / 44 test cases passed.
# Status: Accepted
# Runtime: 335 ms
