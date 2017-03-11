class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        # cooldown max profit, sell max profit, hold max profit, min hold value
        state = [[0]*4, [0,0,0,prices[0]]]
        for i, p in enumerate(prices, 2):
            state[0][0] = max(state[1][0], state[1][1])
            if p > state[1][3]:
                state[0][1] = state[1][2] + p - state[1][3]
            else:
                state[0][1] = state[1][2]
            if state[1][0] - p > state[1][2] - state[1][3]:
                state[0][2] = state[1][0]
                state[0][3] = p
            else:
                state[0][2] = state[1][2]
                state[0][3] = min(p, state[1][3])
            state[0], state[1] = state[1], state[0]
        return max(state[1][0], state[1][1], state[1][2])
