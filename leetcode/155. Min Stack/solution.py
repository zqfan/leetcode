class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self._data = []
        # when push a new x, we record current min num's pos
        self._min_indexes = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if not self._data:
            min_index = 0
            min_num = x
        else:
            min_index = self._min_indexes[-1]
            min_num = self._data[min_index]

        if x < min_num:
            min_index = len(self._data)

        self._min_indexes.append(min_index)
        self._data.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if self._data:
            self._data.pop()
            self._min_indexes.pop()

    def top(self):
        """
        :rtype: int
        """
        if self._data:
            return self._data[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if self._data:
            return self._data[self._min_indexes[-1]]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
