class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1
        while nums[l] > nums[r]:
            m = l + (r - l) / 2
            if nums[l] <= nums[m]:
                l = m + 1
            else:
                r = m
        return nums[l]
