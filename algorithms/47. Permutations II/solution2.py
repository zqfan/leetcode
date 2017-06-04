class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(start, nums):
            if start == len(nums):
                res.append(nums[:])
            for i in xrange(start, len(nums)):
                if i != start and nums[i] == nums[start]:
                    continue
                nums[i], nums[start] = nums[start], nums[i]
                dfs(start + 1, nums[:])
        nums = sorted(nums)
        res = []
        dfs(0, nums)
        return res

# 30 / 30 test cases passed.
# Status: Accepted
# Runtime: 112 ms
# beats 71.89 %
