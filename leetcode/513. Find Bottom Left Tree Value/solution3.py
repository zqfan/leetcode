# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        cur_lvl = [root]
        while cur_lvl:
            target = cur_lvl[0].val
            next_lvl = []
            for node in cur_lvl:
                next_lvl += filter(None, (node.left, node.right))
            cur_lvl = next_lvl
        return target
