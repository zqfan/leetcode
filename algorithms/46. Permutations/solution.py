class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(i):
            if i >= len(nums):
                result.append(nums[:])
            for j in xrange(i, len(nums)):
                nums[i], nums[j] = nums[j], nums[i]
                dfs(i + 1)
                nums[i], nums[j] = nums[j], nums[i]
        result = []
        dfs(0)
        return result

# 25 / 25 test cases passed.
# Status: Accepted
# Runtime: 72 ms
# beats 75.27 %
