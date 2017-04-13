# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        paths = []
        if not root:
            return []
        if not root.left and not root.right:
            return ["%s" % root.val]
        for path in self.binaryTreePaths(root.left):
            paths.append("%s->%s" % (root.val, path))
        for path in self.binaryTreePaths(root.right):
            paths.append("%s->%s" % (root.val, path))
        return paths
