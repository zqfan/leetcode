class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = [[]]
        for i in xrange(len(nums)):
            if i == 0 or nums[i] != nums[i-1]:
                l = len(res)
            for j in xrange(len(res) - l, len(res)):
                res.append(res[j] + [nums[i]])
        return res
