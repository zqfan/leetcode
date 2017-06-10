class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        if not nums1 or not nums2 or k <= 0:
            return []

        heap = [[nums1[i] + nums2[0], i, 0] for i in xrange(len(nums1))]
        heapq.heapify(heap)

        result = []
        for _ in xrange(min(k, len(nums1) * len(nums2))):
            s, i, j = heapq.heappop(heap)
            result.append([nums1[i], nums2[j]])
            if j + 1 < len(nums2):
                heapq.heappush(heap, [nums1[i] + nums2[j + 1], i, j + 1])

        return result

# 27 / 27 test cases passed.
# Status: Accepted
# Runtime: 86 ms
# beats 85.71 %
