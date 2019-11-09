class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cache, total, result = collections.defaultdict(int), 0, 0
        cache[0] = 1
        for n in nums:
            total += n & 1
            cache[total] += 1
            result += cache[total - k]
        return result
