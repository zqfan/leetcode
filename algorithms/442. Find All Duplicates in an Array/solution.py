class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        dup = []
        for n in nums:
            idx = abs(n) - 1
            if nums[idx] < 0:
                dup.append(idx + 1)
            else:
                nums[idx] = -nums[idx]
        return dup

# 27 / 27 test cases passed.
# Status: Accepted
# Runtime: 308 ms
# 82.47%
