class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        d = {0: 1}
        result = s = 0
        for n in nums:
            s += n
            result += d.get(s - k, 0)
            d[s] = d.get(s, 0) + 1
        return result

# 80 / 80 test cases passed.
# Status: Accepted
# Runtime: 95 ms
