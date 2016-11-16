class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n + 1) for i in range(n + 1)]
        return self._get_min_worst(dp, 1, n)

    def _get_min_worst(self, dp, s, e):
        if s >= e:
            return 0
        if dp[s][e] != 0:
            return dp[s][e]
        min_worst = sys.maxsize
        for i in range(s, e + 1):
            left = self._get_min_worst(dp, s, i - 1)
            right = self._get_min_worst(dp, i + 1, e)
            worst = i + max(left, right)
            min_worst = min(min_worst, worst)
        dp[s][e] = min_worst
        return min_worst
