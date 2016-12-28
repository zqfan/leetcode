class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m = len(dungeon); n = len(dungeon[0])
        hp = [[sys.maxsize]*(n+1) for i in xrange(m+1)]
        hp[m][n-1] = hp[m-1][n] = 1
        for i in xrange(m-1, -1, -1):
            for j in xrange(n-1, -1, -1):
                hp[i][j] = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j]
                if hp[i][j] <= 0:
                    hp[i][j] = 1
        return hp[0][0]
