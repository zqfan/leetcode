class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        r = bisect.bisect_right(arr, x)
        l = r - 1
        for i in xrange(k):
            if l >= 0 and (r >= len(arr) or x - arr[l] <= arr[r] - x):
                l -= 1
            else:
                r += 1
        return arr[l+1:r]

# 55 / 55 test cases passed.
# Status: Accepted
# Runtime: 255 ms
# beats 76.43 %
