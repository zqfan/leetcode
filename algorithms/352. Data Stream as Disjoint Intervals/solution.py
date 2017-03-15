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
        # inspired by @haoc
        self._interval = []

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        heapq.heappush(self._interval, [val, val])

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        stack = []
        while self._interval:
            start, end = heapq.heappop(self._interval)
            if stack and stack[-1][1] + 1 >= start:
                stack[-1][1] = max(stack[-1][1], end)
            else:
                stack.append([start, end])
        self._interval = stack
        return stack

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
