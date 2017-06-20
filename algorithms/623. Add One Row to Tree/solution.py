# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        # inspired by @alexander
        if d < 2:
            node = TreeNode(v)
            node.left = root if d == 1 else None
            node.right = root if d == 0 else None
            return node
        elif root:
            root.left = self.addOneRow(root.left, v, d - 1 if d > 2 else 1)
            root.right = self.addOneRow(root.right, v, d - 1 if d > 2 else 0)
            return root
