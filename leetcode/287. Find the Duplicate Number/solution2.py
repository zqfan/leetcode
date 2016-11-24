class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # @mehran
        l = 1; r = len(nums) - 1
        while l < r:
            m = (l + r) / 2
            count = 0
            for n in nums:
                if n <= m:
                    count += 1
            if count <= m:
                l = m + 1
            else:
                r = m
        return l

# 53 / 53 test cases passed.
# Status: Accepted
# Runtime: 59 ms
# 65.65%
