class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n:
                return
            if visited[i][j] or grid[i][j] == '0':
                return
            visited[i][j] = 1
            for dx, dy in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
                dfs(i + dx, j + dy)

        m, n = len(grid), len(grid[0]) if grid else 0
        visited = [[0] * n for i in xrange(m)]
        islands = 0
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    dfs(i, j)
                    islands += 1
        return islands
