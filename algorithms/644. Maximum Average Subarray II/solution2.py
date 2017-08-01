import numpy

class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # @ StefanPochmann
        lo, hi = min(nums), max(nums)
        nums = numpy.array([0] + nums)
        while hi - lo >= 1e-5:
            mid = nums[0] = (lo + hi) / 2.
            sums = (nums - mid).cumsum()
            mins = numpy.minimum.accumulate(sums)
            if (sums[k:] - mins[:-k]).max() > 0:
                lo = mid
            else:
                hi = mid
        return lo

# 74 / 74 test cases passed.
# Status: Accepted
# Runtime: 285 ms
