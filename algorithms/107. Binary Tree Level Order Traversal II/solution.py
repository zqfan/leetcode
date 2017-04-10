# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        cur = [root] if root else []
        while cur:
            levels.append([node.val for node in cur])
            cur = [x for n in cur for x in (n.left, n.right) if x]
        return levels[::-1]
