class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lp = bisect.bisect_left(nums, target)
        rp = bisect.bisect_right(nums, target)
        return [-1, -1] if target not in nums[lp:lp+1] else [lp, rp-1]
