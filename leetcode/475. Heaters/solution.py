class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters = sorted(heaters) + [sys.maxsize]
        i = r = 0
        for x in sorted(houses):
            while x >= (heaters[i] + heaters[i+1]) / 2.0:
                i += 1
            r = max(r, abs(heaters[i] - x))
        return r

# 27 / 27 test cases passed.
# Status: Accepted
# Runtime: 152 ms
