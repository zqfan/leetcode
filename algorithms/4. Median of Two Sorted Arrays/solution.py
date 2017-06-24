class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # @MissMary
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, m, nums2, n = nums2, n, nums1, m
        lo, hi = 0, m
        while lo <= hi:
            i = (lo + hi) / 2
            j = (m + n + 1) / 2 - i
            if i < m and nums1[i] < nums2[j - 1]:
                lo = i + 1
            elif i > 0 and nums1[i - 1] > nums2[j]:
                hi = i - 1
            else:
                max_of_left = max(nums1[i - 1] if i > 0 else float('-inf'),
                                  nums2[j - 1] if j > 0 else float('-inf'))
                if (m + n) % 2 == 1:
                    return max_of_left
                min_of_right = min(nums1[i] if i < m else float('inf'),
                                   nums2[j] if j < n else float('inf'))
                return (max_of_left + min_of_right) / 2.0

# 2080 / 2080 test cases passed.
# Status: Accepted
# Runtime: 106 ms
# beats 61.21 %
