# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return []
        result = []
        intervals = sorted(intervals, key=lambda x: (x.start, x.end))
        start, end = intervals[0].start, intervals[0].end
        for i in xrange(1, len(intervals)):
            if end >= intervals[i].start:
                end = max(end, intervals[i].end)
            else:
                result.append(Interval(start, end))
                start, end = intervals[i].start, intervals[i].end
        result.append(Interval(start, end))
        return result

# 169 / 169 test cases passed.
# Status: Accepted
# Runtime: 82 ms
# beats 83.68 %
