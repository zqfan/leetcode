class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        p = 0; r = len(grid); c = len(grid[0])
        for i in range(r):
            for j in range(c):
                if not grid[i][j]:
                    continue
                p += 4
                if 0 <= i-1 and grid[i-1][j]:
                    p -= 1
                if j+1 < c and grid[i][j+1]:
                    p -= 1
                if i+1 < r and grid[i+1][j]:
                    p -= 1
                if 0 <= j-1 and grid[i][j-1]:
                    p -= 1
        return p
