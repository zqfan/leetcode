# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(node):
            if not node:
                return 0
            s = node.val + dfs(node.left) + dfs(node.right)
            counter[s] += 1
            return s

        counter = collections.defaultdict(int)
        dfs(root)
        max_cnt = max(counter.itervalues()) if counter else 0
        return [k for k, v in counter.iteritems() if v == max_cnt]
