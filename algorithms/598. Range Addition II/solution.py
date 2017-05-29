class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        a, b = zip(*ops) if ops else [[m], [n]]
        return min(a) * min(b)
