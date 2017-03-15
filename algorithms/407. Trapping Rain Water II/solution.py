class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        # based on @shenggu
        m, n = len(heightMap), len(heightMap[0]) if heightMap else 0
        visited = [[0] * n for i in xrange(m)]
        candidates = []
        for i in xrange(m):
            for j in xrange(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    visited[i][j] = 1
                    heapq.heappush(candidates, (heightMap[i][j], i, j))
        water = 0
        while candidates:
            h, i, j = heapq.heappop(candidates)
            for x, y in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
                x, y = i + x, j + y
                if 0 <= x < m and 0 <= y < n and not visited[x][y]:
                    water += max(0, h - heightMap[x][y])
                    visited[x][y] = 1
                    heapq.heappush(candidates, (max(heightMap[x][y], h), x, y))
        return water
