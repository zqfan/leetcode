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
        def dfs(root, path):
            if not root:
                return
            if not root.left and not root.right:
                result.append(path + str(root.val))
            path = path + str(root.val) + "->"
            dfs(root.left, path)
            dfs(root.right, path)
        result = []
        dfs(root, "")
        return result
