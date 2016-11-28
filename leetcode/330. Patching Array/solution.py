class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        # @StefanPochmann
        res = i = 0
        min_miss = 1
        while min_miss <= n:
            if i < len(nums) and nums[i] <= min_miss:
                min_miss += nums[i]
                i += 1
            else:
                min_miss += min_miss
                res += 1
        return res

# 149 / 149 test cases passed.
# Status: Accepted
# Runtime: 42 ms
# 79.17%
