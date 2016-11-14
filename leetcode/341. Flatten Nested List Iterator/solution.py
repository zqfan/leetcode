# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self._stack = collections.deque()
        self._stack.append(iter(nestedList))
        self._integer = None
        self._adjust()

    def _adjust(self):
        if not self._stack:
            return
        try:
            e = self._stack[-1].next()
            if e.isInteger():
                self._integer = e.getInteger()
            else:
                self._stack.append(iter(e.getList()))
                self._adjust()
        except:
            self._stack.pop()
            self._adjust()

    def next(self):
        """
        :rtype: int
        """
        t, self._integer = None, t
        self._adjust()
        return t

    def hasNext(self):
        """
        :rtype: bool
        """
        return self._integer is not None

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
