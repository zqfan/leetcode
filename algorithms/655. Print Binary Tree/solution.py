# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        def h(node):
            if not node:
                return 0
            return max(h(node.left), h(node.right)) + 1

        def write(node, h, w, w0):
            if node:
                matrix[h][w0 + w/2] = str(node.val)
                write(node.left, h + 1, w / 2, w0)
                write(node.right, h + 1, w / 2, w0 + w / 2 + 1)

        height = h(root)
        matrix = [[""] * (2 ** height - 1) for i in xrange(height)]
        write(root, 0, 2 ** height - 1, 0)
        return matrix

# 73 / 73 test cases passed.
# Status: Accepted
# Runtime: 45 ms
