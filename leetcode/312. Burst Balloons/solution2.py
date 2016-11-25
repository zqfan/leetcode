class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        remains = (1,) + tuple(filter(bool,nums)) + (1,)
        maxscores = [[0] * len(remains) for _ in xrange(len(remains))]
        def get_maxscore(left, right):
            if right - left < 2:
                return 0
            if maxscores[left][right]:
                return maxscores[left][right]
            maxscore = 0
            for i in xrange(left+1, right):
                score = remains[left] * remains[i] * remains[right]
                score += get_maxscore(left, i) + get_maxscore(i, right)
                maxscore = max(maxscore, score)
            maxscores[left][right] = maxscore
            return maxscore

        return get_maxscore(0, len(remains)-1)

# 70 / 70 test cases passed.
# Status: Accepted
# Runtime: 872 ms
# 28.02%
