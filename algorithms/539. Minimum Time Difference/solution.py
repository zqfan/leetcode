class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        if len(timePoints) > 1440:
            return 0
        s = sorted(map(lambda t: int(t[:2]) * 60 + int(t[3:]), timePoints))
        return min(s2 - s1 for s1, s2 in zip(s, s[1:] + [1440+s[0]]))
