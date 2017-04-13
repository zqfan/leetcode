class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        row = [1] * (rowIndex + 1)
        for i in xrange(2, rowIndex + 1):
            for j in xrange(i - 1, 0, -1):
                row[j] += row[j-1]
        return row
