# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        def dfs(root):
            if not root:
                return "null"
            return "%s,%s,%s" % (root.val, dfs(root.left), dfs(root.right))
        return (',' + dfs(s)).find(',' + dfs(t)) != -1

# 174 / 174 test cases passed.
# Status: Accepted
# Runtime: 95 ms
