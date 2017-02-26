class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        sorted_nums = sorted(zip(nums, range(len(nums))), reverse=True)
        res = [''] * len(nums)
        for i, (n, j) in enumerate(sorted_nums):
            res[j] = str(i + 1)
        # handle top 3
        if len(nums) > 0:
            res[sorted_nums[0][1]] = 'Gold Medal'
        if len(nums) > 1:
            res[sorted_nums[1][1]] = 'Silver Medal'
        if len(nums) > 2:
            res[sorted_nums[2][1]] = 'Bronze Medal'
        return res
