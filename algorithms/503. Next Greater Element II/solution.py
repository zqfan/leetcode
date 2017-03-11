class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        desc_stack = []
        res = [0] * len(nums)
        # process one pass
        for i, n in enumerate(nums):
            while desc_stack and desc_stack[-1][0] < n:
                res[desc_stack.pop()[1]] = n
            desc_stack.append((nums[i], i))
        # process rotate pass
        for n in nums:
            while desc_stack and desc_stack[-1][0] < n:
                res[desc_stack.pop()[1]] = n
        # process maximal number
        while desc_stack:
            res[desc_stack.pop()[1]] = -1
        return res
