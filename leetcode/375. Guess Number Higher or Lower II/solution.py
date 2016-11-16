class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        min_worst = [[0] * (n+1) for i in range(n+1)]
        for start in reversed(range(1, n)):
            for end in range(start+1, n+1):
                min_worst[start][end] = min(x + max(min_worst[start][x-1],
                                                    min_worst[x+1][end])
                                            for x in range(start, end))
        return min_worst[1][n]
