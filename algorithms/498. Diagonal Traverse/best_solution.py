class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        n = len(matrix and matrix[0])
        res = [0] * (m * n)
        d = 1
        r = c = 0
        for i in xrange(m * n):
            res[i] = matrix[r][c]
            r -= d
            c += d
            if r >= m:
                r -= 1
                c += 2
                d = -d
            if c >= n:
                c -= 1
                r += 2
                d = -d
            if r < 0:
                r = 0
                d = -d
            if c < 0:
                c = 0
                d = -d
        return res
