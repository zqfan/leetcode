# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        q, s = collections.deque([root]), set()
        while q:
            p = q.popleft()
            s.add(p.val)
            if p.left:
                q.append(p.left)
            if p.right:
                q.append(p.right)
        s.remove(min(s))
        return min(s) if s else -1

# 34 / 34 test cases passed.
# Status: Accepted
# Runtime: 42 ms
