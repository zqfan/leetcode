class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        ways = {0: 1}
        for n in nums:
            tways = collections.defaultdict(int)
            for k in ways:
                tways[k+n] += ways[k]
                tways[k-n] += ways[k]
            ways = tways
        return ways.get(S, 0)

# 139 / 139 test cases passed.
# Status: Accepted
# Runtime: 278 ms
# 85.25%
