class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        m, n = len(A), len(A[0])
        g = copy.deepcopy(A)
        def dfs(i, j):
            g[i][j] = 0
            for x, y in ((i-1, j), (i, j+1), (i+1, j), (i, j-1)):
                if 0 <= x < m and 0 <= y < n and g[x][y] == 1:
                    dfs(x, y)
        for i in range(m):
            for j in range(n):
                if (i == 0 or j == 0 or i == m - 1 or j == n - 1) and g[i][j] == 1:
                    dfs(i, j)
        return sum(sum(row) for row in g)
