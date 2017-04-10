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
        left = self.pathSum(root.left, sum)
        right = self.pathSum(root.right, sum)
        return self.rootSum(root, sum) + left + right

    def rootSum(self, root, sum):
        if not root:
            return 0
        left = self.rootSum(root.left, sum - root.val)
        right = self.rootSum(root.right, sum - root.val)
        return (root.val == sum) + left + right
