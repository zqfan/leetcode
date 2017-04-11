class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        p1 = p2 = 0
        for n in nums:
            p1, p2 = p2, max(p1 + n, p2)
        return p2
