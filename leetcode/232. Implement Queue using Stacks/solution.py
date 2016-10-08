class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self._data = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self._data.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        self._data.pop(0)

    def peek(self):
        """
        :rtype: int
        """
        return self._data[0]

    def empty(self):
        """
        :rtype: bool
        """
        return len(self._data) == 0