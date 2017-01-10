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
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            else:
                cur = root.left
                while cur and cur.right:
                    cur = cur.right
                root.val = cur.val
                root.left = self.deleteNode(root.left, root.val)
        return root

# 84 / 84 test cases passed.
# Status: Accepted
# Runtime: 102 ms
# 84.93%
