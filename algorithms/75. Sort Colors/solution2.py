class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        c = collections.Counter(nums)
        nums[:] = [0] * c[0] + [1] * c[1] + [2] * c[2]
