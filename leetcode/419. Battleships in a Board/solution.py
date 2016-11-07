class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        ships = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X':
                    if i+1 < len(board) and board[i+1][j] == 'X':
                        continue
                    if j+1 < len(board[0]) and board[i][j+1] == 'X':
                        continue
                    ships += 1
        return ships
