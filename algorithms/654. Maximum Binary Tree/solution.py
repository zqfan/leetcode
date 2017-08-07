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
        s = []
        for n in nums:
            cur = TreeNode(n)
            while s and s[-1].val < n:
                cur.left = s.pop()
            if s:
                s[-1].right = cur
            s.append(cur)
        return s[0]

# 107 / 107 test cases passed.
# Status: Accepted
# Runtime: 192 ms
