# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(node, h):
            path = []
            while node:
                path.append(node)
                node = node.left
            if len(path) < h:
                return len(path)-1, 0, None
            if len(path) == 1:
                return 0, 1, None
            path.reverse()
            l = 0; r = len(path)-1
            while l < r:
                k = m = (l + r) / 2
                cur = path[m]
                while k > 0:
                    cur = cur.right
                    k -= 1
                if cur:
                    l = m + 1
                else:
                    r = m
            return len(path)-1, l, path[l].right

        bottom = 0; height = 0; b = 1
        while root:
            h, b, root = helper(root, b)
            height = max(height, h)
            if b > 0:
                bottom += 1<<(b-1)
        return (1<<height)-1+bottom
