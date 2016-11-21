class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        inc = dec = 1
        for i in xrange(1, len(nums)):
            if nums[i] > nums[i-1]:
                inc = dec + 1
            elif nums[i] < nums[i-1]:
                dec = inc + 1
        return max(inc, dec) if nums else 0
