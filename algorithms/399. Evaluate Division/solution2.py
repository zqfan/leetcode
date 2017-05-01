class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        # the relationship of these string can be treated as a
        # graphic, the division value is the shortest path length,
        # but this time, we use * instead of +
        g = collections.defaultdict(dict)
        for (p, q), v in zip(equations, values):
            g[p][p] = g[q][q] = 1.0
            g[p][q] = v
            g[q][p] = 1.0 / v
        for i in g:
            for j in g:
                for k in g:
                    if k in g[i] and j in g[k]:
                        g[i][j] = g[i][k] * g[k][j]
        return [g[p].get(q, -1.0) for p, q in queries]
