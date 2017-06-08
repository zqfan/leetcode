# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        # @StefanPochmann
        def node(val, left, right):
            root = TreeNode(val)
            root.left = left
            root.right = right
            return root
        def gen(start, end):
            return [node(val, left, right)
                    for val in xrange(start, end+1)
                    for left in gen(start, val-1)
                    for right in gen(val+1, end)] or [None]
        return gen(1, n) if n > 0 else []
