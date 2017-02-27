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
        def dfs(node, height):
            if height > self.height:
                self.height = height
                self.target = node.val
            if node.left:
                dfs(node.left, height + 1)
            if node.right:
                dfs(node.right, height + 1)

        self.height = self.target = 0
        dfs(root, 1)
        return self.target
