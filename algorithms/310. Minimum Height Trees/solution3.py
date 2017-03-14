class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def dfs_height(vertex, parent):
            for v in g[vertex]:
                if v == parent:
                    continue
                dfs_height(v, vertex)
                h = height[v] + 1
                if h > height[vertex]:
                    sub_height[vertex] = height[vertex]
                    height[vertex] = h
                elif h > sub_height[vertex]:
                    sub_height[vertex] = h

        def dfs_mht(vertex, parent, cur):
            dp[vertex] = max(height[vertex], cur)
            for v in g[vertex]:
                if v == parent:
                    continue
                if height[v] + 1 == height[vertex]:
                    h = sub_height[vertex]
                else:
                    h = height[vertex]
                dfs_mht(v, vertex, max(cur + 1, h + 1))

        if n <= 2:
            return range(n)
        g = collections.defaultdict(set)
        for e in edges:
            g[e[0]].add(e[1])
            g[e[1]].add(e[0])
        dp, height, sub_height = [0] * n, [0] * n, [0] * n
        dfs_height(0, -1)
        dfs_mht(0, -1, 0)
        minimal = min(dp)
        return [i for i in xrange(n) if dp[i] == minimal]
