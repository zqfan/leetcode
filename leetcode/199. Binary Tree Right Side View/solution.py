# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        right_values = []
        parents = [root]
        children = []
        while parents:
            right_values.append(parents[-1].val)
            for node in parents:
                if node.left:
                    children.append(node.left)
                if node.right:
                    children.append(node.right)
            parents, children = children, parents
            del children[:]
        return right_values
