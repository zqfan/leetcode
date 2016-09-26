# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        # leaf node alreay checked in parent call
        if not (root.left or root.right):
            return 0
        if not root.left:
            left_sum = 0
        elif not (root.left.left or root.left.right):
            left_sum = root.left.val
        else:
            left_sum = self.sumOfLeftLeaves(root.left)
        right_sum = self.sumOfLeftLeaves(root.right)
        return left_sum + right_sum
