# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        height = self.get_height(root)
        if height == 1:
            return 1
        right_height = self.get_height(root.right)
        if (right_height == height-1):
            return (1<<height-1) + self.countNodes(root.right)
        else:
            return (1<<height-2) + self.countNodes(root.left)

    def get_height(self, root):
        h = 0
        while root:
            h += 1
            root = root.left
        return h
