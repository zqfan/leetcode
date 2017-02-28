# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            self.min_diff = min(self.min_diff, node.val - self.pre)
            self.pre = node.val
            dfs(node.right)

        self.pre, self.min_diff = -float('inf'), float('inf')
        dfs(root)
        return self.min_diff
