# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def dfs(root):
            if root:
                dfs(root.right)
                root.val = total[0] = total[0] + root.val
                dfs(root.left)
        total = [0]
        dfs(root)
        return root
