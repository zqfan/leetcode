class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not matrix:
            return 0

        directions = [[-1,0],[0,1],[1,0],[0,-1]]
        m = len(matrix)
        n = len(matrix[0])
        lips = [[0] * n for _ in xrange(m)]

        def dfs(i, j):
            lips[i][j] = 1
            for d in directions:
                x = i + d[0]
                y = j + d[1]
                if 0 <= x < m and 0 <= y < n and matrix[i][j] > matrix[x][y]:
                    if lips[x][y]:
                        lips[i][j] = max(lips[i][j], lips[x][y]+1)
                    else:
                        lips[i][j] = max(lips[i][j], dfs(x, y)+1)
            return lips[i][j]

        maxlip = 0
        for i in xrange(m):
            for j in xrange(n):
                if lips[i][j] == 0:
                    dfs(i, j)
                maxlip = max(maxlip, lips[i][j])
        return maxlip

# 137 / 137 test cases passed.
# Status: Accepted
# Runtime: 399 ms
# 82.38%
