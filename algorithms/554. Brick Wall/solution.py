class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        counter = collections.defaultdict(int)
        for row in wall:
            s = 0
            for j in xrange(len(row) - 1):
                s += row[j]
                counter[s] += 1
        maximum = max(counter.itervalues()) if counter else 0
        return len(wall) - maximum

# 85 / 85 test cases passed.
# Status: Accepted
# Runtime: 105 ms
