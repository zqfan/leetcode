# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class SummaryRanges(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # inspired by @	qianzhige
        self._intervals = []

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        s, l = self._intervals, len(self._intervals)
        p = bisect.bisect_left(s, [val, val])
        if p < l and s[p][0] == val:
            return
        if 0 < p < l and s[p-1][1] + 1 == val == s[p][0] - 1:
            s[p-1][1] = s[p][1]
            del s[p]
        elif 0 < p and s[p-1][1] + 1 >= val:
            s[p-1][1] = max(s[p-1][1], val)
        elif p < l and s[p][0] - 1 == val:
            s[p][0] -= 1
        else:
            s.insert(p, [val, val])

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        return self._intervals

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
