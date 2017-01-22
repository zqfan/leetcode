class Solution(object):
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        sorted_arr = sorted(nums[:k])
        median = [(sorted_arr[k/2] + sorted_arr[(k-1)/2]) / 2.0]
        for i in xrange(k, len(nums)):
            sorted_arr.remove(nums[i-k])
            bisect.insort_left(sorted_arr, nums[i])
            median.append((sorted_arr[k/2] + sorted_arr[(k-1)/2]) / 2.0)
        return median
