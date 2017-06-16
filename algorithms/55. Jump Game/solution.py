class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        i = final = 0
        while i <= final:
            final = max(final, nums[i] + i)
            if final >= len(nums) - 1:
                return True
            i += 1
        return False

# 75 / 75 test cases passed.
# Status: Accepted
# Runtime: 62 ms
# beats 48.32 %
