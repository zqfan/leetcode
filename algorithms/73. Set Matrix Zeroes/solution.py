class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0]) if matrix else 0
        col0 = 1
        for i in xrange(m):
            if matrix[i][0] == 0:
                col0 = 0
            for j in xrange(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        for i in xrange(m-1, -1, -1):
            for j in xrange(1, n):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0
            if col0 == 0:
                matrix[i][0] = 0
