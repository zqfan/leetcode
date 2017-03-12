class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        if len(timePoints) > 1440:
            return 0
        buckets = [0] * 1440
        for tp in timePoints:
            seconds = int(tp[:2]) * 60 + int(tp[3:])
            buckets[seconds] += 1
            if buckets[seconds] > 1:
                return 0
        s = [i for i, cnt in enumerate(buckets) if cnt]
        return min(s2 - s1 for s1, s2 in zip(s, s[1:] + [1440 + s[0]]))
