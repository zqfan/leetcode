class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ret = 0
        for i in xrange(len(nums)):
            p = 1
            for j in xrange(i, len(nums)):
                p *= nums[j]
                if p >= k:
                    break
                ret += 1
        return ret

# the reason why this solution pass is because the official test cases
# are too weak
# 64 / 64 test cases passed.
# Status: Accepted
# Runtime: 375 ms
