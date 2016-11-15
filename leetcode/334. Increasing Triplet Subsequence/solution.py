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
        smallest = smallest_peak = None
        for n in nums:
            if smallest_peak is not None and n > smallest_peak:
                return True
            # we find a new peak and it is less than smallest_peak
            elif smallest is not None and n > smallest:
                smallest_peak = n
            else:
                smallest = n
        return False
