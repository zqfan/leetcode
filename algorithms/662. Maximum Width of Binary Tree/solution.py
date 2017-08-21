# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node, h, w):
            if node:
                l[h].append(w)
                dfs(node.left, h + 1, w * 2)
                dfs(node.right, h + 1, w * 2 + 1)
        l = collections.defaultdict(list)
        dfs(root, 0, 0)
        return max(w[-1] - w[0] for h, w in l.iteritems()) + 1

# 108 / 108 test cases passed.
# Status: Accepted
# Runtime: 52 ms
