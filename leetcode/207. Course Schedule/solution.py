class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        incoming = collections.defaultdict(set)
        outgoing = collections.defaultdict(set)
        for p in prerequisites:
            incoming[p[1]].add(p[0])
            outgoing[p[0]].add(p[1])
        s = [v for v in outgoing if v not in incoming]
        while s:
            n = s.pop()
            for m in outgoing[n]:
                incoming[m].remove(n)
                if not incoming[m]:
                    incoming.pop(m)
                    s.append(m)
            outgoing.pop(n)
        return not bool(incoming)

# 35 / 35 test cases passed.
# Status: Accepted
# Runtime: 65 ms
# 64.16%
