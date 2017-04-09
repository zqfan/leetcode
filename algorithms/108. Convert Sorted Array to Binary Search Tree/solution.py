# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def dfs(start, end):
            if start >= end:
                return None
            m = (start + end) / 2
            root = TreeNode(nums[m])
            root.left = dfs(start, m)
            root.right = dfs(m + 1, end)
            return root
        return dfs(0, len(nums))

# 32 / 32 test cases passed.
# Status: Accepted
# Runtime: 119 ms
