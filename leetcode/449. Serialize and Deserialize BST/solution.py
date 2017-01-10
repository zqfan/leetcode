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
        # @StefanPochmann
        def encode(cur):
            if cur:
                nums.append(str(cur.val))
                encode(cur.left)
                encode(cur.right)
        nums = []
        encode(root)
        return ' '.join(nums)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        preorder = map(int, data.split())
        inorder = sorted(preorder)
        preorder.reverse()
        inorder.reverse()
        def build(stop):
            if inorder and inorder[-1] != stop:
                root = TreeNode(preorder.pop())
                root.left = build(root.val)
                inorder.pop()
                root.right = build(stop)
                return root
        return build(None)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

# 62 / 62 test cases passed.
# Status: Accepted
# Runtime: 158 ms
# 48.00%
