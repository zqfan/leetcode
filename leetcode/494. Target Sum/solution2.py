class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        total = sum(nums)
        if S > total or S < -total or (S + total) & 1:
            return 0
        ways = [0] * (2 * total + 1)
        ways[total] = 1
        next_ways = [0] * (2 * total + 1)
        for n in nums:
            for i, w in enumerate(ways):
                if w > 0:
                    next_ways[i + n] += w
                    next_ways[i - n] += w
                    ways[i] = 0
            ways, next_ways = next_ways, ways
        return ways[total+S]

# 139 / 139 test cases passed.
# Status: Accepted
# Runtime: 212 ms
# 91.80%
