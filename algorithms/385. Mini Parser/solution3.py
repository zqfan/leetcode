# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
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

class Solution(object):
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        # @StefanPochmann
        def genNestedInteger():
            num = ''
            while s[-1] in '0123456789-':
                num += s.pop()
            if num:
                return NestedInteger(int(num))
            s.pop()
            ni = NestedInteger()
            while s[-1] != ']':
                ni.add(genNestedInteger())
                if s[-1] == ',':
                    s.pop()
            s.pop()
            return ni
        s = list(' ' + s[::-1])
        return genNestedInteger()

# 57 / 57 test cases passed.
# Status: Accepted
# Runtime: 192 ms
# beats 57.40 %
