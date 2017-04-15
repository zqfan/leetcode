class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        unique = set(nums)
        if len(unique) < 3:
            return max(unique)
        unique.remove(max(unique))
        unique.remove(max(unique))
        return max(unique)

# 26 / 26 test cases passed.
# Status: Accepted
# Runtime: 55 ms
# beats 41.04%
