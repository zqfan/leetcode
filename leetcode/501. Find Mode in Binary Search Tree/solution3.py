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
        def dfs(root):
            if not root:
                return
            counter[root.val] += 1
            dfs(root.left)
            dfs(root.right)
        counter = collections.defaultdict(int)
        dfs(root)
        maximal = max(counter.itervalues()) if counter else 0
        return filter(lambda k: counter[k] == maximal, counter.iterkeys())
