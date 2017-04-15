class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # there is no test case with empty nums
        nums[:] = nums[-k%len(nums):] + nums[:-k%len(nums)]
