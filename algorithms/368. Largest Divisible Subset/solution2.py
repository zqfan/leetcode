class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        nums.sort()
        dp = [0] * len(nums)
        dp[0] = [nums[0]]
        for i in xrange(1, len(nums)):
            maxlen = 0; maxlenidx = -1
            for j in xrange(i):
                if nums[i] % dp[j][-1] == 0:
                    if len(dp[j]) > maxlen:
                        maxlen = len(dp[j])
                        maxlenidx = j
            if maxlen:
                dp[i] = dp[maxlenidx] + [nums[i]]
            else:
                dp[i] = [nums[i]]
        maxlen = 0; maxlenidx = -1
        for i in xrange(len(dp)):
            if len(dp[i]) > maxlen:
                maxlen = len(dp[i])
                maxlenidx = i
        return dp[maxlenidx]
