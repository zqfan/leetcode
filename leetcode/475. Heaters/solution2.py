class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort()
        heaters = [-sys.maxsize] + sorted(heaters) + [sys.maxsize]
        min_radius = right = 0
        for i in xrange(1, len(heaters)):
            if min_radius >= heaters[i] - heaters[i-1]:
                continue
            left = bisect.bisect_left(houses, heaters[i-1], lo=right)
            right = bisect.bisect_right(houses, heaters[i], lo=left)
            for j in xrange(left, right):
                radius = min(houses[j]-heaters[i-1], heaters[i]-houses[j])
                min_radius = max(min_radius, radius)
        return min_radius

# 27 / 27 test cases passed.
# Status: Accepted
# Runtime: 126 ms
