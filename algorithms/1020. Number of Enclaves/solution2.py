class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        g = copy.deepcopy(A)
        m, n = len(g), len(g[0])
        q = []
        for i in range(n):
            if g[0][i] == 1:
                q.append((0, i))
            if g[m-1][i] == 1:
                q.append((m-1, i))
        for i in range(1, m-1):
            if g[i][0] == 1:
                q.append((i, 0))
            if g[i][n-1] == 1:
                q.append((i, n-1))
        while q:
            i, j = q.pop()
            if g[i][j] == 0:
                continue
            g[i][j] = 0
            for dx, dy in [[0,1],[1,0],[0,-1],[-1,0]]:
                x = i + dx
                y = j + dy
                if 0 < x < m and 0 < y < n and g[x][y] == 1:
                    q.append((x,y))
        return sum(sum(row) for row in g)
