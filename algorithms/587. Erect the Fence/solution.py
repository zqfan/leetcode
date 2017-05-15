# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    def outerTrees(self, points):
        """
        :type points: List[Point]
        :rtype: List[Point]
        """
        # @awice
        def clockwise(p, q, r):
            return (p.x - r.x) * (q.y - r.y) < (q.x - r.x) * (p.y - r.y)
        def findhull(hull, p):
            hull.append(p)
            while len(hull) > 2 and clockwise(*hull[-3:]):
                hull.pop(-2)
            return hull
        points.sort(key=lambda p: (p.x, p.y))
        lowerhull = reduce(findhull, points, [])
        upperhull = reduce(findhull, points[::-1], [])
        return list(set(lowerhull + upperhull))
