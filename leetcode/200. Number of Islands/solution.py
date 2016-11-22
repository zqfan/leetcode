class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0

        dirs = [(-1,0),(0,1),(1,0),(0,-1)]
        r = len(grid); c = len(grid[0])
        flag = [[0] * c for i in xrange(r)]
        for i in xrange(r):
            for j in xrange(c):
                flag[i][j] = int(grid[i][j])

        def dfs(i, j):
            flag[i][j] = 0
            for d in dirs:
                x = i + d[0]; y = j + d[1]
                if 0 <= x < r and 0 <= y < c and flag[x][y]:
                    dfs(x, y)

        islands = 0
        for i in xrange(r):
            for j in xrange(c):
                if flag[i][j]:
                    islands += 1
                    dfs(i, j)

        return islands
