class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        # @StefanPochmann
        g = collections.defaultdict(list)
        for start, end in sorted(tickets, reverse=True):
            g[start].append(end)
        path, stack = [], ['JFK']
        while stack:
            while g[stack[-1]]:
                stack.append(g[stack[-1]].pop())
            path.append(stack.pop())
        return path[::-1]

# 79 / 79 test cases passed.
# Status: Accepted
# Runtime: 99 ms
# 61.08%
