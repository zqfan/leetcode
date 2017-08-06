# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        def serialize(node):
            if not node:
                return ""
            left = serialize(node.left)
            right = serialize(node.right)
            s = "%s,%s,%s" % (node.val, left, right)
            mem[s].append(node)
            return s
        mem = collections.defaultdict(list)
        serialize(root)
        return [nodes[0] for s, nodes in mem.iteritems() if len(nodes) > 1]

# 167 / 167 test cases passed.
# Status: Accepted
# Runtime: 105 ms
# beats 85.92 %
