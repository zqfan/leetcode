class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        m = len(matrix)
        n = len(matrix[0])
        visit = [[0] * n for i in xrange(m)]
        dist = [[0] * n for i in xrange(m)]
        heap = []
        for i in xrange(m):
            for j in xrange(n):
                if matrix[i][j] == 0:
                    visit[i][j] = 1
                    dist[i][j] = 0
                    heapq.heappush(heap, (0, i, j))
        while heap:
            d, i, j = heapq.heappop(heap)
            for x, y in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
                x += i
                y += j
                if 0 <= x < m and 0 <= y < n and not visit[x][y]:
                    visit[x][y] = 1
                    dist[x][y] = d + 1
                    heapq.heappush(heap, (d + 1, x, y))
        return dist
