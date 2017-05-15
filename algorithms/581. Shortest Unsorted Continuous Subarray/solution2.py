class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = sorted(nums)
        l, r = 0, len(nums) - 1
        while l <= r and s[l] == nums[l]:
            l += 1
        while l <= r and s[r] == nums[r]:
            r -= 1
        return r - l + 1
