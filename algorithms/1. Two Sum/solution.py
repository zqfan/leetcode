class Solution(object):
    def twoSum(self, nums, target):
        nums_set = set(nums)
        for i, n in enumerate(nums):
            if (target - n) not in nums_set:
                continue
            try:
                j = nums.index(target - n, i + 1)
            except ValueError:
                pass
            else:
                return [i, j]
