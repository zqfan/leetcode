class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)
        return max(nums[-1] * nums[-2] * nums[-3], nums[-1] * nums[0] * nums[1])

# 83 / 83 test cases passed.
# Status: Accepted
# Runtime: 152 ms
