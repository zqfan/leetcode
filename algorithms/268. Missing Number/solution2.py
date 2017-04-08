class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(operator.xor, nums + range(len(nums) + 1))

# 121 / 121 test cases passed.
# Status: Accepted
# Runtime: 72 ms
