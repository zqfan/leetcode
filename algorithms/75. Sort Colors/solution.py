class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        e = u = 0
        g = len(nums)
        while u < g:
            if nums[u] < 1:
                nums[u], nums[e] = nums[e], nums[u]
                u += 1
                e += 1
            elif nums[u] > 1:
                g -= 1
                nums[u], nums[g] = nums[g], nums[u]
            else:
                u += 1
