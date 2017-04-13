class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows < 1:
            return []
        result = [[1]]
        for i in xrange(1, numRows):
            result.append([1])
            for j in xrange(1, i):
                result[-1].append(result[-2][j-1] + result[-2][j])
            result[-1].append(1)
        return result
