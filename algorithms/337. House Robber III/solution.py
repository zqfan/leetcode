# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    history = {}

    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        if root in self.history:
            return self.history.get(root)

        if not root.left and not root.right:
            return self.history.setdefault(root, root.val)

        no_rob_root = self.rob(root.left) + self.rob(root.right)
        rob_root = root.val
        if root.left:
            rob_root += self.rob(root.left.left) + self.rob(root.left.right)
        if root.right:
            rob_root += self.rob(root.right.left) + self.rob(root.right.right)

        return self.history.setdefault(root, max(no_rob_root, rob_root))
