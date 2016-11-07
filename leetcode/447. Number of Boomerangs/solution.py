import collections

class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        # O(n^2) time, O(n) space
        boomerangs = 0
        dis_count = collections.defaultdict(int)
        for x1, y1 in points:
            for x2, y2 in points:
                d = (x1 - x2) ** 2 + (y1 - y2) ** 2
                dis_count[d] += 1
            for d, c in dis_count.iteritems():
                boomerangs += (c - 1) * c
            dis_count.clear()
        return boomerangs
