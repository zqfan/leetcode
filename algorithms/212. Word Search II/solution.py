class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        def dfs(i, j, prefix, trie):
            if board[i][j] not in trie:
                return
            if None in trie[board[i][j]]:
                exist_words.add(prefix + board[i][j])
            visit[i][j] = 1
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if not (0 <= x < m and 0 <= y < n and visit[x][y] == 0):
                    continue
                dfs(x, y, prefix+board[i][j], trie[board[i][j]])
            visit[i][j] = 0

        trie = {}
        for word in words:
            cur = trie
            for char in word:
                cur[char] = cur.get(char, {})
                cur = cur[char]
            cur[None] = 1
        r = set(); m = len(board); n = len(board[0])
        visit = [[0] * n for _ in xrange(m)]
        dirs = [[-1,0],[0,1],[1,0],[0,-1]]
        for i in xrange(m):
            for j in xrange(n):
                exist_words = set()
                dfs(i, j, '', trie)
                r.update(exist_words)
        return list(r)
# 37 / 37 test cases passed.
# Status: Accepted
# Runtime: 422 ms
# 95.24%
