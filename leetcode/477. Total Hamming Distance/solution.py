class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(b.count('0') * b.count('1') for b in zip(*map('{:032b}'.format, nums)))

# 47 / 47 test cases passed.
# Status: Accepted
# Runtime: 298 ms
