class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        return [n for n, cnt in collections.Counter(nums).most_common(k)]

# 20 / 20 test cases passed.
# Status: Accepted
# Runtime: 76 ms
# beats 67.17%
