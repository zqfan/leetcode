class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in xrange(1, len(nums)):
            if nums[i] < nums[i-1]:
                return i - 1
        return len(nums) - 1
