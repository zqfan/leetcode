class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        def helper(amount, count, index):
            if index >= len(coins):
                return
            for i in range(amount/coins[index], -1, -1):
                remain = amount - i * coins[index]
                # remain will always >= 0
                if remain > 0 and count+i+1 < self.mincount:
                    helper(remain, count+i, index+1)
                else:
                    if remain == 0:
                        self.mincount = min(self.mincount, count+i)
                    # less big coins, more small coins, so brake
                    break

        coins.sort(reverse=True)
        self.mincount = sys.maxsize
        helper(amount, 0, 0)
        return self.mincount if self.mincount != sys.maxsize else -1
