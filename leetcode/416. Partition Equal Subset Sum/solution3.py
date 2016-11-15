class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sums = sum(nums)
        if sums & 1:
            return False
        nums.sort()  # use sorted in real case
        nset = set([0])
        for n in nums:
            for m in nset.copy():
                nset.add(m + n)
            if sums / 2 in nset:
                return True
        return False
