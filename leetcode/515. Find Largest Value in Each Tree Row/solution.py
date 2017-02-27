# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(node, height):
            if not node:
                return
            if height >= len(self.max_vals):
                self.max_vals.append(node.val)
            if node.val > self.max_vals[height]:
                self.max_vals[height] = node.val
            dfs(node.left, height + 1)
            dfs(node.right, height + 1)

        self.max_vals = []
        dfs(root, 0)
        return self.max_vals
