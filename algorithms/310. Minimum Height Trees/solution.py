class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        g = collections.defaultdict(set)
        for e in edges:
            g[e[0]].add(e[1])
            g[e[1]].add(e[0])
        while len(g) > 2:
            for v in [v for v in g if len(g[v]) == 1]:
                g[g[v].pop()].remove(v)
                g.pop(v)
        return g.keys() or range(n)
