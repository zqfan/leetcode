class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s, m = [], [-1] * len(nums)
        for i in range(len(nums)) * 2:
            while s and nums[s[-1]] < nums[i]:
                m[s.pop()] = nums[i]
            s.append(i)
        return m
