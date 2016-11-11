class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if not points:
            return 0
        points.sort()  # use sorted for real case
        # n: number of arrows
        n = 0
        # the most left end of the pile
        # arrow will always shot at e
        e = points[0][1]
        for p in points:
            if p[0] > e:
                n += 1
                e = p[1]
            e = min(e, p[1])
        return n + 1
