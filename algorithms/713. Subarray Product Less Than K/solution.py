class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ret = end = 0
        p = 1
        for start in xrange(0, len(nums)):
            if end < start:
                end = start
            while end < len(nums) and p * nums[end] < k:
                p *= nums[end]
                end += 1
            ret += end - start
            p /= nums[start]
        return ret

# 64 / 64 test cases passed.
# Status: Accepted
# Runtime: 349 ms
