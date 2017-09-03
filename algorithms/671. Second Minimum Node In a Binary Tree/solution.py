# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node):
            if node:
                s.add(node.val)
                dfs(node.left)
                dfs(node.right)
        s = set()
        dfs(root)
        s.remove(min(s))
        return min(s) if s else -1

# 34 / 34 test cases passed.
# Status: Accepted
# Runtime: 36 ms
