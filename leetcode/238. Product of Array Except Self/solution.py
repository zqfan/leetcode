class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        p_arr = [1] * len(nums)
        p = 1
        for i in range(1, len(nums)):
            p *= nums[i-1]
            p_arr[i] = p
        p = 1
        for i in range(len(nums)-2, -1, -1):
            p *= nums[i+1]
            p_arr[i] *= p
        return p_arr
