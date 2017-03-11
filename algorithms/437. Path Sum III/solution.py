# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:
            return 0
        if not root.left and not root.right:
            return 1 if root.val == sum else 0
        s = (self.pathSum(root.left, sum) +
             self.pathSum(root.right, sum) +
             self.path_sum_wr(root.left, sum - root.val) +
             self.path_sum_wr(root.right, sum - root.val))
        if root.val == sum:
            s += 1
        return s

    def path_sum_wr(self, root, sum):
        if not root:
            return 0
        if not root.left and not root.right:
            return 1 if root.val == sum else 0
        s = (self.path_sum_wr(root.left, sum - root.val) +
             self.path_sum_wr(root.right, sum - root.val))
        if root.val == sum:
            s += 1
        return s
