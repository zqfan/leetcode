class Solution(object):
    def minDistance(self, height, width, tree, squirrel, nuts):
        """
        :type height: int
        :type width: int
        :type tree: List[int]
        :type squirrel: List[int]
        :type nuts: List[List[int]]
        :rtype: int
        """
        totalMoves = 0
        saveMove = float('-inf')
        for x, y in nuts:
            move2tree = abs(tree[0] - x) + abs(tree[1] - y)
            move2squirrel = abs(squirrel[0] - x) + abs(squirrel[1] - y)
            totalMoves += 2 * move2tree
            saveMove = max(saveMove, move2tree - move2squirrel)
        return totalMoves - saveMove
