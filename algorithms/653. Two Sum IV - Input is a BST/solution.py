# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        counter = collections.defaultdict(int)
        def dfs(node):
            if node:
                counter[node.val] += 1
                dfs(node.left)
                dfs(node.right)
        dfs(root)
        for val in counter:
            if k - val == val:
                if counter[val] > 1:
                    return True
            elif k - val in counter:
                return True
        return False

# 421 / 421 test cases passed.
# Status: Accepted
# Runtime: 198 ms
