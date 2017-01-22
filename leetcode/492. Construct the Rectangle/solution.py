class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        for x in xrange(int(area**0.5), 0, -1):
            if area % x == 0:
                return [area / x, x]
