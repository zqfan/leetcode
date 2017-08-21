class Solution(object):
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(M), len(M[0])
        r = [[0] * n for i in xrange(m)]
        for i in xrange(m):
            for j in xrange(n):
                c = 0
                for ni in xrange(i-1, i+2):
                    for nj in xrange(j-1, j+2):
                        if 0 <= ni < m and 0 <= nj < n:
                            r[i][j] += M[ni][nj]
                            c += 1
                r[i][j] /= c
        return r

# 202 / 202 test cases passed.
# Status: Accepted
# Runtime: 939 ms
