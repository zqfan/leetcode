class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        # @StefanPochmann
        A = [[0] * n for i in xrange(n)]
        i, j, di, dj = 0, 0, 0, 1
        for k in xrange(1, n * n + 1):
            A[i][j] = k
            if A[(i + di) % n][(j + dj) % n]:
                di, dj = dj, -di
            i += di
            j += dj
        return A
