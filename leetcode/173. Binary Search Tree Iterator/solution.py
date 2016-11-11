# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.path = []
        cur = root
        while cur:
            self.path.append(cur)
            cur = cur.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.path

    def next(self):
        """
        :rtype: int
        """
        node = self.path.pop()
        cur = node.right
        while cur:
            self.path.append(cur)
            cur = cur.left
        return node.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
