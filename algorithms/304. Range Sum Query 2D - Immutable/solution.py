class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        m, n = len(matrix), len(matrix[0] if matrix else [])
        self._sum = [[0] * n for i in xrange(m)]
        col_sum = [0] * n
        for i in xrange(m):
            s = 0
            for j in xrange(n):
                col_sum[j] += matrix[i][j]
                s += col_sum[j]
                self._sum[i][j] = s

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        m, n = len(self._sum), len(self._sum[0] if self._sum else [])
        if not (0 <= row1 <= row2 < m and 0 <= col1 <= col2 < n):
            return 0
        s = self._sum[row2][col2]
        if row1 > 0:
            s -= self._sum[row1-1][col2]
        if col1 > 0:
            s -= self._sum[row2][col1-1]
        if row1 > 0 and col1 > 0:
            s += self._sum[row1-1][col1-1]
        return s


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
