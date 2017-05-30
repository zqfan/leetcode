class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # @StefanPochmann
        S = {1: []}
        for n in sorted(nums):
            S[n] = max([S[d] for d in S if n % d == 0], key=len) + [n]
        return max(S.itervalues(), key=len)

# 36 / 36 test cases passed.
# Status: Accepted
# Runtime: 385 ms
# beats 97.77 %
