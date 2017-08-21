# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def checkEqualTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def treesum(node):
            if not node:
                return 0
            s = node.val + treesum(node.left) + treesum(node.right)
            counter[s] += 1
            return s

        counter = collections.defaultdict(int)
        s = treesum(root)
        counter[s] -= 1
        return s % 2 == 0 and counter[s / 2] > 0

# 194 / 194 test cases passed.
# Status: Accepted
# Runtime: 152 ms
