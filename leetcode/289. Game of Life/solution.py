class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            retrn
        r = len(board); c = len(board[0])
        for i in xrange(r):
            for j in xrange(c):
                l = 0
                if i-1 >= 0 and j-1 >= 0 and board[i-1][j-1] > 0:
                    l += 1
                if i-1 >= 0 and board[i-1][j] > 0:
                    l += 1
                if i-1 >= 0 and j+1 < c and board[i-1][j+1] > 0:
                    l += 1
                if j+1 < c and board[i][j+1] > 0:
                    l += 1
                if i+1 < r and j+1 < c and board[i+1][j+1] > 0:
                    l += 1
                if i+1 < r and board[i+1][j] > 0:
                    l += 1
                if i+1 < r and j-1 >= 0 and board[i+1][j-1] > 0:
                    l += 1
                if j-1 >= 0 and board[i][j-1] > 0:
                    l += 1
                if board[i][j] > 0:
                    board[i][j] = l or 1
                else:
                    board[i][j] = -l
        for i in xrange(r):
            for j in xrange(c):
                if 0 < board[i][j] < 2 or board[i][j] > 3:
                    board[i][j] = 0
                elif 2 <= board[i][j] <= 3 or board[i][j] == -3:
                    board[i][j] = 1
                else:
                    board[i][j] = 0
