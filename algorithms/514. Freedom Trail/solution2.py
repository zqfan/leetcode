class Solution(object):
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        dp = [[min(i, len(ring)-i) for i in xrange(len(ring))]]
        dp.extend([[float('inf')] * len(ring) for _ in xrange(len(key))])
        for i in xrange(1, len(key)+1):
            for j in xrange(len(ring)):
                if ring[j] != key[i-1]:
                    continue
                min_step = float('inf')
                for k in xrange(len(ring)):
                    if dp[i-1][k] == float('inf'):
                        continue
                    step = abs(k - j)
                    step = min(step, len(ring) - step) + 1 + dp[i-1][k]
                    min_step = min(min_step, step)
                dp[i][j] = min_step
        return min(dp[-1])
