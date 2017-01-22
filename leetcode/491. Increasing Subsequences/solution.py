class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(candidate, idx):
            for i in xrange(idx, len(nums)):
                if candidate and nums[i] < candidate[-1]:
                    continue
                candidate.append(nums[i])
                if len(candidate) > 1:
                    res.add(tuple(candidate))
                dfs(candidate, i+1)
                candidate.pop()
        res = set()
        dfs([], 0)
        return [list(t) for t in res]
