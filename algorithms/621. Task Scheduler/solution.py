class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        c = collections.defaultdict(int)
        for t in tasks:
            c[t] += 1
        m = max(c.itervalues())
        l = len([k for k in c if c[k] == m])
        return max(len(tasks), (m - 1) * (n + 1) + l)

# 64 / 64 test cases passed.
# Status: Accepted
# Runtime: 682 ms
