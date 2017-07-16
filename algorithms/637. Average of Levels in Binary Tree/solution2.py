# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        q = collections.deque([root])
        result = []
        while q:
            val, n = 0, len(q)
            for i in xrange(n):
                node = q.popleft()
                val += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            result.append(val / float(n))
        return result

# 63 / 63 test cases passed.
# Status: Accepted
# Runtime: 75 ms
