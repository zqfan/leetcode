class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        maxsum = ksum = sum(itertools.islice(nums, 0, k))
        for i in xrange(k, len(nums)):
            ksum += nums[i] - nums[i-k]
            maxsum = max(maxsum, ksum)
        return maxsum / float(k)
