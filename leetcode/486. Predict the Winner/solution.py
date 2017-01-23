class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # @kevin36
        if len(nums) & 1 == 0:
            return True
        # @Hcisly
        dp = [[0] * len(nums) for i in xrange(len(nums))]
        for i in xrange(len(nums)-1, -1, -1):
            dp[i][i] = nums[i]
            for j in xrange(i+1, len(nums)):
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
        return dp[0][len(nums)-1] >= 0
