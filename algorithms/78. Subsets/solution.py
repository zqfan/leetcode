class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        result = [list() for i in xrange(2 ** n)]
        for i in xrange(n):
            for j in xrange(2 ** n):
                if (j >> i) & 1:
                    result[j].append(nums[i])
        return result
