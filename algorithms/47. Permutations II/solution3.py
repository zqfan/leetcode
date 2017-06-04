class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(remains):
            if len(path) == len(nums):
                res.append(path[:])
            for i in xrange(len(remains)):
                if i == 0 or remains[i] != remains[i-1]:
                    path.append(remains[i])
                    dfs(remains[:i] + remains[i+1:])
                    path.pop()
        nums = sorted(nums)
        res, path = [], []
        dfs(nums)
        return res

# 30 / 30 test cases passed.
# Status: Accepted
# Runtime: 115 ms
# beats 67.62 %
