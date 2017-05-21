class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = collections.Counter(nums)
        lhs = 0
        for n in counter:
            if n + 1 in counter:
                lhs = max(lhs, counter[n] + counter[n+1])
        return lhs
