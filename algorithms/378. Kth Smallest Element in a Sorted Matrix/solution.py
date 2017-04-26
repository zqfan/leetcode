class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        # return list(heapq.merge(*matrix))[k-1]
        return sorted(itertools.chain(*matrix))[k-1]

# 85 / 85 test cases passed.
# Status: Accepted
# Runtime: 72 ms
# beats 85.09 %
