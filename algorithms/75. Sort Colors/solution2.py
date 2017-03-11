class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        color_count = [0] * 3
        for n in nums:
            color_count[n] += 1
        i = 0
        for color, count in enumerate(color_count):
            while count:
                nums[i] = color
                count -= 1
                i += 1
