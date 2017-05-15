class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start, end, mini, maxi = 1, 0, float('inf'), float('-inf')
        for i in xrange(len(nums)):
            maxi = max(maxi, nums[i])
            if nums[i] < maxi:
                end = i
        for i in xrange(len(nums) - 1, -1, -1):
            mini = min(mini, nums[i])
            if nums[i] > mini:
                start = i
        return end - start + 1
