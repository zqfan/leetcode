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
        def dfs(node, height):
            if node:
                if height > len(levelsum):
                    levelsum.append([0.0, 0.0])
                levelsum[height-1][0] += node.val
                levelsum[height-1][1] += 1
                dfs(node.left, height + 1)
                dfs(node.right, height + 1)
        levelsum = []
        dfs(root, 1)
        return [val / count for val, count in levelsum]

# 63 / 63 test cases passed.
# Status: Accepted
# Runtime: 105 ms
