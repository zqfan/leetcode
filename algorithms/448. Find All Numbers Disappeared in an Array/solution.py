class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i, n in enumerate(nums):
            while n:
                nums[n-1], n = 0, nums[n-1]
        return [i+1 for i, n in enumerate(nums) if n]
