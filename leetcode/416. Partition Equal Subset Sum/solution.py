class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # we use a big int, to indicate whether a sum
        # has been appeared
        s, bit = 0, 1
        for n in nums:
            s += n
            bit |= bit << n
        return not (s & 1) and bool(bit & (1 << (s / 2)))
