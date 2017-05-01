# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals.sort(key=lambda x: (x.end, x.start))
        removes = 0
        pre = float('-inf')
        for i in xrange(len(intervals)):
            if intervals[i].start < pre:
                removes += 1
            else:
                pre = intervals[i].end
        return removes
