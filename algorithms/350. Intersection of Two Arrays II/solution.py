class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # bad solution for mem, but good for cpu
        ret = []
        num_count = {}
        for n in nums1:
            num_count[n] = num_count.get(n, 0) + 1
        for n in nums2:
            if num_count.get(n, -1) >= 1:
                ret.append(n)
                num_count[n] -= 1
        return ret

    # solution if nums1 & nums2 get sorted
    def intersect2(self, nums1, nums2):
        ret = []
        i, length = 0, len(nums2)
        for n in nums1:
            while i < length and nums2[i] < n:
                i += 1
            if i < length and nums2[i] == n:
                i += 1
                ret.append(n)
        return ret

# test
s = Solution().intersect
assert [2, 2] == s([1, 2, 2, 1], [2, 2])
s2 = Solution().intersect2
import random
for i in range(100):
    nums1 = [random.randint(-32767, 32767) for x in range(30000)]
    nums2 = [random.randint(-32767, 32767) for x in range(30000)]
    assert sorted(s(nums1, nums2)) == s2(sorted(nums1), sorted(nums2))
