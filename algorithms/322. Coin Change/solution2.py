class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [sys.maxsize] * (amount+1)
        dp[0] = 0
        for c in coins:
            for i in range(c, amount+1):
                if dp[i-c] != sys.maxsize:
                    dp[i] = min(dp[i-c]+1, dp[i])
        return dp[amount] if dp[amount] != sys.maxsize else -1
