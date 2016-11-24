class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        # @dietpepsi
        if k < 1 or t < 0 or not nums:
            return False
        buckets = {}; width = t + 1
        for i, n in enumerate(nums):
            b = n / width
            if b in buckets:
                return True
            if b-1 in buckets and n - buckets[b-1] < width:
                return True
            if b+1 in buckets and buckets[b+1] - n < width:
                return True
            buckets[b] = n
            if i >= k:
                buckets.pop(nums[i-k] / width)
        return False

# 31 / 31 test cases passed.
# Status: Accepted
# Runtime: 49 ms
# 91.12%
