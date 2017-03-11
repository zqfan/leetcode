class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        diff_hash = {0: -1}
        diff = maxlen = 0
        for i, bit in enumerate(nums):
            diff += 1 if bit else -1
            maxlen = max(maxlen, i - diff_hash.setdefault(diff, i))
        return maxlen
