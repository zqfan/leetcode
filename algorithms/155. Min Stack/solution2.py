class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.desc = []
        self.data = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.data.append(x)
        if not self.desc or self.desc[-1] >= x:
            self.desc.append(x)

    def pop(self):
        """
        :rtype: void
        """
        val = self.data.pop()
        if self.desc[-1] == val:
            self.desc.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.data[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.desc[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
