# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def str2tree(self, s):
        """
        :type s: str
        :rtype: TreeNode
        """
        if not s:
            return None
        cnt, left_start = 0, len(s)
        for i, char in enumerate(s):
            if char == '(':
                cnt += 1
                if left_start == len(s):
                    left_start = i
            elif char == ')':
                cnt -= 1
                if cnt == 0:
                    break
        root = TreeNode(int(s[:left_start]))
        root.left = self.str2tree(s[left_start+1:i])
        root.right = self.str2tree(s[i+2:-1])
        return root
