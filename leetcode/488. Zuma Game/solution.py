class Solution(object):
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        def dfs(board, hand):
            if not board:
                history[board] = 0
            if board in history:
                return history[board]
            minimal = -1
            for i in xrange(len(board)):
                for j in xrange(len(hand)):
                    # zuma rule, we don't want to introduce new chaos
                    if board[i] != hand[j]:
                        continue
                    new_board = board[:i] + hand[j] + board[i:]
                    new_board = self.remove_balls(new_board)
                    new_hand = hand[:j] + hand[j+1:]
                    step = dfs(new_board, new_hand)
                    if step >= 0 and (minimal == -1 or minimal > step + 1):
                        minimal = step + 1
            history[board] = minimal
            return minimal
        # we can do input check to skip some impossible case
        # we can do minimal check to skip some larger step process
        history = {}
        return dfs(board, hand)

    def remove_balls(self, board):
        count = start = pre = 0
        for i, ball in enumerate(board):
            if ball == pre:
                count += 1
            elif count < 2:
                pre = ball
                count = 0
                start = i
            else:
                break
        if count >= 2:
            end = start + count + 1
            new_board = board[:start] + board[end:]
            return self.remove_balls(new_board)
        else:
            return board
