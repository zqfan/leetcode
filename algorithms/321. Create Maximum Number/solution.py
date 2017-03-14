class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        # inspired by StefanPochmann
        def pick(nums, k):
            '''pick k number and make it maximal'''
            d, r = len(nums) - k, collections.deque()
            for n in nums:
                while d and r and r[-1] < n:
                    r.pop()
                    d -= 1
                r.append(n)
            while len(r) > k:
                r.pop()
            return r

        def merge(a, b):
            return [max(a, b).popleft() for _ in xrange(len(a) + len(b))]

        return max(merge(pick(nums1, i), pick(nums2, k - i))
                   for i in xrange(k + 1)
                   if i <= len(nums1) and k - i <= len(nums2))
