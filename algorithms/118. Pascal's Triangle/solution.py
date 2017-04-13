class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        p = [[1]]
        for i in xrange(1, numRows):
            p.append(map(operator.add, [0] + p[-1], p[-1] + [0]))
        return p[:numRows]
