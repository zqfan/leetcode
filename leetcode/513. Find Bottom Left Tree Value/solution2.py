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
        # @StefanPochmann
        queue = [root]
        for node in queue:
            queue += filter(None, (node.right, node.left))
        return node.val
