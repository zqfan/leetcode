class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        reserve = [g - c for g, c in zip(gas, cost)]
        if sum(reserve) < 0: return -1
        total, start = 0, 0
        for i in range(len(reserve)):
            total += reserve[i]
            if total < 0:
                total, start = 0, i + 1
        return start
