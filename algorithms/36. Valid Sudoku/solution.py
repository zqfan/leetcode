class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        unique = []
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val != '.':
                    unique += [(i, val), (val, j), (i/3, j/3, val)]
        return len(unique) == len(set(unique))
