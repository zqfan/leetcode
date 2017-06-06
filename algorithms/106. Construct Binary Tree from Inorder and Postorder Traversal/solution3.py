# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if inorder:
            p = inorder.index(postorder.pop())
            root = TreeNode(inorder[p])
            root.right = self.buildTree(inorder[p+1:], postorder)
            root.left = self.buildTree(inorder[:p], postorder)
            return root

# 202 / 202 test cases passed.
# Status: Accepted
# Runtime: 212 ms
# beats 68.81 %
