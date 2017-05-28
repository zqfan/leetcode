class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        p0 = p1 = p2 = p3 = 0
        for i in xrange(0, len(nums) - 1):
            p0, p1 = p1, max(p0 + nums[i], p1)
        for i in xrange(1, len(nums)):
            p2, p3 = p3, max(p2 + nums[i], p3)
        return max(p1, p3) if len(nums) > 1 else sum(nums)
