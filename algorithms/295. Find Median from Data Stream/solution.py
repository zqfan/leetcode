class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.smallhalf = []
        self.largehalf = []

    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if len(self.largehalf) == len(self.smallhalf):
            if not self.largehalf or num >= self.largehalf[0]:
                heapq.heappush(self.largehalf, num)
            else:
                heapq.heappush(self.smallhalf, -num)
                n = heapq.heappop(self.smallhalf)
                heapq.heappush(self.largehalf, -n)
        else:
            if num > self.largehalf[0]:
                heapq.heappush(self.largehalf, num)
                n = heapq.heappop(self.largehalf)
                heapq.heappush(self.smallhalf, -n)
            else:
                heapq.heappush(self.smallhalf, -num)

    def findMedian(self):
        """
        Returns the median of current data stream
        :rtype: float
        """
        if len(self.largehalf) > len(self.smallhalf):
            return self.largehalf[0] / 1.0
        else:
            return (self.largehalf[0] - self.smallhalf[0]) / 2.0

# Your MedianFinder object will be instantiated and called as such:
# mf = MedianFinder()
# mf.addNum(1)
# mf.findMedian()

# 18 / 18 test cases passed.
# Status: Accepted
# Runtime: 342 ms
# 79.95%
