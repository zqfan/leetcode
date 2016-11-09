class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        d = collections.defaultdict(int)
        for n in nums:
            d[n] += 1
        return [n for n in d if d[n] == 1]
