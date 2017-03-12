class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        vertexs = set()
        minx = miny = float('inf')
        maxx = maxy = area = 0
        for x1, y1, x2, y2 in rectangles:
            minx = min(minx, x1)
            miny = min(miny, y1)
            maxx = max(maxx, x2)
            maxy = max(maxy, y2)
            area += (x2 - x1) * (y2 - y1)
            for v in [(x1, y1), (x1, y2), (x2, y1), (x2, y2)]:
                if v in vertexs:
                    vertexs.remove(v)
                else:
                    vertexs.add(v)
        if area != (maxx - minx) * (maxy - miny):
            return False
        return vertexs == set([(minx, miny), (minx, maxy), (maxx, miny), (maxx, maxy)])
