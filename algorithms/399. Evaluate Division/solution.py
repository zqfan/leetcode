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
        g = collections.defaultdict(
            lambda: collections.defaultdict(lambda: -1.0))
        for (p, q), l in zip(equations, values):
            g[p][q] = l
            g[q][p] = 1.0 / l
        for p in g:
            for q1 in g:
                for q2 in g:
                    if g[q1][p] > 0 and g[p][q2] > 0:
                        g[q1][q2] = g[q1][p] * g[p][q2]
            g[p][p] = 1.0
        return [g[p][q] for p, q in queries if g[p][q]]
