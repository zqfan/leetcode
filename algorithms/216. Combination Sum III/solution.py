class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        # @StefanPochmann
        return [c for c in itertools.combinations(xrange(1, 10), k) if sum(c) == n]
