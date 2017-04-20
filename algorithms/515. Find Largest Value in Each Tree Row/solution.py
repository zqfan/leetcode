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
        def dfs(root, h):
            if root:
                if h >= len(result):
                    result.append(root.val)
                result[h] = max(result[h], root.val)
                dfs(root.left, h + 1)
                dfs(root.right, h + 1)
        result = []
        dfs(root, 0)
        return result
