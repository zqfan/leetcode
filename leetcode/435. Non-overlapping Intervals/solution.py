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
        if not intervals:
            return 0
        intervals.sort(key=lambda o: o.start)  # use sorted in real case
        removes = 0
        end = intervals[0].end
        for i in intervals:
            if i.start < end:
                removes += 1
                end = min(end, i.end)
            else:
                end = i.end
        return removes - 1
