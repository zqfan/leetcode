# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        def dfs(root, h):
            if root:
                if h == len(result):
                    result.append([])
                result[h].append(root.val)
                dfs(root.left, h + 1)
                dfs(root.right, h + 1)
        result = []
        dfs(root, 0)
        return result
