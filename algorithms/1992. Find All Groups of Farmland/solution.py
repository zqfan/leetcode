class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        visited = [[0] * n for _ in range(m)]
        result = []
        for r1 in range(m):
            for c1 in range(n):
                if not land[r1][c1] or visited[r1][c1]:
                    continue
                r2, c2 = r1, c1
                while c2 + 1 < n and land[r1][c2 + 1]:
                    c2 += 1
                while r2 + 1 < m and land[r2 + 1][c2]:
                    r2 += 1
                result.append([r1, c1, r2, c2])
                for i in range(r1, r2 + 1):
                    for j in range(c1, c2 + 1):
                        visited[i][j] = 1
        return result
