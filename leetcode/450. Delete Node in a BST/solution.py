# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            cur = root.left; pre = None
            while cur and cur.right:
                pre = cur
                cur = cur.right
            if not cur:
                root = root.right
            elif cur == root.left:
                root.val = root.left.val
                root.left = cur.left
            else:
                pre.right = cur.left
                root.val = cur.val
        return root

# 84 / 84 test cases passed.
# Status: Accepted
# Runtime: 105 ms
# 77.63%
