class Solution(object):
    def findLucky(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        return max(k if k == v else -1 for k, v in collections.Counter(arr).iteritems())
# Runtime: 48 ms, faster than 59.57% of Python online submissions for Find Lucky Integer in an Array.
# Memory Usage: 12.7 MB, less than 100.00% of Python online submissions for Find Lucky Integer in an Array.
