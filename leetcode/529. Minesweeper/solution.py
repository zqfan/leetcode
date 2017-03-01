class Solution(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        if board[click[0]][click[1]] == 'M':
            board[click[0]][click[1]] = 'X'
            return board
        dirs = [(-1, 0), (-1, 1), (0, 1), (1, 1),
                (1, 0), (1, -1), (0, -1), (-1, -1)]
        unreveal_empty_cells = []
        mine_cnt = 0
        for d in dirs:
            x, y = click[0] + d[0], click[1] + d[1]
            if 0 <= x < len(board) and 0 <= y < len(board[0]):
                if board[x][y] == 'M':
                    mine_cnt += 1
                elif board[x][y] == 'E':
                    unreveal_empty_cells.append([x, y])
        if mine_cnt != 0:
            board[click[0]][click[1]] = str(mine_cnt)
        else:
            board[click[0]][click[1]] = 'B'
            for cell in unreveal_empty_cells:
                self.updateBoard(board, cell)
        return board
