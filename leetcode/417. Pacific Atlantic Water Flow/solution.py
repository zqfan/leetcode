class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if not matrix:
            return []

        r = len(matrix); c = len(matrix[0])
        flag = [[0] * c for i in xrange(r)]
        dirs = [(-1,0),(0,1),(1,0),(0,-1)]

        def dfs(i, j, mask):
            flag[i][j] |= mask
            for d in dirs:
                x = i + d[0]; y = j + d[1]
                if (0 <= x < r and 0 <= y < c and flag[x][y] & mask == 0
                    and matrix[i][j] <= matrix[x][y]):
                    dfs(x, y, mask)

        for i in xrange(c):
            dfs(0, i, 1)
            dfs(r-1, i, 2)
        for i in xrange(r):
            dfs(i, 0, 1)
            dfs(i, c-1, 2)

        res = []
        for i in xrange(r):
            for j in xrange(c):
                if flag[i][j] == 3:
                    res.append([i,j])
        return res
