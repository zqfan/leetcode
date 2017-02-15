# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def find_modes(val):
            if val != self.cur_val:
                self.cur_val = val
                self.cur_cnt = 0
            self.cur_cnt += 1
            if self.cur_cnt > self.max_cnt:
                self.max_cnt = self.cur_cnt
            elif self.cur_cnt == self.max_cnt and self.modes is not None:
                self.modes.append(val)

        def inorder(node):
            if node:
                inorder(node.left)
                find_modes(node.val)
                inorder(node.right)

        self.cur_cnt = self.max_cnt = 0
        self.cur_val = self.modes = None
        inorder(root)
        self.cur_val = None
        self.cur_cnt = 0
        self.modes = []
        inorder(root)
        return self.modes
