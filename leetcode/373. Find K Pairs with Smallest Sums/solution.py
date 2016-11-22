class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        if not nums1 or not nums2 or k < 1:
            return []

        heap = []
        for i in xrange(len(nums1)):
            heap.append((nums1[i]+nums2[0], i, 0))
        heapq.heapify(heap)

        res = []
        while k > 0 and len(heap) > 0:
            s, i1, i2 = heapq.heappop(heap)
            res.append([nums1[i1], nums2[i2]])
            if i2+1 < len(nums2):
                heapq.heappush(heap, (nums1[i1]+nums2[i2+1], i1, i2+1))
            k -= 1
        return res
