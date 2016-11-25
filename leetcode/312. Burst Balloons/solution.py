class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # @dietpepsi
        remains = (1,) + tuple(filter(bool,nums)) + (1,)
        maxscores = [[0] * len(remains) for _ in xrange(len(remains))]
        for i in xrange(len(remains)-1, -1, -1):
            for j in xrange(i+2, len(remains)):
                maxscore = 0; bound_score = remains[i] * remains[j]
                for k in xrange(i+1, j):
                    score = bound_score * remains[k]
                    score += maxscores[i][k] + maxscores[k][j]
                    maxscore = max(maxscore, score)
                maxscores[i][j] = maxscore
        return maxscores[0][-1]

# 70 / 70 test cases passed.
# Status: Accepted
# Runtime: 412 ms
# 96.50%
