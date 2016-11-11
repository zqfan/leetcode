# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        s = [(e.start, i) for i, e in enumerate(intervals)]
        s.sort()
        indices = []
        for i in intervals:
            # binary search for right intervals
            l = 0
            r = len(intervals)-1
            m = (l + r) / 2
            while l < r:
                if s[m][0] < i.end:
                    l = m + 1
                elif s[m][0] > i.end:
                    r = m
                else:
                    break
                m = (l + r) / 2
            if s[m][0] >= i.end:
                indices.append(s[m][1])
            else:
                indices.append(-1)
        return indices
