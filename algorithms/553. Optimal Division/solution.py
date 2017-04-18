class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        snums = map(str, nums)
        if len(nums) > 2:
            snums[1] = '(' + snums[1]
            snums[-1] = snums[-1] + ')'
        return '/'.join(snums)
