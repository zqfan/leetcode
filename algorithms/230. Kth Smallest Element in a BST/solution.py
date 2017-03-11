# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        return self.find_k(root, k)[0]

    def find_k(self, root, k):
        """find kth num in O(n) time."""
        if not root:
            return None, 0
        if not root.left and not root.right:
            return (root.val, 1) if k == 1 else (None, 1)
        target, count_left = self.find_k(root.left, k)
        if target is not None:
            return target, None
        elif count_left == (k - 1):
            return root.val, None
        target, count_right = self.find_k(root.right, k - count_left - 1)
        if target is not None:
            return target, None
        else:
            return None, count_left + count_right + 1
