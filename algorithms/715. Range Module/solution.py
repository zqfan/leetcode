class RangeModule(object):

    def __init__(self):
        # @StefanPochmann
        self.numbers = [0, 1e9]
        self.track = [0, 0]

    def addRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        self._mark(left, right, 1)

    def queryRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: bool
        """
        i = bisect.bisect(self.numbers, left) - 1
        j = bisect.bisect_left(self.numbers, right)
        return all(self.track[i:j])

    def removeRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        self._mark(left, right, 0)

    def _mark(self, left, right, track):
        def index(n):
            p = bisect.bisect_left(self.numbers, n)
            if self.numbers[p] != n:
                self.numbers.insert(p, n)
                self.track.insert(p, self.track[p-1])
            return p
        i = index(left)
        j = index(right)
        self.numbers[i:j] = [left]
        self.track[i:j] = [track]

# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)

# 53 / 53 test cases passed.
# Status: Accepted
# Runtime: 762 ms
