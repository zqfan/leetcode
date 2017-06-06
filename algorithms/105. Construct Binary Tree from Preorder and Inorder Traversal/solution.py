# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def dfs(stop):
            if preorder and inorder[-1] != stop:
                root = TreeNode(preorder.pop())
                root.left = dfs(root.val)
                inorder.pop()
                root.right = dfs(stop)
                return root
        preorder, inorder = preorder[::-1], inorder[::-1]
        return dfs(None)

# 202 / 202 test cases passed.
# Status: Accepted
# Runtime: 89 ms
# beats 88.80 %
