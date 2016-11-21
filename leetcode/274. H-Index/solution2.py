class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort()
        l = len(citations)
        for i in xrange(l):
            if citations[i] >= l - i:
                return l - i
        return 0
