# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def dfs(root):
            if root and self.k > 0:
                dfs(root.left)
                self.k -= 1
                if self.k == 0:
                    self.n = root.val
                dfs(root.right)
        self.n, self.k = 0, k
        dfs(root)
        return self.n
                    
