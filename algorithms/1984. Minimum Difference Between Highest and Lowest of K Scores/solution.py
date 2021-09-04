class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        """Sort then use slide window."""
        nums.sort()
        m = 100000
        for i in range(k - 1, len(nums)):
            m = min(m, nums[i] - nums[i - k + 1])
        return m
