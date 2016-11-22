# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        # input check
        if not p and not q:
            return

        if not p and q:
            return None if q.left and q.right else q

        if not q and p:
            return None if p.left and p.right else p

        # recursive start here
        if not root:
            return

        find_p = root == p
        find_q = root == q

        self.find_p = self.find_q = False
        lca = self.lowestCommonAncestor(root.left, p, q)
        if self.find_p and self.find_q:
            return lca

        find_p = find_p or self.find_p
        find_q = find_q or self.find_q

        self.find_p = self.find_q = False
        lca = self.lowestCommonAncestor(root.right, p, q)
        if self.find_p and self.find_q:
            return lca

        self.find_p = find_p or self.find_p
        self.find_q = find_q or self.find_q
        return root
