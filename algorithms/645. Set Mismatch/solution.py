class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # @ hy299792458
        s1, s2, n = sum(nums), sum(set(nums)), len(nums)
        return [s1 - s2, n * (n + 1) / 2 - s2]
