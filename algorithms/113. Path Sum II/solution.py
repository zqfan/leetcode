# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def dfs(root, target):
            if not root:
                return
            if not root.left and not root.right:
                if target == root.val:
                    res.append(path + [root.val])
                return
            path.append(root.val)
            dfs(root.left, target - root.val)
            dfs(root.right, target - root.val)
            path.pop()
        res, path = [], []
        dfs(root, sum)
        return res

# 114 / 114 test cases passed.
# Status: Accepted
# Runtime: 66 ms
# beats 96.94 %
