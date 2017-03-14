class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def bfs(start):
            visited, dist, pre = [0] * n, [0] * n, [-1] * n
            visited[start] = 1
            q = [start]
            while q:
                v = q.pop()
                for u in g[v]:
                    if not visited[u]:
                        visited[u] = 1
                        dist[u] = dist[v] + 1
                        pre[u] = v
                        q.append(u)
            return dist, pre

        if n <= 2:
            return range(n)
        g = collections.defaultdict(set)
        for e in edges:
            g[e[0]].add(e[1])
            g[e[1]].add(e[0])
        dist, pre = bfs(0)
        _, start = max(zip(dist, xrange(n)))
        dist, pre = bfs(start)
        length, mid = max(zip(dist, xrange(n)))
        for i in xrange(length / 2):
            mid = pre[mid]
        return [mid, pre[mid]] if length & 1 else [mid]
