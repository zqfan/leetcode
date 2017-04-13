# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def depth(root):
            if not root:
                return 0
            left = depth(root.left)
            right = depth(root.right)
            if abs(left - right) > 1:
                balanced[0] = False
            return max(left, right) + 1
        balanced = [True]
        depth(root)
        return balanced[0]
