class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        left, right = 0, sum(nums)
        for i in range(len(nums)):
            right -= nums[i]
            if left == right:
                return i
            left += nums[i]
        return -1
