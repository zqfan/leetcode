# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values, stack = [], [root]
        while stack:
            root = stack.pop()
            if root:
                values.append(root.val)
                stack.append(root.right)
                stack.append(root.left)
        return values
