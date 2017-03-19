class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(matrix), len(matrix[0])
        visit = [[0] * n for i in xrange(m)]
        dist = [[0] * n for i in xrange(m)]
        queue = collections.deque()
        for i in xrange(m):
            for j in xrange(n):
                if matrix[i][j] == 0:
                    visit[i][j] = 1
                    dist[i][j] = 0
                    queue.append((0, i, j))
        while queue:
            d, i, j = queue.popleft()
            for x, y in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
                x += i
                y += j
                if 0 <= x < m and 0 <= y < n and not visit[x][y]:
                    visit[x][y] = 1
                    dist[x][y] = d + 1
                    queue.append((d + 1, x, y))
        return dist
