# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root, n):
            if not root:
                return 0
            n = n * 10 + root.val
            if not root.left and not root.right:
                return n
            return dfs(root.left, n) + dfs(root.right, n)
        return dfs(root, 0)
