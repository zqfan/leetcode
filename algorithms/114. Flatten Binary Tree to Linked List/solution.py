# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        def dfs(root):
            if root:
                dfs(root.right)
                dfs(root.left)
                root.left = None
                root.right = pre[0]
                pre[0] = root
        pre = [None]
        dfs(root)
