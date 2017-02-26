class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        # @StefanPochmann
        desc_nums = sorted(nums, reverse=True)
        rank = ['Gold Medal', 'Silver Medal', 'Bronze Medal']
        rank += map(str, xrange(4, len(nums) + 1))
        return map(dict(zip(desc_nums, rank)).get, nums)
