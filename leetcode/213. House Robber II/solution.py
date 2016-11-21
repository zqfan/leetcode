class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return sum(nums)
        def rob_by_range(start, end):
            dp = [0, 0, 0]
            for i in xrange(start, end):
                dp[0] = max(dp[2]+nums[i], dp[1])
                dp[2] = dp[1]
                dp[1] = dp[0]
            return dp[0]
        return max(rob_by_range(0, len(nums)-1), rob_by_range(1, len(nums)))
