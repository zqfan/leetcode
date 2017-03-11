class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # refer to http://www.cnblogs.com/grandyang/p/5705750.html
        dp = [0] * (target+1)
        dp[0] = 1
        for i in range(target+1):
            for n in nums:
                if n + i <= target:
                    dp[n+i] += dp[i]
        return dp[target]
