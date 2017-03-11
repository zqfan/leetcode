class Solution(object):
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        def dfs(board, hand):
            if not board:
                return 0
            if board in history:
                return history[board]
            # we can do minimal check to skip some larger step process
            minimal = -1
            for i in xrange(len(board)):
                for j in xrange(len(hand)):
                    # zuma rule, we don't want to introduce new chaos
                    if board[i] != hand[j]:
                        continue
                    new_board = board[:i] + hand[j] + board[i:]
                    reduced_board = self.remove_balls(new_board)
                    step = dfs(reduced_board, hand[:j] + hand[j+1:])
                    if step >= 0 and (minimal == -1 or minimal > step + 1):
                        minimal = step + 1
            return history.setdefault(board, minimal)
        # we can do input check to skip some impossible case, for one or two balls
        history = {}
        return dfs(board, hand)

    def remove_balls(self, board):
        # we can do one pass check to accelerate it
        for dup in ['R'*3, 'G'*3, 'B'*3, 'Y'*3, 'W'*3]:
            start, end = board.find(dup), board.rfind(dup) + 3
            if start != -1:
                return self.remove_balls(board[:start] + board[end:])
        return board
