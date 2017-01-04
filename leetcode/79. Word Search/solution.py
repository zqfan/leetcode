class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(i, j, idx):
            if board[i][j] != word[idx]:
                return False
            if idx == len(word)-1:
                return True
            visit[i][j] = 1
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if not (0 <= x < m and 0 <= y < n and visit[x][y] == 0):
                    continue
                if dfs(x, y, idx+1):
                    return True
            visit[i][j] = 0
            return False

        if not board:
            return False
        dirs = [[-1,0],[0,1],[1,0],[0,-1]]
        m = len(board); n = len(board[0])
        visit = [[0] * n for i in xrange(m)]
        for i in xrange(m):
            for j in xrange(n):
                if dfs(i, j, 0):
                    return True
        return False

# 87 / 87 test cases passed.
# Status: Accepted
# Runtime: 272 ms
# 91.50%
