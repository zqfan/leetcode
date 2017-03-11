# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        max_points = 0
        slopes = collections.defaultdict(int)
        for i, pi in enumerate(points):
            slopes.clear()
            for j, pj in enumerate(points, i):
                if pi.x != pj.x:
                    slopes[(pi.y-pj.y)/float((pi.x-pj.x))] += 1
                elif pi.y == pj.y:
                    slopes['d'] += 1
                else:
                    slopes['v'] += 1
            d = slopes.pop('d')
            for s, c in slopes.iteritems():
                max_points = max(max_points, c + d)
            max_points = max(max_points, d)
        return max_points
