class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # Define peak is a number that there must be another
        # number in its left side and smaller than it.
        # Define smallest_peak is the smallest peak.
        # Note that smallest number may be left or right side
        # of smallest_peak, but it doesn't matter.
        smallest = smallest_peak = float('inf')
        for n in nums:
            if n > smallest_peak:
                return True
            smallest = min(smallest, n)
            # we find a new peak and it is less than smallest_peak
            if smallest < n < smallest_peak:
                smallest_peak = n
        return False
