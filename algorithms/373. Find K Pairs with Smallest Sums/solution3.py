class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        # @StefanPochmann
        return map(list, heapq.nsmallest(k, itertools.product(nums1, nums2), key=sum))

# 27 / 27 test cases passed.
# Status: Accepted
# Runtime: 502 ms
# beats 10.60 %
