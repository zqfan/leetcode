class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        incoming = collections.defaultdict(set)
        outgoing = collections.defaultdict(set)
        for p in prerequisites:
            incoming[p[1]].add(p[0])
            outgoing[p[0]].add(p[1])
        s = [v for v in outgoing if v not in incoming]
        r = []
        while s:
            n = s.pop()
            for m in outgoing[n]:
                incoming[m].remove(n)
                if not incoming[m]:
                    incoming.pop(m)
                    s.append(m)
            outgoing.pop(n)
            r.append(n)
        if incoming:
            return []
        r.reverse()
        return r + list(set(xrange(numCourses))-set(r))

# 36 / 36 test cases passed.
# Status: Accepted
# Runtime: 68 ms
# 86.56%
