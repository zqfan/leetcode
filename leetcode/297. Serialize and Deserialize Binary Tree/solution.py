# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        def helper(root, res):
            if not root:
                res.append('')
                return
            res.append(str(root.val))
            helper(root.left, res)
            helper(root.right, res)

        res = []
        helper(root, res)
        while res and res[-1] == '':
            res.pop()
        return ','.join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        def helper(idx):
            if idx >= len(strnodes) or strnodes[idx] == '':
                return None, idx
            root = TreeNode(int(strnodes[idx]))
            root.left, idx = helper(idx+1)
            root.right, idx = helper(idx+1)
            return root, idx

        strnodes = data.split(',')
        return helper(0)[0]
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

# 47 / 47 test cases passed.
# Status: Accepted
# Runtime: 189 ms
# 88.19%
