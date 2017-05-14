class Solution(object):
    def findPaths(self, m, n, N, i, j):
        """
        :type m: int
        :type n: int
        :type N: int
        :type i: int
        :type j: int
        :rtype: int
        """
        MOD = 1000000007
        paths = 0
        cur = {(i, j): 1}
        for i in xrange(N):
            next = collections.defaultdict(int)
            for (x, y), cnt in cur.iteritems():
                for dx, dy in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
                    nx = x + dx
                    ny = y + dy
                    if nx < 0 or ny < 0 or nx >= m or ny >= n:
                        paths += cnt
                        paths %= MOD
                    else:
                        next[(nx, ny)] += cnt
                        next[(nx, ny)] %= MOD
            cur = next
        return paths

# 94 / 94 test cases passed.
# Status: Accepted
# Runtime: 232 ms
# beats 75.36 %
