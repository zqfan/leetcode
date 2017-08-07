# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if nums:
            root, idx = TreeNode(max(nums)), nums.index(max(nums))
            root.left = self.constructMaximumBinaryTree(nums[:idx])
            root.right = self.constructMaximumBinaryTree(nums[idx+1:])
            return root

# 107 / 107 test cases passed.
# Status: Accepted
# Runtime: 262 ms
