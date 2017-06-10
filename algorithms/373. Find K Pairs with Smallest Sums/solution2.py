class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        # @StefanPochmann
        stream = heapq.merge(*map(lambda u: ([u+v, u, v] for v in nums2), nums1))
        return [suv[1:] for suv in itertools.islice(stream, k)]

# 27 / 27 test cases passed.
# Status: Accepted
# Runtime: 92 ms
# beats 67.74 %
